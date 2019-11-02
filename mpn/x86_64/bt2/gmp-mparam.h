/* AMD Jaguar gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 2019 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */

#define GMP_LIMB_BITS 64
#define GMP_LIMB_BYTES 8

/* Disable use of slow functions.  FIXME: We should disable lib inclusion.  */
#undef HAVE_NATIVE_mpn_mul_2
#undef HAVE_NATIVE_mpn_addmul_2

/* 2050 MHz AMD Jaguar/Kabini */
/* FFT tuning limit = 225,381,546 */
/* Generated by tuneup.c, 2019-10-18, gcc 8.3 */

#define MOD_1_NORM_THRESHOLD                 3
#define MOD_1_UNNORM_THRESHOLD               4
#define MOD_1N_TO_MOD_1_1_THRESHOLD          4
#define MOD_1U_TO_MOD_1_1_THRESHOLD          4
#define MOD_1_1_TO_MOD_1_2_THRESHOLD        65
#define MOD_1_2_TO_MOD_1_4_THRESHOLD         0  /* never mpn_mod_1s_2p */
#define PREINV_MOD_1_TO_MOD_1_THRESHOLD     10
#define USE_PREINV_DIVREM_1                  1  /* native */
#define DIV_QR_1_NORM_THRESHOLD              4
#define DIV_QR_1_UNNORM_THRESHOLD        MP_SIZE_T_MAX  /* never */
#define DIV_QR_2_PI2_THRESHOLD           MP_SIZE_T_MAX  /* never */
#define DIVEXACT_1_THRESHOLD                 0  /* always (native) */
#define BMOD_1_TO_MOD_1_THRESHOLD           15

#define DIV_1_VS_MUL_1_PERCENT             267

#define MUL_TOOM22_THRESHOLD                25
#define MUL_TOOM33_THRESHOLD                32
#define MUL_TOOM44_THRESHOLD                93
#define MUL_TOOM6H_THRESHOLD               366
#define MUL_TOOM8H_THRESHOLD               537

#define MUL_TOOM32_TO_TOOM43_THRESHOLD      63
#define MUL_TOOM32_TO_TOOM53_THRESHOLD     172
#define MUL_TOOM42_TO_TOOM53_THRESHOLD      63
#define MUL_TOOM42_TO_TOOM63_THRESHOLD      67
#define MUL_TOOM43_TO_TOOM54_THRESHOLD      91

#define SQR_BASECASE_THRESHOLD               0  /* always (native) */
#define SQR_TOOM2_THRESHOLD                 20
#define SQR_TOOM3_THRESHOLD                 97
#define SQR_TOOM4_THRESHOLD                220
#define SQR_TOOM6_THRESHOLD                318
#define SQR_TOOM8_THRESHOLD                434

#define MULMID_TOOM42_THRESHOLD             20

#define MULMOD_BNM1_THRESHOLD               11
#define SQRMOD_BNM1_THRESHOLD               13

#define MUL_FFT_MODF_THRESHOLD             348  /* k = 5 */
#define MUL_FFT_TABLE3                                      \
  { {    348, 5}, {     17, 6}, {      9, 5}, {     19, 6}, \
    {     23, 7}, {     21, 8}, {     11, 7}, {     24, 8}, \
    {     13, 7}, {     28, 8}, {     15, 7}, {     31, 8}, \
    {     17, 7}, {     35, 8}, {     19, 7}, {     39, 8}, \
    {     21, 9}, {     11, 8}, {     29, 9}, {     15, 8}, \
    {     35, 9}, {     19, 8}, {     41, 9}, {     23, 8}, \
    {     49, 9}, {     27,10}, {     15, 9}, {     39,10}, \
    {     23, 9}, {     55,11}, {     15,10}, {     31, 9}, \
    {     67,10}, {     39, 9}, {     79,10}, {     55,11}, \
    {     31,10}, {     63, 6}, {   1087, 8}, {    303, 9}, \
    {    159,10}, {     95,12}, {     31,11}, {     63,10}, \
    {    127, 9}, {    255,11}, {     79,10}, {    159, 9}, \
    {    319,10}, {    167,11}, {     95,10}, {    191, 9}, \
    {    383,10}, {    207, 9}, {    415,11}, {    111,12}, \
    {     63,11}, {    127,10}, {    255, 9}, {    511,10}, \
    {    271,11}, {    143,10}, {    287, 9}, {    575,10}, \
    {    303,11}, {    159,10}, {    319,12}, {     95,11}, \
    {    191,10}, {    383,11}, {    207,10}, {    415,11}, \
    {    223,13}, {     63,12}, {    127,11}, {    255,10}, \
    {    511,11}, {    271,10}, {    543,11}, {    287,10}, \
    {    575,11}, {    303,12}, {    159,11}, {    319,10}, \
    {    639,11}, {    351,12}, {    191,11}, {    415,12}, \
    {    223,11}, {    479,13}, {    127,12}, {    255,11}, \
    {    543,12}, {    287,11}, {    607,12}, {    319,11}, \
    {    639,12}, {    351,13}, {    191,12}, {    383,11}, \
    {    767,12}, {    415,11}, {    831,12}, {    479,14}, \
    {    127,13}, {    255,12}, {    543,11}, {   1087,12}, \
    {    607,13}, {    319,12}, {    703,13}, {    383,12}, \
    {    831,13}, {    447,12}, {    895,14}, {    255,13}, \
    {    511,12}, {   1023,13}, {    575,12}, {   1151,13}, \
    {    639,12}, {   1279,13}, {    703,14}, {    383,13}, \
    {    831,12}, {   1663,13}, {    895,15}, {    255,14}, \
    {    511,13}, {   1087,12}, {   2175,13}, {   1151,14}, \
    {    639,13}, {   1343,12}, {   2687,14}, {    767,13}, \
    {   1663,14}, {    895,15}, {    511,14}, {   1023,13}, \
    {   2175,14}, {   1151,13}, {   2431,14}, {   1279,13}, \
    {   2687,15}, {    767,14}, {   1663,13}, {   3327,16}, \
    {    511,15}, {   1023,14}, {   2175,13}, {   4351,14}, \
    {   2431,13}, {   4863,15}, {   1279,14}, {   2943,13}, \
    {   5887,15}, {   1535,14}, {   3455,13}, {   6911,15}, \
    {   1791,14}, {   3839,13}, {   7679,16}, {   1023,15}, \
    {   2047,14}, {   4223,13}, {   8447,14}, {   4479,15}, \
    {   2303,14}, {   4863,15}, {   2559,14}, {   5247,15}, \
    {   2815,14}, {   5887,16}, {   1535,15}, {   3071,14}, \
    {   6271,15}, {   3327,14}, {   6911,15}, {   3839,14}, \
    {   7679,17}, {   1023,16}, {   2047,15}, {   4095,14}, \
    {   8447,15}, {   4351,14}, {   8959,15}, {   4863,16}, \
    {   2559,15}, {   5887,14}, {  11775,16}, {   3071,15}, \
    {  32768,16}, {  65536,17}, { 131072,18}, { 262144,19}, \
    { 524288,20}, {1048576,21}, {2097152,22}, {4194304,23}, \
    {8388608,24} }
#define MUL_FFT_TABLE3_SIZE 201
#define MUL_FFT_THRESHOLD                 3200

#define SQR_FFT_MODF_THRESHOLD             340  /* k = 5 */
#define SQR_FFT_TABLE3                                      \
  { {    340, 5}, {     19, 6}, {     10, 5}, {     21, 6}, \
    {     11, 5}, {     23, 6}, {     21, 7}, {     11, 6}, \
    {     23, 7}, {     12, 6}, {     25, 7}, {     13, 6}, \
    {     27, 7}, {     21, 8}, {     11, 7}, {     25, 8}, \
    {     13, 7}, {     27, 8}, {     15, 7}, {     31, 8}, \
    {     21, 9}, {     11, 8}, {     27, 9}, {     15, 8}, \
    {     35, 9}, {     19, 8}, {     41, 9}, {     23, 8}, \
    {     47, 9}, {     27,10}, {     15, 9}, {     39,10}, \
    {     23, 9}, {     51,11}, {     15,10}, {     31, 9}, \
    {     63,10}, {     39, 9}, {     79,10}, {     47,11}, \
    {     31,10}, {     79,11}, {     47,10}, {     95, 6}, \
    {   1663, 7}, {    895, 9}, {    239, 8}, {    479,10}, \
    {    127, 9}, {    255, 8}, {    511,10}, {    135, 9}, \
    {    271,11}, {     79, 9}, {    319,11}, {     95,10}, \
    {    191, 9}, {    383,10}, {    207,11}, {    111,12}, \
    {     63,11}, {    127,10}, {    255, 9}, {    511,10}, \
    {    271, 9}, {    543,10}, {    287, 9}, {    575,10}, \
    {    303, 9}, {    607,10}, {    319, 9}, {    639,12}, \
    {     95,11}, {    191,10}, {    383,11}, {    207,10}, \
    {    415,13}, {     63,12}, {    127,11}, {    255,10}, \
    {    511,11}, {    271,10}, {    543,11}, {    287,10}, \
    {    575,11}, {    303,10}, {    607,11}, {    319,10}, \
    {    639,11}, {    351,10}, {    703,11}, {    367,12}, \
    {    191,11}, {    383,10}, {    767,11}, {    415,12}, \
    {    223,11}, {    479,13}, {    127,12}, {    255,11}, \
    {    543,12}, {    287,11}, {    607,12}, {    319,11}, \
    {    639,12}, {    351,11}, {    703,13}, {    191,12}, \
    {    383,11}, {    767,12}, {    415,11}, {    831,12}, \
    {    479,14}, {    127,13}, {    255,12}, {    607,13}, \
    {    319,12}, {    735,13}, {    383,12}, {    831,13}, \
    {    447,12}, {    895,14}, {    255,13}, {    511,12}, \
    {   1023,13}, {    575,12}, {   1151,13}, {    703,14}, \
    {    383,13}, {    831,12}, {   1663,13}, {    895,15}, \
    {    255,14}, {    511,13}, {   1087,12}, {   2175,13}, \
    {   1151,14}, {    639,13}, {   1343,12}, {   2687,13}, \
    {   1407,14}, {    767,13}, {   1599,12}, {   3199,13}, \
    {   1663,14}, {    895,15}, {    511,14}, {   1023,13}, \
    {   2175,14}, {   1151,13}, {   2431,14}, {   1279,13}, \
    {   2687,14}, {   1407,15}, {    767,14}, {   1535,13}, \
    {   3199,14}, {   1663,13}, {   3455,16}, {    511,15}, \
    {   1023,14}, {   2175,13}, {   4479,14}, {   2431,13}, \
    {   4863,15}, {   1279,14}, {   2943,13}, {   5887,15}, \
    {   1535,14}, {   3455,13}, {   6911,15}, {   1791,14}, \
    {   3839,13}, {   7679,16}, {   1023,15}, {   2047,14}, \
    {   4479,15}, {   2303,14}, {   4991,15}, {   2815,14}, \
    {   5887,16}, {   1535,15}, {   3071,14}, {   6143,15}, \
    {   3327,14}, {   6911,15}, {   3839,14}, {   7679,17}, \
    {   1023,16}, {   2047,15}, {   4095,14}, {   8191,15}, \
    {   4351,14}, {   8959,15}, {   4863,16}, {   2559,15}, \
    {   5887,14}, {  11775,16}, {   3071,15}, {  32768,16}, \
    {  65536,17}, { 131072,18}, { 262144,19}, { 524288,20}, \
    {1048576,21}, {2097152,22}, {4194304,23}, {8388608,24} }
#define SQR_FFT_TABLE3_SIZE 208
#define SQR_FFT_THRESHOLD                 2880

#define MULLO_BASECASE_THRESHOLD             0  /* always */
#define MULLO_DC_THRESHOLD                  63
#define MULLO_MUL_N_THRESHOLD             6253
#define SQRLO_BASECASE_THRESHOLD             8
#define SQRLO_DC_THRESHOLD                  54
#define SQRLO_SQR_THRESHOLD               5558

#define DC_DIV_QR_THRESHOLD                 72
#define DC_DIVAPPR_Q_THRESHOLD             195
#define DC_BDIV_QR_THRESHOLD                50
#define DC_BDIV_Q_THRESHOLD                 90

#define INV_MULMOD_BNM1_THRESHOLD           46
#define INV_NEWTON_THRESHOLD               195
#define INV_APPR_THRESHOLD                 197

#define BINV_NEWTON_THRESHOLD              230
#define REDC_1_TO_REDC_2_THRESHOLD          67
#define REDC_2_TO_REDC_N_THRESHOLD           0  /* always */

#define MU_DIV_QR_THRESHOLD               1334
#define MU_DIVAPPR_Q_THRESHOLD            1334
#define MUPI_DIV_QR_THRESHOLD              104
#define MU_BDIV_QR_THRESHOLD              1017
#define MU_BDIV_Q_THRESHOLD               1187

#define POWM_SEC_TABLE  1,16,194,712,779,2387

#define GET_STR_DC_THRESHOLD                15
#define GET_STR_PRECOMPUTE_THRESHOLD        29
#define SET_STR_DC_THRESHOLD               216
#define SET_STR_PRECOMPUTE_THRESHOLD       994

#define FAC_DSC_THRESHOLD                  153
#define FAC_ODD_THRESHOLD                    0  /* always */

#define MATRIX22_STRASSEN_THRESHOLD         17
#define HGCD2_DIV1_METHOD                    1  /* 9.38% faster than 3 */
#define HGCD_THRESHOLD                      77
#define HGCD_APPR_THRESHOLD                 50
#define HGCD_REDUCE_THRESHOLD             2121
#define GCD_DC_THRESHOLD                   440
#define GCDEXT_DC_THRESHOLD                273
#define JACOBI_BASE_METHOD                   1  /* 7.74% faster than 4 */

/* Tuneup completed successfully, took 495910 seconds */
