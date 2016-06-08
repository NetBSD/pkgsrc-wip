$NetBSD$

Fix build on NetBSD/amd64. From Wayne Scott.

--- src/libc/utils/crc32c.c.orig	2016-05-16 18:52:05.000000000 +0000
+++ src/libc/utils/crc32c.c
@@ -1247,7 +1247,7 @@ cpuid(u32 functionInput)
 	u32 ebx;
 	u32 ecx;
 	u32 edx;
-#ifdef __PIC__
+#if defined(__PIC__) && !defined(__x86_64__)
 	// PIC: Need to save and restore ebx See:
 	// http://sam.zoy.org/blog/2007-04-13-shlib-with-non-pic-code-have-inline-assembly-and-pic-mix-well
 	asm("pushl %%ebx\n\t" /* save %ebx */
