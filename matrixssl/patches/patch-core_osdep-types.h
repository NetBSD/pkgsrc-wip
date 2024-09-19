$NetBSD$

Get size_t on at least macOS.

--- core/osdep-types.h.orig	2017-06-28 06:34:11.000000000 +0000
+++ core/osdep-types.h
@@ -1,3 +1,4 @@
+#include <sys/types.h>
 /**
  *      @file    osdep-types.h
  *      @version 950bba4 (HEAD -> master)
