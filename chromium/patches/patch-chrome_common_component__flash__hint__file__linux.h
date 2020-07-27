$NetBSD$

--- chrome/common/component_flash_hint_file_linux.h.orig	2020-07-24 02:37:49.000000000 +0000
+++ chrome/common/component_flash_hint_file_linux.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 #error "This file only applies to the Linux component update of Flash."
 #endif  // !defined(OS_LINUX)
 
