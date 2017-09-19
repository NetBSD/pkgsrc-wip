$NetBSD$

cstring for strerror.
recognise netbsd as having procfs

--- base/file.cpp.orig	2017-06-27 22:39:52.000000000 +0000
+++ base/file.cpp
@@ -26,6 +26,7 @@
 #include <memory>
 #include <mutex>
 #include <string>
+#include <cstring>
 #include <vector>
 
 #include "android-base/macros.h"  // For TEMP_FAILURE_RETRY on Darwin.
@@ -235,7 +236,7 @@ bool Realpath(const std::string& path, s
 #endif
 
 std::string GetExecutablePath() {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   std::string path;
   android::base::Readlink("/proc/self/exe", &path);
   return path;
