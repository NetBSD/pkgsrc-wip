$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/zygote_host/zygote_host_impl_linux.h.orig	2024-10-18 12:34:14.198494700 +0000
+++ content/browser/zygote_host/zygote_host_impl_linux.h
@@ -47,12 +47,14 @@ class CONTENT_EXPORT ZygoteHostImpl : pu
                      base::ScopedFD* control_fd,
                      base::FileHandleMappingVector additional_remapped_fds);
 
+#if !BUILDFLAG(IS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
 #if BUILDFLAG(IS_CHROMEOS)
   void ReinitializeLogging(uint32_t logging_dest,
                            base::PlatformFile log_file_fd) override;
 #endif  // BUILDFLAG(IS_CHROMEOS)
+#endif
 
   bool HasZygote() { return !zygote_pids_.empty(); }
 
@@ -67,9 +69,11 @@ class CONTENT_EXPORT ZygoteHostImpl : pu
 
   int renderer_sandbox_status_;
 
+#if !BUILDFLAG(IS_BSD)
   bool use_namespace_sandbox_;
   bool use_suid_sandbox_;
   bool use_suid_sandbox_for_adj_oom_score_;
+#endif
   std::string sandbox_binary_;
 
   // This lock protects the |zygote_pids_| set.
