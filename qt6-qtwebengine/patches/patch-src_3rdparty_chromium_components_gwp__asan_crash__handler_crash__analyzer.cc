$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/gwp_asan/crash_handler/crash_analyzer.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/gwp_asan/crash_handler/crash_analyzer.cc
@@ -35,7 +35,7 @@
 #include "third_party/crashpad/crashpad/snapshot/process_snapshot.h"
 #include "third_party/crashpad/crashpad/util/process/process_memory.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <signal.h>
 #elif BUILDFLAG(IS_APPLE)
 #include <mach/exception_types.h>
@@ -95,7 +95,7 @@ bool CrashAnalyzer::GetExceptionInfo(
 
 crashpad::VMAddress CrashAnalyzer::GetAccessAddress(
     const crashpad::ExceptionSnapshot& exception) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (exception.Exception() == SIGSEGV || exception.Exception() == SIGBUS)
     return exception.ExceptionAddress();
 #elif BUILDFLAG(IS_APPLE)
