$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/launch_posix.cc.orig	2024-12-03 23:30:04.288363500 +0000
+++ base/process/launch_posix.cc
@@ -67,6 +67,9 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#if defined(OS_FREEBSD)
+#pragma weak environ
+#endif
 extern char** environ;
 
 namespace base {
@@ -223,6 +226,8 @@ static const char kFDDir[] = "/dev/fd";
 static const char kFDDir[] = "/dev/fd";
 #elif BUILDFLAG(IS_OPENBSD)
 static const char kFDDir[] = "/dev/fd";
+#elif BUILDFLAG(IS_NETBSD)
+static const char kFDDir[] = "/dev/fd";
 #elif BUILDFLAG(IS_ANDROID)
 static const char kFDDir[] = "/proc/self/fd";
 #endif
