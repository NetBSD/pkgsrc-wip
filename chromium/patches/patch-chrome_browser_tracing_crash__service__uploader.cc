$NetBSD$

--- chrome/browser/tracing/crash_service_uploader.cc.orig	2017-02-02 02:02:49.000000000 +0000
+++ chrome/browser/tracing/crash_service_uploader.cc
@@ -156,6 +156,10 @@ void TraceCrashServiceUploader::DoUpload
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
+#elif defined(OS_NETBSD)
+  const char product[] = "Chrome_NetBSD";
 #else
 #error Platform not supported.
 #endif
