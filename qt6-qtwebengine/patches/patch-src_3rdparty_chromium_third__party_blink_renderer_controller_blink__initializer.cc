$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/controller/blink_initializer.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/controller/blink_initializer.cc
@@ -81,12 +81,12 @@
 #include "third_party/blink/renderer/controller/private_memory_footprint_provider.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/controller/memory_usage_monitor_posix.h"
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/controller/highest_pmf_reporter.h"
 #include "third_party/blink/renderer/controller/user_level_memory_pressure_signal_generator.h"
 #endif
@@ -255,7 +255,7 @@ void BlinkInitializer::RegisterInterface
       main_thread_task_runner);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   binders.Add<mojom::blink::MemoryUsageMonitorLinux>(
       ConvertToBaseRepeatingCallback(
           CrossThreadBindRepeating(&MemoryUsageMonitorPosix::Bind)),
@@ -302,7 +302,7 @@ void BlinkInitializer::RegisterMemoryWat
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Start reporting the highest private memory footprint after the first
   // navigation.
   HighestPmfReporter::Initialize(main_thread_task_runner);
