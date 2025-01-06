$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/platform/platform.h.orig	2024-10-18 12:34:34.668523300 +0000
+++ third_party/blink/public/platform/platform.h
@@ -374,7 +374,7 @@ class BLINK_PLATFORM_EXPORT Platform {
     return nullptr;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // This is called after the thread is created, so the embedder
   // can initiate an IPC to change its thread type (on Linux we can't
   // increase the nice value, so we need to ask the browser process). This
@@ -662,6 +662,9 @@ class BLINK_PLATFORM_EXPORT Platform {
   virtual void DidStartWorkerThread() {}
   virtual void WillStopWorkerThread() {}
   virtual void WorkerContextCreated(const v8::Local<v8::Context>& worker) {}
+  virtual void WorkerScriptReadyForEvaluation(
+      const v8::Local<v8::Context>& worker) {}
+  virtual void WorkerContextWillDestroy(const v8::Local<v8::Context>& worker) {}
   virtual bool AllowScriptExtensionForServiceWorker(
       const WebSecurityOrigin& script_origin) {
     return false;
