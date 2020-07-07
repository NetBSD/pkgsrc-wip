$NetBSD$

Use pthreads on NetBSD.

From upstream pull request #355:

 <https://github.com/9fans/plan9port/pull/355>

--- src/libthread/NetBSD-power-asm.s.orig	2020-06-22 15:22:27.000000000 +0000
+++ src/libthread/NetBSD-power-asm.s
@@ -1,16 +0,0 @@
-	.globl	_tas
-_tas:
-	li	%r0, 0
-	mr	%r4, %r3
-	lis	%r5, 0xcafe
-	ori	%r5, %r5, 0xbabe
-1:
-	lwarx	%r3, %r0, %r4
-	cmpwi	%r3, 0
-	bne	2f
-	stwcx.	%r5, %r0, %r4
-	bne-	1b
-2:
-	sync
-	blr
-
