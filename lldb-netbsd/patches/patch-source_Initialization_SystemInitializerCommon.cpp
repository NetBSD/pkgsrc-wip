$NetBSD$

--- source/Initialization/SystemInitializerCommon.cpp.orig	2016-12-17 10:30:23.000000000 +0000
+++ source/Initialization/SystemInitializerCommon.cpp
@@ -26,7 +26,7 @@
 #include "Plugins/ObjectFile/Mach-O/ObjectFileMachO.h"
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
 #include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
 #endif
 
@@ -93,7 +93,7 @@ void SystemInitializerCommon::Initialize
 #if defined(__APPLE__)
   ObjectFileMachO::Initialize();
 #endif
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   static ConstString g_linux_log_name("linux");
   ProcessPOSIXLog::Initialize(g_linux_log_name);
 #endif
