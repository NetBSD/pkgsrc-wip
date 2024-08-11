$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/controller/memory_usage_monitor_posix.h.orig	2024-07-24 02:44:45.381628500 +0000
+++ third_party/blink/renderer/controller/memory_usage_monitor_posix.h
@@ -13,7 +13,7 @@
 #include "third_party/blink/renderer/controller/controller_export.h"
 #include "third_party/blink/renderer/controller/memory_usage_monitor.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/public/mojom/memory_usage_monitor_linux.mojom-blink.h"
 #endif
 
@@ -22,7 +22,7 @@ namespace blink {
 // MemoryUsageMonitor implementation for Android and Linux.
 class CONTROLLER_EXPORT MemoryUsageMonitorPosix
     : public MemoryUsageMonitor
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     ,
       public mojom::blink::MemoryUsageMonitorLinux
 #endif
@@ -30,7 +30,7 @@ class CONTROLLER_EXPORT MemoryUsageMonit
  public:
   MemoryUsageMonitorPosix() = default;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static void Bind(
       mojo::PendingReceiver<mojom::blink::MemoryUsageMonitorLinux> receiver);
 #endif
@@ -48,7 +48,7 @@ class CONTROLLER_EXPORT MemoryUsageMonit
                                               uint64_t* vm_size,
                                               uint64_t* vm_hwm_size);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // mojom::MemoryUsageMonitorLinux implementations:
   void SetProcFiles(base::File statm_file, base::File status_file) override;
 #endif
@@ -66,7 +66,7 @@ class CONTROLLER_EXPORT MemoryUsageMonit
   base::ScopedFD statm_fd_;
   base::ScopedFD status_fd_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   mojo::Receiver<mojom::blink::MemoryUsageMonitorLinux> receiver_{this};
 #endif
 };
