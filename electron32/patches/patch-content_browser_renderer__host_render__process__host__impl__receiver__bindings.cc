$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_process_host_impl_receiver_bindings.cc.orig	2024-10-18 12:34:13.578814700 +0000
+++ content/browser/renderer_host/render_process_host_impl_receiver_bindings.cc
@@ -52,7 +52,7 @@
 #include "third_party/blink/public/mojom/webdatabase/web_database.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
 #include "content/browser/font_service.h"  // nogncheck
 #include "content/browser/media/video_encode_accelerator_provider_launcher.h"
@@ -341,7 +341,7 @@ void RenderProcessHostImpl::IOThreadHost
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
