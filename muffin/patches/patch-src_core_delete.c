$NetBSD$

Fix _XOPEN_SOURCE on SunOS.

--- src/core/delete.c.orig	2018-05-06 14:14:22.000000000 +0000
+++ src/core/delete.c
@@ -22,7 +22,9 @@
  * 02110-1335, USA.
  */
 
+#if !defined(__sun)
 #define _XOPEN_SOURCE /* for kill() */
+#endif
 
 #include <config.h>
 #include <meta/util.h>
