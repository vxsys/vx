/* SPDX-License-Identifier: BSD-2-Clause */
/* Copyright (c) 2023, KanOS Contributors */
#ifndef __SYS_INTERRUPT_H__
#define __SYS_INTERRUPT_H__
#include <machine/cpu.h>
#include <machine/limits.h>
#include <sys/cdefs.h>

/* How many functions can pretend to consume
 * an interrupt signal, if there happens to be one */
#define MAX_INTERRUPT_HANDLERS 4

/* Returned by alloc_interrupt when it fails */
#define INVALID_INTERRUPT_VECTOR ((long)(-1))

/* Returns nonzero to notify the interrupt system
 * that the interrupt signal has been consumed */
typedef int (*interrupt_handler_t)(cpu_ctx_t *restrict ctx, void *restrict arg);

long allocate_interrupt(long desired_vector);
int add_interrupt_handler(long vector, interrupt_handler_t handler, void *restrict arg);
int trigger_interrupt(long vector, cpu_ctx_t *restrict ctx);

#endif /* __SYS_INTERRUPT_H__ */
