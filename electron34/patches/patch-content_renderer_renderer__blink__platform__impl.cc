$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/renderer_blink_platform_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -127,7 +127,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
@@ -196,13 +196,13 @@ RendererBlinkPlatformImpl::RendererBlink
       is_locked_to_site_(false),
       main_thread_scheduler_(main_thread_scheduler),
       next_frame_sink_id_(uint32_t{std::numeric_limits<int32_t>::max()} + 1) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   sk_sp<font_service::FontLoader> font_loader;
 #endif
 
   // RenderThread may not exist in some tests.
   if (RenderThreadImpl::current()) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     mojo::PendingRemote<font_service::mojom::FontService> font_service;
     RenderThreadImpl::current()->BindHostReceiver(
         font_service.InitWithNewPipeAndPassReceiver());
@@ -222,7 +222,7 @@ RendererBlinkPlatformImpl::RendererBlink
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (sandboxEnabled()) {
 #if BUILDFLAG(IS_MAC)
     sandbox_support_ = std::make_unique<WebSandboxSupportMac>();
@@ -283,7 +283,7 @@ void RendererBlinkPlatformImpl::SetThrea
 #endif
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return sandbox_support_.get();
 #else
   // These platforms do not require sandbox support.
@@ -875,12 +875,24 @@ void RendererBlinkPlatformImpl::WillStop
   WorkerThreadRegistry::Instance()->WillStopCurrentWorkerThread();
 }
 
+void RendererBlinkPlatformImpl::WorkerContextWillDestroy(
+    const v8::Local<v8::Context>& worker) {
+  GetContentClient()->renderer()->WillDestroyWorkerContextOnWorkerThread(
+      worker);
+}
+
 void RendererBlinkPlatformImpl::WorkerContextCreated(
     const v8::Local<v8::Context>& worker) {
   GetContentClient()->renderer()->DidInitializeWorkerContextOnWorkerThread(
       worker);
 }
 
+void RendererBlinkPlatformImpl::WorkerScriptReadyForEvaluation(
+    const v8::Local<v8::Context>& worker) {
+  GetContentClient()->renderer()->WorkerScriptReadyForEvaluationOnWorkerThread(
+      worker);
+}
+
 bool RendererBlinkPlatformImpl::AllowScriptExtensionForServiceWorker(
     const blink::WebSecurityOrigin& script_origin) {
   return GetContentClient()->renderer()->AllowScriptExtensionForServiceWorker(
