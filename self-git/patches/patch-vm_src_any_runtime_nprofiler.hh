$NetBSD$

--- vm/src/any/runtime/nprofiler.hh.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/any/runtime/nprofiler.hh
@@ -102,7 +102,7 @@ class StackInfo {
   // Variable computed at Profiler::suspend().
   float computed_user_time;
   float user_time() { return computed_user_time; }
-# elif  TARGET_OS_FAMILY == MACOS_FAMILY
+# elif  TARGET_OS_FAMILY == MACOS_FAMILY || TARGET_OS_FAMILY == NETBSD_VERSION || defined(__NetBSD__)
   float user_time() { return 0.0; } // unimp mac
 # else
   # error which?
