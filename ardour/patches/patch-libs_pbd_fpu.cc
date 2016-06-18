$NetBSD$

--- libs/pbd/fpu.cc.orig	2016-02-19 01:28:56.000000000 +0000
+++ libs/pbd/fpu.cc
@@ -19,7 +19,9 @@
 
 #include "libpbd-config.h"
 
+#ifndef __NetBSD__
 #define _XOPEN_SOURCE 600
+#endif
 #include <cstring> // for memset
 #include <cstdlib>
 #include <stdint.h>
