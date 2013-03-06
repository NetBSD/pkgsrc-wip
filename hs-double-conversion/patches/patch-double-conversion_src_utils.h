$NetBSD: patch-double-conversion_src_utils.h,v 1.2 2013/03/06 15:08:32 phonohawk Exp $

GCC defines __POWERPC__ instead of __powerpc__ for that
architecture. Should be sent to the upstream?


--- double-conversion/src/utils.h.orig	2012-12-31 22:09:16.000000000 +0000
+++ double-conversion/src/utils.h
@@ -56,6 +56,7 @@
     defined(__ARMEL__) || defined(__avr32__) || \
     defined(__hppa__) || defined(__ia64__) || \
     defined(__mips__) || defined(__powerpc__) || \
+    defined(__POWERPC__) || \
     defined(__sparc__) || defined(__sparc) || defined(__s390__) || \
     defined(__SH4__) || defined(__alpha__) || \
     defined(_MIPS_ARCH_MIPS32R2)
