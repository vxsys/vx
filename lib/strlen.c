/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (c) 2024, VX/sys Contributors */
#include <string.h>

size_t strlen(const char *restrict s)
{
    size_t i;
    for(i = 0; *s++; i++);
    return i;
}
