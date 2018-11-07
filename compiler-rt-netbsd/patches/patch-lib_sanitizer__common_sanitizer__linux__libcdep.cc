$NetBSD$

--- lib/sanitizer_common/sanitizer_linux_libcdep.cc.orig	2018-11-07 20:58:31.926766835 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cc
@@ -26,6 +26,7 @@
 #include "sanitizer_getauxval.h"
 #include "sanitizer_linux.h"
 #include "sanitizer_placement_new.h"
+#include "sanitizer_posix.h"
 #include "sanitizer_procmaps.h"
 
 #include <dlfcn.h>  // for dlsym()
