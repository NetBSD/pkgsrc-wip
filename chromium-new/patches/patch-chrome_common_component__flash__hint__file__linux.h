$NetBSD$

--- chrome/common/component_flash_hint_file_linux.h.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/common/component_flash_hint_file_linux.h
@@ -7,9 +7,9 @@
 
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
 #error "This file only applies to the Linux component update of Flash."
-#endif  // !defined(OS_LINUX)
+#endif  // !defined(OS_LINUX) && !defined(OS_FREEBSD)
 
 #include <string>
 
