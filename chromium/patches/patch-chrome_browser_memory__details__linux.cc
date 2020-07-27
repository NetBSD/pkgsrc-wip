$NetBSD$

--- chrome/browser/memory_details_linux.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/memory_details_linux.cc
@@ -69,8 +69,10 @@ ProcessData GetProcessDataMemoryInformat
 
     std::unique_ptr<base::ProcessMetrics> metrics(
         base::ProcessMetrics::CreateProcessMetrics(pid));
+#if !defined(OS_BSD)
     pmi.num_open_fds = metrics->GetOpenFdCount();
     pmi.open_fds_soft_limit = metrics->GetOpenFdSoftLimit();
+#endif
 
     process_data.processes.push_back(pmi);
   }
