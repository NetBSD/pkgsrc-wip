$NetBSD: patch-md4.c,v 1.1 2012/12/03 13:10:03 othyro Exp $

Needs memcpy.

--- md4.c.orig	2003-06-17 12:50:47.000000000 +0000
+++ md4.c
@@ -25,6 +25,8 @@
    It assumes that a int is at least 32 bits long
 */
 
+#include <string.h>
+
 typedef unsigned int uint32;
 
 static uint32 A, B, C, D;
