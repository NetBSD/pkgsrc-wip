$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/mac/sandbox_logging.cc.orig	2024-10-18 12:34:31.993766300 +0000
+++ sandbox/mac/sandbox_logging.cc
@@ -33,9 +33,11 @@
   }
 #endif
 
+#if !IS_MAS_BUILD()
 extern "C" {
 void abort_report_np(const char*, ...);
 }
+#endif
 
 namespace sandbox::logging {
 
@@ -76,9 +78,11 @@ void SendOsLog(Level level, const char* 
     sandbox::crash_message::SetCrashMessage(message);
   }
 
+#if !IS_MAS_BUILD()
   if (level == Level::FATAL) {
     abort_report_np(message);
   }
+#endif
 }
 
 // |error| is strerror(errno) when a P* logging function is called. Pass
