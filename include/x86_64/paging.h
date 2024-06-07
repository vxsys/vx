/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _INCLUDE_X86_64_PAGING_H
#define _INCLUDE_X86_64_PAGING_H
#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/vprot.h>

#define X86_PML_ADDRESS 0x000FFFFFFFFFF000
#define X86_PML_PRESENT 0x0000000000000001
#define X86_PML_WRITE   0x0000000000000002
#define X86_PML_USER    0x0000000000000004
#define X86_PML_NOEXEC  0x8000000000000000

#define PMENTRY_LVL1_MASK UINT64_C(0x1FF)
#define PMENTRY_LVL2_MASK UINT64_C(0x1FF)
#define PMENTRY_LVL3_MASK UINT64_C(0x1FF)
#define PMENTRY_LVL4_MASK UINT64_C(0x1FF)
#define PMENTRY_LVL5_MASK UINT64_C(0x1FF)

#define PMENTRY_LVL1_SHIFT UINT64_C(12)
#define PMENTRY_LVL2_SHIFT UINT64_C(21)
#define PMENTRY_LVL3_SHIFT UINT64_C(30)
#define PMENTRY_LVL4_SHIFT UINT64_C(39)
#define PMENTRY_LVL5_SHIFT UINT64_C(48)

#define PMENTRY_LVL3 1
#define PMENTRY_LVL4 1
#define PMENTRY_LVL5 0

#define PMENTRY_NULL UINT64_C(0x0000000000000000)

#define PAGEMAP_SIZE 0x200
#define PAGEMAP_KERN 0x100
#define PAGEMAP_USER 0x000

typedef uint64_t pmentry_t;

static __always_inline __nodiscard inline int pmentry_valid(pmentry_t entry)
{
    return (int)(entry & X86_PML_PRESENT);
}

static __always_inline __nodiscard inline uintptr_t pmentry_address(pmentry_t entry)
{
    return (uintptr_t)(entry & X86_PML_ADDRESS);
}

static __always_inline __nodiscard inline pmentry_t make_pmentry(uintptr_t address, unsigned vprot)
{
    pmentry_t entry = PMENTRY_NULL;

    entry |= X86_PML_ADDRESS & address;
    entry |= X86_PML_PRESENT;
    entry |= X86_PML_NOEXEC;

    if(vprot & VPROT_WRITE) entry |= X86_PML_WRITE;
    if(vprot & VPROT_USER)  entry |= X86_PML_USER;
    if(vprot & VPROT_EXEC)  entry &= ~X86_PML_NOEXEC;

    return entry;
}

#endif /* _INCLUDE_X86_64_PAGING_H */