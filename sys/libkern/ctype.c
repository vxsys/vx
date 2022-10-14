/* SPDX-License-Identifier: BSD-2-Clause */
/* Copyright (c), 2022, Kaneru Contributors */
#include <ctype.h>

const struct ctype _ctype[CTYPE_SIZE] = {
    /* EOF  */  { .lower = 0xFF, .upper = 0xFF, .flags = _CT_NULL },
    /* NUL  */  { .lower = 0x00, .upper = 0x00, .flags = _CT_CTRL },
    /* SOH  */  { .lower = 0x01, .upper = 0x01, .flags = _CT_CTRL },
    /* STX  */  { .lower = 0x02, .upper = 0x02, .flags = _CT_CTRL },
    /* ETX  */  { .lower = 0x03, .upper = 0x03, .flags = _CT_CTRL },
    /* EOT  */  { .lower = 0x04, .upper = 0x04, .flags = _CT_CTRL },
    /* ENQ  */  { .lower = 0x05, .upper = 0x05, .flags = _CT_CTRL },
    /* ACK  */  { .lower = 0x06, .upper = 0x06, .flags = _CT_CTRL },
    /* BEL  */  { .lower = 0x07, .upper = 0x07, .flags = _CT_CTRL },
    /* BS   */  { .lower = 0x08, .upper = 0x08, .flags = _CT_CTRL },
    /* HT   */  { .lower = 0x09, .upper = 0x09, .flags = _CT_CTRL | _CT_SPCE | _CT_BLNK },
    /* LF   */  { .lower = 0x0A, .upper = 0x0A, .flags = _CT_CTRL | _CT_SPCE },
    /* VT   */  { .lower = 0x0B, .upper = 0x0B, .flags = _CT_CTRL | _CT_SPCE },
    /* FF   */  { .lower = 0x0C, .upper = 0x0C, .flags = _CT_CTRL | _CT_SPCE },
    /* CR   */  { .lower = 0x0D, .upper = 0x0D, .flags = _CT_CTRL | _CT_SPCE },
    /* SO   */  { .lower = 0x0E, .upper = 0x0E, .flags = _CT_CTRL },
    /* SI   */  { .lower = 0x0F, .upper = 0x0F, .flags = _CT_CTRL },
    /* DLE  */  { .lower = 0x10, .upper = 0x10, .flags = _CT_CTRL },
    /* DC1  */  { .lower = 0x11, .upper = 0x11, .flags = _CT_CTRL },
    /* DC2  */  { .lower = 0x12, .upper = 0x12, .flags = _CT_CTRL },
    /* DC3  */  { .lower = 0x13, .upper = 0x13, .flags = _CT_CTRL },
    /* DC4  */  { .lower = 0x14, .upper = 0x14, .flags = _CT_CTRL },
    /* NAK  */  { .lower = 0x15, .upper = 0x15, .flags = _CT_CTRL },
    /* SYN  */  { .lower = 0x16, .upper = 0x16, .flags = _CT_CTRL },
    /* ETB  */  { .lower = 0x17, .upper = 0x17, .flags = _CT_CTRL },
    /* CAN  */  { .lower = 0x18, .upper = 0x18, .flags = _CT_CTRL },
    /* EM   */  { .lower = 0x19, .upper = 0x19, .flags = _CT_CTRL },
    /* SUB  */  { .lower = 0x1A, .upper = 0x1A, .flags = _CT_CTRL },
    /* ESC  */  { .lower = 0x1B, .upper = 0x1B, .flags = _CT_CTRL },
    /* FS   */  { .lower = 0x1C, .upper = 0x1C, .flags = _CT_CTRL },
    /* GS   */  { .lower = 0x1D, .upper = 0x1D, .flags = _CT_CTRL },
    /* RS   */  { .lower = 0x1E, .upper = 0x1E, .flags = _CT_CTRL },
    /* US   */  { .lower = 0x1F, .upper = 0x1F, .flags = _CT_CTRL },
    /* SP   */  { .lower = 0x20, .upper = 0x20, .flags = _CT_SPCE | _CT_BLNK },
    /* !    */  { .lower = 0x21, .upper = 0x21, .flags = _CT_GRPH | _CT_PNCT },
    /* "    */  { .lower = 0x22, .upper = 0x22, .flags = _CT_GRPH | _CT_PNCT },
    /* #    */  { .lower = 0x23, .upper = 0x23, .flags = _CT_GRPH | _CT_PNCT },
    /* $    */  { .lower = 0x24, .upper = 0x24, .flags = _CT_GRPH | _CT_PNCT },
    /* %    */  { .lower = 0x25, .upper = 0x25, .flags = _CT_GRPH | _CT_PNCT },
    /* &    */  { .lower = 0x26, .upper = 0x26, .flags = _CT_GRPH | _CT_PNCT },
    /* '    */  { .lower = 0x27, .upper = 0x27, .flags = _CT_GRPH | _CT_PNCT },
    /* (    */  { .lower = 0x28, .upper = 0x28, .flags = _CT_GRPH | _CT_PNCT },
    /* )    */  { .lower = 0x29, .upper = 0x29, .flags = _CT_GRPH | _CT_PNCT },
    /* *    */  { .lower = 0x2A, .upper = 0x2A, .flags = _CT_GRPH | _CT_PNCT },
    /* +    */  { .lower = 0x2B, .upper = 0x2B, .flags = _CT_GRPH | _CT_PNCT },
    /* ,    */  { .lower = 0x2C, .upper = 0x2C, .flags = _CT_GRPH | _CT_PNCT },
    /* -    */  { .lower = 0x2D, .upper = 0x2D, .flags = _CT_GRPH | _CT_PNCT },
    /* .    */  { .lower = 0x2E, .upper = 0x2E, .flags = _CT_GRPH | _CT_PNCT },
    /* /    */  { .lower = 0x2F, .upper = 0x2F, .flags = _CT_GRPH | _CT_PNCT },
    /* 0    */  { .lower = 0x30, .upper = 0x30, .flags = _CT_GRPH | _CT_DECD | _CT_HEXD },
    /* 1    */  { .lower = 0x31, .upper = 0x31, .flags = _CT_GRPH | _CT_DECD | _CT_HEXD },
    /* 2    */  { .lower = 0x32, .upper = 0x32, .flags = _CT_GRPH | _CT_DECD | _CT_HEXD },
    /* 3    */  { .lower = 0x33, .upper = 0x33, .flags = _CT_GRPH | _CT_DECD | _CT_HEXD },
    /* 4    */  { .lower = 0x34, .upper = 0x34, .flags = _CT_GRPH | _CT_DECD | _CT_HEXD },
    /* 5    */  { .lower = 0x35, .upper = 0x35, .flags = _CT_GRPH | _CT_DECD | _CT_HEXD },
    /* 6    */  { .lower = 0x36, .upper = 0x36, .flags = _CT_GRPH | _CT_DECD | _CT_HEXD },
    /* 7    */  { .lower = 0x37, .upper = 0x37, .flags = _CT_GRPH | _CT_DECD | _CT_HEXD },
    /* 8    */  { .lower = 0x38, .upper = 0x38, .flags = _CT_GRPH | _CT_DECD | _CT_HEXD },
    /* 9    */  { .lower = 0x39, .upper = 0x39, .flags = _CT_GRPH | _CT_DECD | _CT_HEXD },
    /* :    */  { .lower = 0x3A, .upper = 0x3A, .flags = _CT_GRPH | _CT_PNCT },
    /* ;    */  { .lower = 0x3B, .upper = 0x3B, .flags = _CT_GRPH | _CT_PNCT },
    /* <    */  { .lower = 0x3C, .upper = 0x3C, .flags = _CT_GRPH | _CT_PNCT },
    /* =    */  { .lower = 0x3D, .upper = 0x3D, .flags = _CT_GRPH | _CT_PNCT },
    /* >    */  { .lower = 0x3E, .upper = 0x3E, .flags = _CT_GRPH | _CT_PNCT },
    /* ?    */  { .lower = 0x3F, .upper = 0x3F, .flags = _CT_GRPH | _CT_PNCT },
    /* @    */  { .lower = 0x40, .upper = 0x40, .flags = _CT_GRPH | _CT_PNCT },
    /* A    */  { .lower = 0x61, .upper = 0x41, .flags = _CT_GRPH | _CT_UPRC | _CT_HEXD },
    /* B    */  { .lower = 0x62, .upper = 0x42, .flags = _CT_GRPH | _CT_UPRC | _CT_HEXD },
    /* C    */  { .lower = 0x63, .upper = 0x43, .flags = _CT_GRPH | _CT_UPRC | _CT_HEXD },
    /* D    */  { .lower = 0x64, .upper = 0x44, .flags = _CT_GRPH | _CT_UPRC | _CT_HEXD },
    /* E    */  { .lower = 0x65, .upper = 0x45, .flags = _CT_GRPH | _CT_UPRC | _CT_HEXD },
    /* F    */  { .lower = 0x66, .upper = 0x46, .flags = _CT_GRPH | _CT_UPRC | _CT_HEXD },
    /* G    */  { .lower = 0x67, .upper = 0x47, .flags = _CT_GRPH | _CT_UPRC },
    /* H    */  { .lower = 0x68, .upper = 0x48, .flags = _CT_GRPH | _CT_UPRC },
    /* I    */  { .lower = 0x69, .upper = 0x49, .flags = _CT_GRPH | _CT_UPRC },
    /* J    */  { .lower = 0x6A, .upper = 0x4A, .flags = _CT_GRPH | _CT_UPRC },
    /* K    */  { .lower = 0x6B, .upper = 0x4B, .flags = _CT_GRPH | _CT_UPRC },
    /* L    */  { .lower = 0x6C, .upper = 0x4C, .flags = _CT_GRPH | _CT_UPRC },
    /* M    */  { .lower = 0x6D, .upper = 0x4D, .flags = _CT_GRPH | _CT_UPRC },
    /* N    */  { .lower = 0x6E, .upper = 0x4E, .flags = _CT_GRPH | _CT_UPRC },
    /* O    */  { .lower = 0x6F, .upper = 0x4F, .flags = _CT_GRPH | _CT_UPRC },
    /* P    */  { .lower = 0x70, .upper = 0x50, .flags = _CT_GRPH | _CT_UPRC },
    /* Q    */  { .lower = 0x71, .upper = 0x51, .flags = _CT_GRPH | _CT_UPRC },
    /* R    */  { .lower = 0x72, .upper = 0x52, .flags = _CT_GRPH | _CT_UPRC },
    /* S    */  { .lower = 0x73, .upper = 0x53, .flags = _CT_GRPH | _CT_UPRC },
    /* T    */  { .lower = 0x74, .upper = 0x54, .flags = _CT_GRPH | _CT_UPRC },
    /* U    */  { .lower = 0x75, .upper = 0x55, .flags = _CT_GRPH | _CT_UPRC },
    /* V    */  { .lower = 0x76, .upper = 0x56, .flags = _CT_GRPH | _CT_UPRC },
    /* W    */  { .lower = 0x77, .upper = 0x57, .flags = _CT_GRPH | _CT_UPRC },
    /* X    */  { .lower = 0x78, .upper = 0x58, .flags = _CT_GRPH | _CT_UPRC },
    /* Y    */  { .lower = 0x79, .upper = 0x59, .flags = _CT_GRPH | _CT_UPRC },
    /* Z    */  { .lower = 0x7A, .upper = 0x5A, .flags = _CT_GRPH | _CT_UPRC },
    /* [    */  { .lower = 0x5B, .upper = 0x5B, .flags = _CT_GRPH | _CT_PNCT },
    /* \    */  { .lower = 0x5C, .upper = 0x5C, .flags = _CT_GRPH | _CT_PNCT },
    /* ]    */  { .lower = 0x5D, .upper = 0x5D, .flags = _CT_GRPH | _CT_PNCT },
    /* ^    */  { .lower = 0x5E, .upper = 0x5E, .flags = _CT_GRPH | _CT_PNCT },
    /* _    */  { .lower = 0x5F, .upper = 0x5F, .flags = _CT_GRPH | _CT_PNCT },
    /* `    */  { .lower = 0x60, .upper = 0x60, .flags = _CT_GRPH | _CT_PNCT },
    /* a    */  { .lower = 0x61, .upper = 0x41, .flags = _CT_GRPH | _CT_LWRC | _CT_HEXD },
    /* b    */  { .lower = 0x62, .upper = 0x42, .flags = _CT_GRPH | _CT_LWRC | _CT_HEXD },
    /* c    */  { .lower = 0x63, .upper = 0x43, .flags = _CT_GRPH | _CT_LWRC | _CT_HEXD },
    /* d    */  { .lower = 0x64, .upper = 0x44, .flags = _CT_GRPH | _CT_LWRC | _CT_HEXD },
    /* e    */  { .lower = 0x65, .upper = 0x45, .flags = _CT_GRPH | _CT_LWRC | _CT_HEXD },
    /* f    */  { .lower = 0x66, .upper = 0x46, .flags = _CT_GRPH | _CT_LWRC | _CT_HEXD },
    /* g    */  { .lower = 0x67, .upper = 0x47, .flags = _CT_GRPH | _CT_LWRC },
    /* h    */  { .lower = 0x68, .upper = 0x48, .flags = _CT_GRPH | _CT_LWRC },
    /* i    */  { .lower = 0x69, .upper = 0x49, .flags = _CT_GRPH | _CT_LWRC },
    /* j    */  { .lower = 0x6A, .upper = 0x4A, .flags = _CT_GRPH | _CT_LWRC },
    /* k    */  { .lower = 0x6B, .upper = 0x4B, .flags = _CT_GRPH | _CT_LWRC },
    /* l    */  { .lower = 0x6C, .upper = 0x4C, .flags = _CT_GRPH | _CT_LWRC },
    /* m    */  { .lower = 0x6D, .upper = 0x4D, .flags = _CT_GRPH | _CT_LWRC },
    /* n    */  { .lower = 0x6E, .upper = 0x4E, .flags = _CT_GRPH | _CT_LWRC },
    /* o    */  { .lower = 0x6F, .upper = 0x4F, .flags = _CT_GRPH | _CT_LWRC },
    /* p    */  { .lower = 0x70, .upper = 0x50, .flags = _CT_GRPH | _CT_LWRC },
    /* q    */  { .lower = 0x71, .upper = 0x51, .flags = _CT_GRPH | _CT_LWRC },
    /* r    */  { .lower = 0x72, .upper = 0x52, .flags = _CT_GRPH | _CT_LWRC },
    /* s    */  { .lower = 0x73, .upper = 0x53, .flags = _CT_GRPH | _CT_LWRC },
    /* t    */  { .lower = 0x74, .upper = 0x54, .flags = _CT_GRPH | _CT_LWRC },
    /* u    */  { .lower = 0x75, .upper = 0x55, .flags = _CT_GRPH | _CT_LWRC },
    /* v    */  { .lower = 0x76, .upper = 0x56, .flags = _CT_GRPH | _CT_LWRC },
    /* w    */  { .lower = 0x77, .upper = 0x57, .flags = _CT_GRPH | _CT_LWRC },
    /* x    */  { .lower = 0x78, .upper = 0x58, .flags = _CT_GRPH | _CT_LWRC },
    /* y    */  { .lower = 0x79, .upper = 0x59, .flags = _CT_GRPH | _CT_LWRC },
    /* z    */  { .lower = 0x7A, .upper = 0x5A, .flags = _CT_GRPH | _CT_LWRC },
    /* {    */  { .lower = 0x7B, .upper = 0x7B, .flags = _CT_GRPH | _CT_PNCT },
    /* |    */  { .lower = 0x7C, .upper = 0x7C, .flags = _CT_GRPH | _CT_PNCT },
    /* }    */  { .lower = 0x7D, .upper = 0x7D, .flags = _CT_GRPH | _CT_PNCT },
    /* ~    */  { .lower = 0x7E, .upper = 0x7E, .flags = _CT_GRPH | _CT_PNCT },
    /* DEL  */  { .lower = 0x7F, .upper = 0x7F, .flags = _CT_CTRL },
    /*      */  { .lower = 0x80, .upper = 0x80, .flags = _CT_NULL },
    /*      */  { .lower = 0x81, .upper = 0x81, .flags = _CT_NULL },
    /*      */  { .lower = 0x82, .upper = 0x82, .flags = _CT_NULL },
    /*      */  { .lower = 0x83, .upper = 0x83, .flags = _CT_NULL },
    /*      */  { .lower = 0x84, .upper = 0x84, .flags = _CT_NULL },
    /*      */  { .lower = 0x85, .upper = 0x85, .flags = _CT_NULL },
    /*      */  { .lower = 0x86, .upper = 0x86, .flags = _CT_NULL },
    /*      */  { .lower = 0x87, .upper = 0x87, .flags = _CT_NULL },
    /*      */  { .lower = 0x88, .upper = 0x88, .flags = _CT_NULL },
    /*      */  { .lower = 0x89, .upper = 0x89, .flags = _CT_NULL },
    /*      */  { .lower = 0x8A, .upper = 0x8A, .flags = _CT_NULL },
    /*      */  { .lower = 0x8B, .upper = 0x8B, .flags = _CT_NULL },
    /*      */  { .lower = 0x8C, .upper = 0x8C, .flags = _CT_NULL },
    /*      */  { .lower = 0x8D, .upper = 0x8D, .flags = _CT_NULL },
    /*      */  { .lower = 0x8E, .upper = 0x8E, .flags = _CT_NULL },
    /*      */  { .lower = 0x8F, .upper = 0x8F, .flags = _CT_NULL },
    /*      */  { .lower = 0x90, .upper = 0x90, .flags = _CT_NULL },
    /*      */  { .lower = 0x91, .upper = 0x91, .flags = _CT_NULL },
    /*      */  { .lower = 0x92, .upper = 0x92, .flags = _CT_NULL },
    /*      */  { .lower = 0x93, .upper = 0x93, .flags = _CT_NULL },
    /*      */  { .lower = 0x94, .upper = 0x94, .flags = _CT_NULL },
    /*      */  { .lower = 0x95, .upper = 0x95, .flags = _CT_NULL },
    /*      */  { .lower = 0x96, .upper = 0x96, .flags = _CT_NULL },
    /*      */  { .lower = 0x97, .upper = 0x97, .flags = _CT_NULL },
    /*      */  { .lower = 0x98, .upper = 0x98, .flags = _CT_NULL },
    /*      */  { .lower = 0x99, .upper = 0x99, .flags = _CT_NULL },
    /*      */  { .lower = 0x9A, .upper = 0x9A, .flags = _CT_NULL },
    /*      */  { .lower = 0x9B, .upper = 0x9B, .flags = _CT_NULL },
    /*      */  { .lower = 0x9C, .upper = 0x9C, .flags = _CT_NULL },
    /*      */  { .lower = 0x9D, .upper = 0x9D, .flags = _CT_NULL },
    /*      */  { .lower = 0x9E, .upper = 0x9E, .flags = _CT_NULL },
    /*      */  { .lower = 0x9F, .upper = 0x9F, .flags = _CT_NULL },
    /*      */  { .lower = 0xA0, .upper = 0xA0, .flags = _CT_NULL },
    /*      */  { .lower = 0xA1, .upper = 0xA1, .flags = _CT_NULL },
    /*      */  { .lower = 0xA2, .upper = 0xA2, .flags = _CT_NULL },
    /*      */  { .lower = 0xA3, .upper = 0xA3, .flags = _CT_NULL },
    /*      */  { .lower = 0xA4, .upper = 0xA4, .flags = _CT_NULL },
    /*      */  { .lower = 0xA5, .upper = 0xA5, .flags = _CT_NULL },
    /*      */  { .lower = 0xA6, .upper = 0xA6, .flags = _CT_NULL },
    /*      */  { .lower = 0xA7, .upper = 0xA7, .flags = _CT_NULL },
    /*      */  { .lower = 0xA8, .upper = 0xA8, .flags = _CT_NULL },
    /*      */  { .lower = 0xA9, .upper = 0xA9, .flags = _CT_NULL },
    /*      */  { .lower = 0xAA, .upper = 0xAA, .flags = _CT_NULL },
    /*      */  { .lower = 0xAB, .upper = 0xAB, .flags = _CT_NULL },
    /*      */  { .lower = 0xAC, .upper = 0xAC, .flags = _CT_NULL },
    /*      */  { .lower = 0xAD, .upper = 0xAD, .flags = _CT_NULL },
    /*      */  { .lower = 0xAE, .upper = 0xAE, .flags = _CT_NULL },
    /*      */  { .lower = 0xAF, .upper = 0xAF, .flags = _CT_NULL },
    /*      */  { .lower = 0xB0, .upper = 0xB0, .flags = _CT_NULL },
    /*      */  { .lower = 0xB1, .upper = 0xB1, .flags = _CT_NULL },
    /*      */  { .lower = 0xB2, .upper = 0xB2, .flags = _CT_NULL },
    /*      */  { .lower = 0xB3, .upper = 0xB3, .flags = _CT_NULL },
    /*      */  { .lower = 0xB4, .upper = 0xB4, .flags = _CT_NULL },
    /*      */  { .lower = 0xB5, .upper = 0xB5, .flags = _CT_NULL },
    /*      */  { .lower = 0xB6, .upper = 0xB6, .flags = _CT_NULL },
    /*      */  { .lower = 0xB7, .upper = 0xB7, .flags = _CT_NULL },
    /*      */  { .lower = 0xB8, .upper = 0xB8, .flags = _CT_NULL },
    /*      */  { .lower = 0xB9, .upper = 0xB9, .flags = _CT_NULL },
    /*      */  { .lower = 0xBA, .upper = 0xBA, .flags = _CT_NULL },
    /*      */  { .lower = 0xBB, .upper = 0xBB, .flags = _CT_NULL },
    /*      */  { .lower = 0xBC, .upper = 0xBC, .flags = _CT_NULL },
    /*      */  { .lower = 0xBD, .upper = 0xBD, .flags = _CT_NULL },
    /*      */  { .lower = 0xBE, .upper = 0xBE, .flags = _CT_NULL },
    /*      */  { .lower = 0xBF, .upper = 0xBF, .flags = _CT_NULL },
    /*      */  { .lower = 0xC0, .upper = 0xC0, .flags = _CT_NULL },
    /*      */  { .lower = 0xC1, .upper = 0xC1, .flags = _CT_NULL },
    /*      */  { .lower = 0xC2, .upper = 0xC2, .flags = _CT_NULL },
    /*      */  { .lower = 0xC3, .upper = 0xC3, .flags = _CT_NULL },
    /*      */  { .lower = 0xC4, .upper = 0xC4, .flags = _CT_NULL },
    /*      */  { .lower = 0xC5, .upper = 0xC5, .flags = _CT_NULL },
    /*      */  { .lower = 0xC6, .upper = 0xC6, .flags = _CT_NULL },
    /*      */  { .lower = 0xC7, .upper = 0xC7, .flags = _CT_NULL },
    /*      */  { .lower = 0xC8, .upper = 0xC8, .flags = _CT_NULL },
    /*      */  { .lower = 0xC9, .upper = 0xC9, .flags = _CT_NULL },
    /*      */  { .lower = 0xCA, .upper = 0xCA, .flags = _CT_NULL },
    /*      */  { .lower = 0xCB, .upper = 0xCB, .flags = _CT_NULL },
    /*      */  { .lower = 0xCC, .upper = 0xCC, .flags = _CT_NULL },
    /*      */  { .lower = 0xCD, .upper = 0xCD, .flags = _CT_NULL },
    /*      */  { .lower = 0xCE, .upper = 0xCE, .flags = _CT_NULL },
    /*      */  { .lower = 0xCF, .upper = 0xCF, .flags = _CT_NULL },
    /*      */  { .lower = 0xD0, .upper = 0xD0, .flags = _CT_NULL },
    /*      */  { .lower = 0xD1, .upper = 0xD1, .flags = _CT_NULL },
    /*      */  { .lower = 0xD2, .upper = 0xD2, .flags = _CT_NULL },
    /*      */  { .lower = 0xD3, .upper = 0xD3, .flags = _CT_NULL },
    /*      */  { .lower = 0xD4, .upper = 0xD4, .flags = _CT_NULL },
    /*      */  { .lower = 0xD5, .upper = 0xD5, .flags = _CT_NULL },
    /*      */  { .lower = 0xD6, .upper = 0xD6, .flags = _CT_NULL },
    /*      */  { .lower = 0xD7, .upper = 0xD7, .flags = _CT_NULL },
    /*      */  { .lower = 0xD8, .upper = 0xD8, .flags = _CT_NULL },
    /*      */  { .lower = 0xD9, .upper = 0xD9, .flags = _CT_NULL },
    /*      */  { .lower = 0xDA, .upper = 0xDA, .flags = _CT_NULL },
    /*      */  { .lower = 0xDB, .upper = 0xDB, .flags = _CT_NULL },
    /*      */  { .lower = 0xDC, .upper = 0xDC, .flags = _CT_NULL },
    /*      */  { .lower = 0xDD, .upper = 0xDD, .flags = _CT_NULL },
    /*      */  { .lower = 0xDE, .upper = 0xDE, .flags = _CT_NULL },
    /*      */  { .lower = 0xDF, .upper = 0xDF, .flags = _CT_NULL },
    /*      */  { .lower = 0xE0, .upper = 0xE0, .flags = _CT_NULL },
    /*      */  { .lower = 0xE1, .upper = 0xE1, .flags = _CT_NULL },
    /*      */  { .lower = 0xE2, .upper = 0xE2, .flags = _CT_NULL },
    /*      */  { .lower = 0xE3, .upper = 0xE3, .flags = _CT_NULL },
    /*      */  { .lower = 0xE4, .upper = 0xE4, .flags = _CT_NULL },
    /*      */  { .lower = 0xE5, .upper = 0xE5, .flags = _CT_NULL },
    /*      */  { .lower = 0xE6, .upper = 0xE6, .flags = _CT_NULL },
    /*      */  { .lower = 0xE7, .upper = 0xE7, .flags = _CT_NULL },
    /*      */  { .lower = 0xE8, .upper = 0xE8, .flags = _CT_NULL },
    /*      */  { .lower = 0xE9, .upper = 0xE9, .flags = _CT_NULL },
    /*      */  { .lower = 0xEA, .upper = 0xEA, .flags = _CT_NULL },
    /*      */  { .lower = 0xEB, .upper = 0xEB, .flags = _CT_NULL },
    /*      */  { .lower = 0xEC, .upper = 0xEC, .flags = _CT_NULL },
    /*      */  { .lower = 0xED, .upper = 0xED, .flags = _CT_NULL },
    /*      */  { .lower = 0xEE, .upper = 0xEE, .flags = _CT_NULL },
    /*      */  { .lower = 0xEF, .upper = 0xEF, .flags = _CT_NULL },
    /*      */  { .lower = 0xF0, .upper = 0xF0, .flags = _CT_NULL },
    /*      */  { .lower = 0xF1, .upper = 0xF1, .flags = _CT_NULL },
    /*      */  { .lower = 0xF2, .upper = 0xF2, .flags = _CT_NULL },
    /*      */  { .lower = 0xF3, .upper = 0xF3, .flags = _CT_NULL },
    /*      */  { .lower = 0xF4, .upper = 0xF4, .flags = _CT_NULL },
    /*      */  { .lower = 0xF5, .upper = 0xF5, .flags = _CT_NULL },
    /*      */  { .lower = 0xF6, .upper = 0xF6, .flags = _CT_NULL },
    /*      */  { .lower = 0xF7, .upper = 0xF7, .flags = _CT_NULL },
    /*      */  { .lower = 0xF8, .upper = 0xF8, .flags = _CT_NULL },
    /*      */  { .lower = 0xF9, .upper = 0xF9, .flags = _CT_NULL },
    /*      */  { .lower = 0xFA, .upper = 0xFA, .flags = _CT_NULL },
    /*      */  { .lower = 0xFB, .upper = 0xFB, .flags = _CT_NULL },
    /*      */  { .lower = 0xFC, .upper = 0xFC, .flags = _CT_NULL },
    /*      */  { .lower = 0xFD, .upper = 0xFD, .flags = _CT_NULL },
    /*      */  { .lower = 0xFE, .upper = 0xFE, .flags = _CT_NULL },
    /*      */  { .lower = 0xFF, .upper = 0xFF, .flags = _CT_NULL },
};
