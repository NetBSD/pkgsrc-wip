$NetBSD$

--- test/sanitizer_common/TestCases/get_module_and_offset_for_pc.cc.orig	2018-10-31 22:49:16.000000000 +0000
+++ test/sanitizer_common/TestCases/get_module_and_offset_for_pc.cc
@@ -5,7 +5,6 @@
 
 // UNSUPPORTED: i386-darwin
 // XFAIL: android
-// XFAIL: netbsd && msan
 
 // Tests __sanitizer_get_module_and_offset_for_pc.
 
