$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.h.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.h
@@ -102,7 +102,7 @@
 #include "media/fuchsia_media_codec_provider_impl.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/child_thread_type_switcher_linux.h"
 #include "media/mojo/mojom/video_encode_accelerator.mojom.h"
 #endif
@@ -617,7 +617,7 @@ class CONTENT_EXPORT RenderProcessHostIm
   // Sets this RenderProcessHost to be guest only. For Testing only.
   void SetForGuestsOnlyForTesting();
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Launch the zygote early in the browser startup.
   static void EarlyZygoteLaunch();
 #endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_MAC)
@@ -982,7 +982,7 @@ class CONTENT_EXPORT RenderProcessHostIm
     std::unique_ptr<service_manager::BinderRegistry> binders_;
     mojo::Receiver<mojom::ChildProcessHost> receiver_{this};
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     mojo::Remote<media::mojom::VideoEncodeAcceleratorProviderFactory>
         video_encode_accelerator_factory_remote_;
     ChildThreadTypeSwitcher child_thread_type_switcher_;
@@ -1230,7 +1230,7 @@ class CONTENT_EXPORT RenderProcessHostIm
   // if the request isn't handled on the IO thread.
   void OnBindHostReceiver(mojo::GenericPendingReceiver receiver);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Provides /proc/{renderer pid}/status and statm files for the renderer,
   // because the files are required to calculate the renderer's private
   // footprint on Chromium Linux. Regarding MacOS X and Windows, we have
