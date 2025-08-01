$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/resource_coordinator/memory_instrumentation/queued_request_dispatcher.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ services/resource_coordinator/memory_instrumentation/queued_request_dispatcher.cc
@@ -54,7 +54,7 @@ uint32_t CalculatePrivateFootprintKb(con
                                      uint32_t shared_resident_kb) {
   DCHECK(os_dump.platform_private_footprint);
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   uint64_t rss_anon_bytes = os_dump.platform_private_footprint->rss_anon_bytes;
   uint64_t vm_swap_bytes = os_dump.platform_private_footprint->vm_swap_bytes;
   return (rss_anon_bytes + vm_swap_bytes) / 1024;
@@ -83,7 +83,7 @@ memory_instrumentation::mojom::OSMemDump
   os_dump->is_peak_rss_resettable = internal_os_dump.is_peak_rss_resettable;
   os_dump->private_footprint_kb =
       CalculatePrivateFootprintKb(internal_os_dump, shared_resident_kb);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   os_dump->private_footprint_swap_kb =
       internal_os_dump.platform_private_footprint->vm_swap_bytes / 1024;
   os_dump->mappings_count = internal_os_dump.mappings_count;
@@ -222,7 +222,7 @@ void QueuedRequestDispatcher::SetUpAndDi
 
 // On most platforms each process can dump data about their own process
 // so ask each process to do so Linux is special see below.
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
     request->pending_responses.insert({client_info.pid, ResponseType::kOSDump});
     client->RequestOSMemoryDump(
         request->memory_map_option(), request->memory_dump_flags(),
@@ -237,7 +237,7 @@ void QueuedRequestDispatcher::SetUpAndDi
 
 // In some cases, OS stats can only be dumped from a privileged process to
 // get around to sandboxing/selinux restrictions (see crbug.com/461788).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::vector<base::ProcessId> pids;
   mojom::ClientProcess* browser_client = nullptr;
   base::ProcessId browser_client_pid = base::kNullProcessId;
@@ -284,7 +284,7 @@ void QueuedRequestDispatcher::SetUpAndDi
     const OsCallback& os_callback) {
 // On Linux, OS stats can only be dumped from a privileged process to
 // get around to sandboxing/selinux restrictions (see crbug.com/461788).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   mojom::ClientProcess* browser_client = nullptr;
   base::ProcessId browser_client_pid = 0;
   for (const auto& client_info : clients) {
@@ -334,7 +334,7 @@ QueuedRequestDispatcher::FinalizeVmRegio
     // each client process provides 1 OS dump, % the case where the client is
     // disconnected mid dump.
     OSMemDumpMap& extra_os_dumps = response.second.os_dumps;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     for (auto& kv : extra_os_dumps) {
       auto pid = kv.first == base::kNullProcessId ? original_pid : kv.first;
       DCHECK(results.find(pid) == results.end());
@@ -395,7 +395,7 @@ void QueuedRequestDispatcher::Finalize(Q
     // crash). In the latter case (OS_LINUX) we expect the full map to come
     // from the browser process response.
     OSMemDumpMap& extra_os_dumps = response.second.os_dumps;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     for (const auto& kv : extra_os_dumps) {
       auto pid = kv.first == base::kNullProcessId ? original_pid : kv.first;
       DCHECK_EQ(pid_to_os_dump[pid], nullptr);
