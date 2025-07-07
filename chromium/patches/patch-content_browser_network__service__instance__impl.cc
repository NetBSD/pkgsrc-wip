$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/network_service_instance_impl.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ content/browser/network_service_instance_impl.cc
@@ -85,7 +85,7 @@
 #include "content/browser/network/network_service_process_tracker_win.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/system_dns_resolution/system_dns_resolver.h"
 #include "services/network/public/mojom/system_dns_resolution.mojom-forward.h"
 #endif
@@ -335,7 +335,7 @@ void CreateInProcessNetworkService(
                                 std::move(receiver)));
 }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Runs a self-owned SystemDnsResolverMojoImpl. This is meant to run on a
 // high-priority thread pool.
 void RunSystemDnsResolverOnThreadPool(
@@ -402,7 +402,7 @@ network::mojom::NetworkServiceParamsPtr 
   }
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (GetContentClient()
           ->browser()
           ->ShouldRunOutOfProcessSystemDnsResolution() &&
