$NetBSD$

--- third_party/pdfium/core/fxcrt/cfx_datetime.cpp.orig	2020-07-15 19:01:38.000000000 +0000
+++ third_party/pdfium/core/fxcrt/cfx_datetime.cpp
@@ -10,7 +10,7 @@
 #include "core/fxcrt/fx_system.h"
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_ASMJS) || defined(__wasm__)
+    defined(OS_ASMJS) || defined(__wasm__) || defined(OS_BSD)
 #include <sys/time.h>
 #include <time.h>
 #endif
