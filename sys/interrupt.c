/* SPDX-License-Identifier: BSD-2-Clause */
/* Copyright (c), 2023, KanOS Contributors */
#include <kan/errno.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <sys/interrupt.h>

typedef struct interrupt_s {
    bool i_taken;
    void *i_args[MAX_INTERRUPT_HANDLERS];
    interrupt_handler_t i_handlers[MAX_INTERRUPT_HANDLERS];
} interrupt_t;

static interrupt_t interrupts[MAX_INTERRUPTS] = { 0 };

long allocate_interrupt(long desired_vector)
{
    long vector;

    if(desired_vector < 0 || desired_vector > MAX_INTERRUPTS) {
        // Any non-valid vector value is considered
        // a lack of preference in which vector to take
        desired_vector = 0;
    }

    for(vector = desired_vector; vector < MAX_INTERRUPTS; vector++) {
        if(!interrupts[vector].i_taken) {
            memset(&interrupts[vector], 0, sizeof(interrupt_t));
            interrupts[vector].i_taken = true;
            return vector;
        }
    }

    for(vector = 0; vector < desired_vector; vector++) {
        if(!interrupts[vector].i_taken) {
            memset(&interrupts[vector], 0, sizeof(interrupt_t));
            interrupts[vector].i_taken = true;
            return vector;
        }
    }

    return INVALID_INTERRUPT_VECTOR;
}

int add_interrupt_handler(long vector, interrupt_handler_t handler, void *restrict arg)
{
    size_t i;
    interrupt_t *interrupt;

    if(vector >= 0 && vector < MAX_INTERRUPTS) {
        interrupt = &interrupts[vector];

        if(interrupt->i_taken) {
            for(i = 0; i < MAX_INTERRUPT_HANDLERS; i++) {
                if(!interrupt->i_handlers[i]) {
                    interrupt->i_handlers[i] = handler;
                    interrupt->i_args[i] = arg;
                    return 0;
                }
            }

            return ENOMEM;
        }

        return EINVAL;
    }

    return ERANGE;
}

int trigger_interrupt(long vector, cpu_ctx_t *restrict ctx)
{
    size_t i;
    interrupt_t *interrupt;
    interrupt_handler_t handler;
    cpu_ctx_t stored_context;

    if(vector >= 0 && vector < MAX_INTERRUPTS) {
        interrupt = &interrupts[vector];

        if(interrupt->i_taken) {
            for(i = 0; i < MAX_INTERRUPT_HANDLERS; i++) {
                handler = interrupt->i_handlers[i];

                if(handler) {
                    memcpy(&stored_context, ctx, sizeof(cpu_ctx_t));

                    // Interrupt that returns TRUE is considered the one
                    // that consumed the signal, hence its changes to the
                    // FAKE CPU context are reflected on the REAL CPU context.
                    if(handler(&stored_context, interrupt->i_args[i])) {
                        memcpy(ctx, &stored_context, sizeof(cpu_ctx_t));
                        break;
                    }
                }
            }

            return 0;
        }

        return EINVAL;
    }

    return ERANGE;
}
