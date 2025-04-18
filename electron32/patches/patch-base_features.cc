$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/features.cc.orig	2024-10-18 12:33:59.758278800 +0000
+++ base/features.cc
@@ -9,8 +9,10 @@
 #include "base/threading/platform_thread.h"
 #include "build/buildflag.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
+#if !BUILDFLAG(IS_BSD)
 #include "base/message_loop/message_pump_epoll.h"
+#endif
 #include "base/message_loop/message_pump_libevent.h"
 #endif
 
@@ -116,10 +118,12 @@ void Init(EmitThreadControllerProfilerMe
   sequence_manager::internal::ThreadController::InitializeFeatures(
       emit_thread_controller_profiler_metadata);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   MessagePumpLibevent::InitializeFeatures();
+#if !BUILDFLAG(IS_BSD)
   MessagePumpEpoll::InitializeFeatures();
 #endif
+#endif
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_CHROMEOS)
   PlatformThread::InitializeFeatures();
