/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (c) 2024, VX/sys Contributors */
#include <string.h>

char *strcat(char *restrict s1, const char *restrict s2)
{
    char *save = s1;
    if(*s1)
        while(*++s1);
    while((*s1++ = *s2++));
    return save;
}
