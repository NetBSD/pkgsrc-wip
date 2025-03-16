$NetBSD: patch-components_crash_core_app_chrome__crashpad__handler.cc,v 1.1 2025/02/06 09:57:58 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/crash/core/app/chrome_crashpad_handler.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/crash/core/app/chrome_crashpad_handler.cc
@@ -6,5 +6,9 @@
 extern "C" int CrashpadHandlerMain(int argc, char* argv[]);
 
 int main(int argc, char* argv[]) {
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+  return -1;
+#else
   return CrashpadHandlerMain(argc, argv);
+#endif
 }
