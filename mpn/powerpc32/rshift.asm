dnl  PowerPC-32 mpn_rshift -- Shift a number right.
dnl
dnl  Copyright 1995, 1998, 2000, 2002 Free Software Foundation, Inc.
dnl
dnl  This file is part of the GNU MP Library.
dnl 
dnl  The GNU MP Library is free software; you can redistribute it and/or
dnl  modify it under the terms of the GNU Lesser General Public License as
dnl  published by the Free Software Foundation; either version 2.1 of the
dnl  License, or (at your option) any later version.
dnl 
dnl  The GNU MP Library is distributed in the hope that it will be useful,
dnl  but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
dnl  Lesser General Public License for more details.
dnl 
dnl  You should have received a copy of the GNU Lesser General Public
dnl  License along with the GNU MP Library; see the file COPYING.LIB.  If
dnl  not, write to the Free Software Foundation, Inc., 59 Temple Place -
dnl  Suite 330, Boston, MA 02111-1307, USA.

include(`../config.m4')


C      cycles/limb
C 604e:    3.0
C 750:     3.0


ASM_START()
PROLOGUE(mpn_rshift)

	C r3	res_ptr
	C r4	s1_ptr
	C r5	size
	C r6	cnt

	cmpi	cr0, r5, 12	C more than 12 limbs?
	addi	r7, r3, -4	C dst-4
	bgt	L(BIG)		C branch if more than 12 limbs

	mtctr	r5		C copy size into CTR
	subfic	r8, r6, 32
	lwz	r11, 0(r4)	C load first s1 limb
	slw	r3, r11, r8	C compute function return value
	bdz	L(end1)

L(oop):	lwzu	r10, 4(r4)
	srw	r9, r11, r6
	slw	r12, r10, r8
	or	r9, r9, r12
	stwu	r9, 4(r7)
	bdz	L(end2)
	lwzu	r11, 4(r4)
	srw	r9, r10, r6
	slw	r12, r11, r8
	or	r9, r9, r12
	stwu	r9, 4(r7)
	bdnz	L(oop)

L(end1):
	srw	r0, r11, r6
	stw	r0, 4(r7)
	blr
L(end2):
	srw	r0, r10, r6
	stw	r0, 4(r7)
	blr

L(BIG):
	stmw	r24, -32(r1)	C save registers we are supposed to preserve
	lwz	r9, 0(r4)
	subfic	r8, r6, 32
	slw	r3, r9, r8	C compute function return value
	srw	r0, r9, r6
	addi	r5, r5, -1

	andi.	r10, r5, 3	C count for spill loop
	beq	L(e)
	mtctr	r10
	lwzu	r28, 4(r4)
	bdz	L(xe0)

L(oop0):
	srw	r12, r28, r6
	slw	r24, r28, r8
	lwzu	r28, 4(r4)
	or	r24, r0, r24
	stwu	r24, 4(r7)
	mr	r0, r12
	bdnz	L(oop0)		C taken at most once!

L(xe0):	srw	r12, r28, r6
	slw	r24, r28, r8
	or	r24, r0, r24
	stwu	r24, 4(r7)
	mr	r0, r12

L(e):	srwi	r5, r5, 2		C count for unrolled loop
	addi	r5, r5, -1
	mtctr	r5
	lwz	r28, 4(r4)
	lwz	r29, 8(r4)
	lwz	r30, 12(r4)
	lwzu	r31, 16(r4)

L(oopU):
	srw	r9, r28, r6
	slw	r24, r28, r8
	lwz	r28, 4(r4)
	srw	r10, r29, r6
	slw	r25, r29, r8
	lwz	r29, 8(r4)
	srw	r11, r30, r6
	slw	r26, r30, r8
	lwz	r30, 12(r4)
	srw	r12, r31, r6
	slw	r27, r31, r8
	lwzu	r31, 16(r4)
	or	r24, r0, r24
	stw	r24, 4(r7)
	or	r25, r9, r25
	stw	r25, 8(r7)
	or	r26, r10, r26
	stw	r26, 12(r7)
	or	r27, r11, r27
	stwu	r27, 16(r7)
	mr	r0, r12
	bdnz	L(oopU)

	srw	r9, r28, r6
	slw	r24, r28, r8
	srw	r10, r29, r6
	slw	r25, r29, r8
	srw	r11, r30, r6
	slw	r26, r30, r8
	srw	r12, r31, r6
	slw	r27, r31, r8
	or	r24, r0, r24
	stw	r24, 4(r7)
	or	r25, r9, r25
	stw	r25, 8(r7)
	or	r26, r10, r26
	stw	r26, 12(r7)
	or	r27, r11, r27
	stwu	r27, 16(r7)
	mr	r0, r12

	stw	r0, 4(r7)
	lmw	r24, -32(r1)	C restore registers
	blr

EPILOGUE(mpn_rshift)
