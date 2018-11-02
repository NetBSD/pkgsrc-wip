$NetBSD$

--- lib/xray/xray_init.cc.orig	2018-09-26 10:51:27.000000000 +0000
+++ lib/xray/xray_init.cc
@@ -106,8 +106,8 @@ __attribute__((section(".preinit_array")
 #else
 // If we cannot use the .preinit_array section, we should instead use dynamic
 // initialisation.
-static bool UNUSED __local_xray_dyninit = [] {
+__attribute__ ((constructor (0)))
+static void __local_xray_dyninit() {
   __xray_init();
-  return true;
-}();
+}
 #endif
