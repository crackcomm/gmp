# PowerPC-64 mpn_copyd -- Copy a limb vector.

# Copyright (C) 1999, 2000 Free Software Foundation, Inc.

# This file is part of the GNU MP Library.

# The GNU MP Library is free software; you can redistribute it and/or modify
# it under the terms of the GNU Library General Public License as published by
# the Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.

# The GNU MP Library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
# License for more details.

# You should have received a copy of the GNU Library General Public License
# along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
# the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
# MA 02111-1307, USA.


# INPUT PARAMETERS
# rptr	r3
# sptr	r4
# n	r5

include(`../config.m4')

# Unrolling this analogous to sparc64/copyi.s doesn't help for any
# operand sizes.

ASM_START()
PROLOGUE(mpn_copyd)
	cmpdi	cr0,r5,0
	mtctr	r5
	sldi	r5,r5,3
	add	r4,r4,r5
	add	r3,r3,r5
	beq	cr0,.Lend
.Loop:	ldu	r0,-8(r4)
	stdu	r0,-8(r3)
	bdnz	.Loop
.Lend:	blr
EPILOGUE(mpn_copyd)
