$NetBSD: patch-libpcsxcore_ix86_iR3000A.c,v 1.1 2011/12/23 00:08:41 othyro Exp $

Fix "MAP_ANONYMOUS' undeclared" error on i386.

--- libpcsxcore/ix86/iR3000A.c.orig	2009-02-23 10:17:22.000000000 +0000
+++ libpcsxcore/ix86/iR3000A.c
@@ -25,6 +25,10 @@
 #include "ix86.h"
 #include <sys/mman.h>
 
+#ifndef MAP_ANONYMOUS
+#define MAP_ANONYMOUS MAP_ANON
+#endif
+
 u32 *psxRecLUT;
 
 #undef PC_REC
