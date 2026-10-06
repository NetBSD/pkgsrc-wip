$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/renderer_blink_platform_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/renderer/renderer_blink_platform_impl.h
@@ -194,6 +194,9 @@ class CONTENT_EXPORT RendererBlinkPlatfo
   void DidStartWorkerThread() override;
   void WillStopWorkerThread() override;
   void WorkerContextCreated(const v8::Local<v8::Context>& worker) override;
+  void WorkerScriptReadyForEvaluation(
+      const v8::Local<v8::Context>& worker) override;
+  void WorkerContextWillDestroy(const v8::Local<v8::Context>& worker) override;
   bool AllowScriptExtensionForServiceWorker(
       const blink::WebSecurityOrigin& script_origin) override;
   blink::ProtocolHandlerSecurityLevel GetProtocolHandlerSecurityLevel(
@@ -254,7 +257,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
   void Collect3DContextInformation(blink::Platform::GraphicsInfo* gl_info,
                                    const gpu::GPUInfo& gpu_info) const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
