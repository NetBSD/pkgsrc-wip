$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/common/system_utils_linux.cpp.orig	2025-01-27 17:37:37.000000000 +0000
+++ third_party/angle/src/common/system_utils_linux.cpp
@@ -15,8 +15,15 @@
 
 #include <array>
 
+#if ANGLE_PLATFORM_OPENBSD
+#include <pthread_np.h>
+#elif ANGLE_PLATFORM_NETBSD
+#include <pthread.h>
+#endif
+
 namespace angle
 {
+#if ANGLE_PLATFORM_LINUX
 std::string GetExecutablePath()
 {
     // We cannot use lstat to get the size of /proc/self/exe as it always returns 0
@@ -32,6 +39,7 @@ std::string GetExecutablePath()
     path[result] = '\0';
     return path;
 }
+#endif
 
 std::string GetExecutableDirectory()
 {
@@ -56,6 +64,12 @@ void SetCurrentThreadName(const char *na
 {
     // There's a 15-character (16 including '\0') limit.  If the name is too big (and ERANGE is
     // returned), just ignore the name.
+#if ANGLE_PLATFORM_OPENBSD
+    pthread_set_name_np(pthread_self(), name);
+#elif ANGLE_PLATFORM_NETBSD
+    pthread_setname_np(pthread_self(), "%s", (void *)name);
+#else
     pthread_setname_np(pthread_self(), name);
+#endif
 }
 }  // namespace angle
