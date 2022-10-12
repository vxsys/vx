/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright (c), 2022, Kaneru Contributors */
#include <kaneru/init.h>
#include <kaneru/kprintf.h>
#include <kaneru/pmio.h>
#include <kaneru/uart.h>
#include <string.h>

#define PC_UART_TEST 0xAE
#define PC_UART_CLOCK 115200
#define PC_UART1_BASE 0x3F8
#define PC_UART2_BASE 0x2F8

#define from_arg(ptr) ((pmio_addr_t)((uintptr_t)(ptr)))
#define to_arg(value) ((void *)((uintptr_t)(value)))

static size_t uart_kprintf_callback(const void *s, size_t n, void *arg)
{
    size_t i;
    const pmio_uint8_t *sp = s;
    pmio_addr_t base = from_arg(arg);
    for(i = 0; i < n; i++) {
        while((pmio_read8(base + UART_LSR) & UART_LSR_ETHR) != UART_LSR_ETHR);
        pmio_write8(base + UART_THR, sp[i]);
    }

    return n;
}

static int uart_init(pmio_addr_t base, unsigned int speed)
{
    pmio_uint16_t d;

    pmio_write8(base + UART_SCR, PC_UART_TEST);
    if(pmio_read8(base + UART_SCR) != PC_UART_TEST) {
        pr_inform("kprintf_early: UART at %03X is not present", base);
        return 0;
    }

    pmio_write8(base + UART_IER, 0);

    d = speed ? (PC_UART_CLOCK / speed) : 1;
    pmio_write8(base + UART_LCR, UART_LCR_DLB);
    pmio_write8(base + UART_DLL, (d & 0x00FF));
    pmio_write8(base + UART_DLH, (d & 0xFF00) >> 8);

    /* 8-bit words, 1 stop bit, no parity, FIFO with girthiest threshold */
    pmio_write8(base + UART_LCR, UART_LCR_LEN_8 | UART_LCR_1SB | UART_LCR_PAR_NIL);
    pmio_write8(base + UART_FCR, UART_FCR_FEN | UART_FCR_CRF | UART_FCR_CTF | UART_FCR_TRG_14_56);

    pmio_write8(base + UART_MCR, UART_MCR_RTS | UART_MCR_AO1 | UART_MCR_AO2 | UART_MCR_LBK);
    pmio_write8_throttle(base + UART_THR, PC_UART_TEST);
    if(pmio_read8_throttle(base + UART_RBR) != PC_UART_TEST) {
        pr_warn("kprintf_early: UART at %03X is faulty", base);
        return 0;
    }

    pmio_write8(base + UART_MCR, UART_MCR_DTR | UART_MCR_RTS | UART_MCR_AO1 | UART_MCR_AO2);

    return 1;
}

static void init_kprintf_early(void)
{
    static const pmio_addr_t bases[] = { PC_UART1_BASE, 0 };
    unsigned int speed = 9600, i;
    pmio_addr_t base = 0;

    for(i = 0; bases[i]; i++) {
        if(!uart_init(bases[i], speed))
            continue;
        base = bases[i];
        break;
    }

    if(base == 0) {
        pr_warn("kprintf_early: Initialization failed");
        return;
    }

    kprintf_set_callback(&uart_kprintf_callback, to_arg(base));

    pr_inform("kprintf_early: Initialized");
}
initcall_tier_0(kprintf_early, init_kprintf_early);