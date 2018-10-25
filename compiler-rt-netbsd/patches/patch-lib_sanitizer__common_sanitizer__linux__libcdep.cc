$NetBSD$

--- lib/sanitizer_common/sanitizer_linux_libcdep.cc.orig	2018-10-25 20:11:47.199977515 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cc
@@ -25,6 +25,7 @@
 #include "sanitizer_freebsd.h"
 #include "sanitizer_linux.h"
 #include "sanitizer_placement_new.h"
+#include "sanitizer_posix.h"
 #include "sanitizer_procmaps.h"
 
 #include <dlfcn.h>  // for dlsym()
