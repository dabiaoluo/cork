/* Fat binary x86 gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 2000, 2001, 2002, 2003 Free Software Foundation,
Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA. */

#define BITS_PER_MP_LIMB 64 
#define BYTES_PER_MP_LIMB 8


/* mpn_divexact_1 is faster than mpn_divrem_1 at all sizes.  The only time
   this might not be true currently is for actual 80386 and 80486 chips,
   where mpn/x86/dive_1.asm might be slower than mpn/x86/divrem_1.asm, but
   that's not worth worrying about.  */
#define DIVEXACT_1_THRESHOLD  0

/* Only some of the x86s have an mpn_preinv_divrem_1, but we set
   USE_PREINV_DIVREM_1 so that all callers use it, and then let the
   __gmpn_cpuvec pointer go to plain mpn_divrem_1 if there's not an actual
   preinv.  */
#define USE_PREINV_DIVREM_1   1

/* mpn_sqr_basecase is faster than mpn_mul_basecase at all sizes, no need
   for mpn_sqr_n to call the latter.  */
#define SQR_BASECASE_THRESHOLD 0

/* Sensible fallbacks for these, when not taken from a cpu-specific
   gmp-mparam.h.  */
#define MUL_KARATSUBA_THRESHOLD   20
#define MUL_TOOM3_THRESHOLD      130
#define MUL_TOOM4_THRESHOLD      426
#define MUL_TOOM7_THRESHOLD      507
#define SQR_KARATSUBA_THRESHOLD   30
#define SQR_TOOM3_THRESHOLD      200
#define SQR_TOOM4_THRESHOLD      662
#define SQR_TOOM7_THRESHOLD     1300

/* These are values more or less in the middle of what the typical x86 chips
   come out as.  For a fat binary it's necessary to have values for these,
   since the defaults for MUL_FFT_TABLE and SQR_FFT_TABLE otherwise come out
   as non-constant array initializers.  FIXME: Perhaps these should be done
   in the cpuvec structure like other thresholds.  */
#define MUL_FFT_FULL_THRESHOLD              5888

#define SQR_FFT_FULL_THRESHOLD              4864
