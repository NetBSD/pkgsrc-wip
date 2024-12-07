$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/browser/service_process_host.cc.orig	2024-12-03 23:30:19.465721000 +0000
+++ content/public/browser/service_process_host.cc
@@ -71,7 +71,7 @@ ServiceProcessHost::Options::WithPreload
 ServiceProcessHost::Options& ServiceProcessHost::Options::WithGpuClient(
     base::PassKey<ServiceProcessHostGpuClient> passkey) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   allow_gpu_client = true;
 #endif
   return *this;
