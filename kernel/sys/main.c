/* SPDX-License-Identifier: BSD-2-Clause */
/* Copyright (c), 2022, Kaneru Contributors */
#include <kaneru/initcall.h>
#include <kaneru/klog.h>
#include <kaneru/panic.h>
#include <kaneru/version.h>
#include <stddef.h>
#include <limine.h>

static void kmain(void) __noreturn;
static volatile struct limine_entry_point_request __used boot_entry_point = {
    .id = LIMINE_ENTRY_POINT_REQUEST,
    .revision = 0,
    .response = NULL,
    .entry = (limine_entry_point)(&kmain),
};

static void __noreturn kmain(void)
{
    unsigned int i;

    /* print semver */
    klog(KL_INIT, "kernel version %s", K_SEMVER);

    /* initialize everything */
    for(i = 0; __initcalls[i]; __initcalls[i++]());

    /* nothing else to do now */
    panic("nothing to do");
}