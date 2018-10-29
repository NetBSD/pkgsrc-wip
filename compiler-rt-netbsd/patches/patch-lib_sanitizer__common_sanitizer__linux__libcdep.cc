$NetBSD$

--- lib/sanitizer_common/sanitizer_linux_libcdep.cc.orig	2018-10-26 19:38:23.525251811 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cc
@@ -25,6 +25,7 @@
 #include "sanitizer_freebsd.h"
 #include "sanitizer_linux.h"
 #include "sanitizer_placement_new.h"
+#include "sanitizer_posix.h"
 #include "sanitizer_procmaps.h"
 
 #include <dlfcn.h>  // for dlsym()
