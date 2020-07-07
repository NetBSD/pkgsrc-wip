$NetBSD$

Use pthreads on NetBSD.

From upstream pull request #355:

 <https://github.com/9fans/plan9port/pull/355>

--- src/libthread/NetBSD-386-asm.s.orig	2020-06-22 15:22:27.000000000 +0000
+++ src/libthread/NetBSD-386-asm.s
@@ -1,7 +0,0 @@
-.globl _tas
-_tas:
-	movl $0xCAFEBABE, %eax
-	movl 4(%esp), %ecx
-	xchgl %eax, 0(%ecx)
-	ret
-
