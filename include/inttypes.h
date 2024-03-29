/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (c) 2024, VX/sys Contributors */
#ifndef INCLUDE_INTTYPES_H
#define INCLUDE_INTTYPES_H
#include <stdint.h>
#include <sys/cdefs.h>

intmax_t strtoimax(const char *restrict nptr, const char **restrict endptr, int base);
uintmax_t strtoumax(const char *restrict nptr, const char **restrict endptr, int base);

#endif /* INCLUDE_INTTYPES_H */
