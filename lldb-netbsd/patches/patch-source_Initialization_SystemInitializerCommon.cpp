$NetBSD$

--- source/Initialization/SystemInitializerCommon.cpp.orig	2017-02-27 20:47:53.000000000 +0000
+++ source/Initialization/SystemInitializerCommon.cpp
@@ -26,7 +26,7 @@
 #include "Plugins/ObjectFile/Mach-O/ObjectFileMachO.h"
 #endif
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
 #endif
 
@@ -93,7 +93,7 @@ void SystemInitializerCommon::Initialize
 #if defined(__APPLE__)
   ObjectFileMachO::Initialize();
 #endif
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
   ProcessPOSIXLog::Initialize();
 #endif
 #if defined(_MSC_VER)
