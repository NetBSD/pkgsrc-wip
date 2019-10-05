$NetBSD$

sincos is a GNU extension.

--- mktimecode.c.orig	2018-01-19 20:40:49.000000000 +0000
+++ mktimecode.c
@@ -22,7 +22,6 @@
  * with xwax.
  */
 
-#define _GNU_SOURCE /* sincos() */
 #include <assert.h>
 #include <limits.h>
 #include <math.h>
@@ -38,6 +37,8 @@
 #define TAPS 0x00002
 #define BITS 22
 
+#define sincos(x, sinp, cosp) *sinp = sin(x); *cosp = cos(x);
+
 #define MAX(x,y) ((x)>(y)?(x):(y))
 
 typedef unsigned int bits_t;
