/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (c) 2024, VX/sys Contributors */
#include <string.h>

const char *strstr(const char *restrict s1, const char *restrict s2)
{
    const char *ap = s1;
    const char *bp;

    while(*s1) {
        bp = s2;

        while (*bp && (*ap == *bp)) {
            ++ap;
            ++bp;
        }

        if (!*bp)
            return s1;
        ap = ++s1;
    }

    return NULL;
}
