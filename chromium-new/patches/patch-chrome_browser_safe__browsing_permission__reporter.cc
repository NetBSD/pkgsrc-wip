$NetBSD$

--- chrome/browser/safe_browsing/permission_reporter.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/safe_browsing/permission_reporter.cc
@@ -190,7 +190,7 @@ bool PermissionReporter::BuildReport(con
 #if defined(OS_ANDROID)
   report.set_platform_type(PermissionReport::ANDROID_PLATFORM);
 #elif defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_CHROMEOS) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   report.set_platform_type(PermissionReport::DESKTOP_PLATFORM);
 #else
 #error Unsupported platform.
