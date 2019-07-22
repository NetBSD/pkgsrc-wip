$NetBSD$

--- vm/src/i386/runtime/runtime_i386.hh.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/i386/runtime/runtime_i386.hh
@@ -29,7 +29,8 @@ inline char*     Byte_Map_Base() { retur
 // must really flush windows, call out to asm stub
 // Have to add this for Unix ppc
 # if TARGET_OS_VERSION == MACOSX_VERSION \
-  || TARGET_OS_VERSION == LINUX_VERSION
+  || TARGET_OS_VERSION == LINUX_VERSION \
+  || TARGET_OS_VERSION == NETBSD_VERSION
 extern "C" {
   void FlushInstruction(void* addr);
 }
