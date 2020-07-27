$NetBSD$

--- chrome/browser/tracing/crash_service_uploader.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/tracing/crash_service_uploader.cc
@@ -158,6 +158,8 @@ void TraceCrashServiceUploader::DoCompre
   const char product[] = "Chrome_ChromeOS";
 #elif defined(OS_LINUX)
   const char product[] = "Chrome_Linux";
+#elif defined(OS_NETBSD)
+  const char product[] = "Chrome_NetBSD";
 #elif defined(OS_ANDROID)
   const char product[] = "Chrome_Android";
 #else
