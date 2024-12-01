$NetBSD$

Add support of NetBSD platform.

--- source/print.cpp.orig	2024-04-22 19:29:56.000000000 +0000
+++ source/print.cpp
@@ -16,8 +16,9 @@
 
 #if defined(SPIRV_ANDROID) || defined(SPIRV_LINUX) || defined(SPIRV_MAC) || \
     defined(SPIRV_IOS) || defined(SPIRV_TVOS) || defined(SPIRV_FREEBSD) ||  \
-    defined(SPIRV_OPENBSD) || defined(SPIRV_EMSCRIPTEN) ||                  \
-    defined(SPIRV_FUCHSIA) || defined(SPIRV_GNU) || defined(SPIRV_QNX)
+    defined(SPIRV_NETBSD) || defined(SPIRV_OPENBSD) ||                      \
+    defined(SPIRV_EMSCRIPTEN) || defined(SPIRV_FUCHSIA) ||                  \
+    defined(SPIRV_GNU) || defined(SPIRV_QNX)
 namespace spvtools {
 
 clr::reset::operator const char*() { return "\x1b[0m"; }
