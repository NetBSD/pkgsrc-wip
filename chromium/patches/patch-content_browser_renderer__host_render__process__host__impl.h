$NetBSD: patch-content_browser_renderer__host_render__process__host__impl.h,v 1.1 2025/02/06 09:58:06 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_process_host_impl.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/renderer_host/render_process_host_impl.h
@@ -102,7 +102,7 @@
 #include "media/fuchsia_media_codec_provider_impl.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/child_thread_type_switcher_linux.h"
 #include "media/mojo/mojom/video_encode_accelerator.mojom.h"
 #endif
@@ -612,7 +612,7 @@ class CONTENT_EXPORT RenderProcessHostIm
   // Sets this RenderProcessHost to be guest only. For Testing only.
   void SetForGuestsOnlyForTesting();
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
 #endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
@@ -973,7 +973,7 @@ class CONTENT_EXPORT RenderProcessHostIm
     std::unique_ptr<service_manager::BinderRegistry> binders_;
     mojo::Receiver<mojom::ChildProcessHost> receiver_{this};
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     mojo::Remote<media::mojom::VideoEncodeAcceleratorProviderFactory>
         video_encode_accelerator_factory_remote_;
     ChildThreadTypeSwitcher child_thread_type_switcher_;
