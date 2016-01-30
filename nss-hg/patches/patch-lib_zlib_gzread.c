$NetBSD$

Missing header for read/write/close.

--- lib/zlib/gzread.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/zlib/gzread.c
@@ -4,6 +4,7 @@
  */
 
 #include "gzguts.h"
+#include <unistd.h>
 
 /* Local functions */
 local int gz_load OF((gz_statep, unsigned char *, unsigned, unsigned *));
