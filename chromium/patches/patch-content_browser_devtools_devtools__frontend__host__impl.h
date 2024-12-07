$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/devtools/devtools_frontend_host_impl.h.orig	2024-12-03 23:30:18.765658100 +0000
+++ content/browser/devtools/devtools_frontend_host_impl.h
@@ -34,7 +34,7 @@ class DevToolsFrontendHostImpl : public 
 
   void BadMessageReceived() override;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void OnDidAddMessageToConsole(
       RenderFrameHost* source_frame,
       blink::mojom::ConsoleMessageLevel log_level,
