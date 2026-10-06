$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/mac/sandbox_logging.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ sandbox/mac/sandbox_logging.cc
@@ -16,6 +16,7 @@
 #include <string>
 
 #include "build/build_config.h"
+#include "electron/mas.h"
 #include "sandbox/mac/sandbox_crash_message.h"
 
 #if defined(ARCH_CPU_X86_64)
@@ -33,9 +34,11 @@
   }
 #endif
 
+#if !IS_MAS_BUILD()
 extern "C" {
 void abort_report_np(const char*, ...);
 }
+#endif
 
 namespace sandbox::logging {
 
@@ -76,9 +79,11 @@ void SendOsLog(Level level, const char* 
     sandbox::crash_message::SetCrashMessage(message);
   }
 
+#if !IS_MAS_BUILD()
   if (level == Level::FATAL) {
     abort_report_np(message);
   }
+#endif
 }
 
 // |error| is strerror(errno) when a P* logging function is called. Pass
