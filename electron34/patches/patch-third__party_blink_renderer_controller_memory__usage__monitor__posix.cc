$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/controller/memory_usage_monitor_posix.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/controller/memory_usage_monitor_posix.cc
@@ -128,15 +128,17 @@ void MemoryUsageMonitorPosix::ResetFileD
 
 void MemoryUsageMonitorPosix::SetProcFiles(base::File statm_file,
                                            base::File status_file) {
+#if !BUILDFLAG(IS_BSD)
   DCHECK(statm_file.IsValid());
   DCHECK(status_file.IsValid());
   DCHECK_EQ(-1, statm_fd_.get());
   DCHECK_EQ(-1, status_fd_.get());
   statm_fd_.reset(statm_file.TakePlatformFile());
   status_fd_.reset(status_file.TakePlatformFile());
+#endif
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 void MemoryUsageMonitorPosix::Bind(
     mojo::PendingReceiver<mojom::blink::MemoryUsageMonitorLinux> receiver) {
