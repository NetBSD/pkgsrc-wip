$NetBSD$

libdrm libsync.h should probably be patched instead for ETIME.

--- src/mesa/drivers/dri/i965/brw_sync.c.orig	2017-05-25 07:13:13.000000000 +0000
+++ src/mesa/drivers/dri/i965/brw_sync.c
@@ -38,6 +38,10 @@
  * performance bottleneck, though.
  */
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 #include <libsync.h> /* Requires Android or libdrm-2.4.72 */
 
 #include "main/imports.h"
