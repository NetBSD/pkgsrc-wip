$NetBSD$

--- base/debug/proc_maps_linux.cc.orig	2016-11-10 20:02:09.000000000 +0000
+++ base/debug/proc_maps_linux.cc
@@ -12,7 +12,7 @@
 #include "base/strings/string_split.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_ANDROID)
 #include <inttypes.h>
 #endif
 
