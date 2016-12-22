$NetBSD$

Include limits.h for INT32_MAX.

--- source/m32exec.c.orig	2015-07-10 07:56:48.000000000 +0000
+++ source/m32exec.c
@@ -20,6 +20,7 @@ Foundation, Inc., 51 Franklin Street, Fi
 */
 //-------------------------------------------------------------------------
 
+#include <limits.h>
 #include <time.h>
 #include <stdlib.h>
 
