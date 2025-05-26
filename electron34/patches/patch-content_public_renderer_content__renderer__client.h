$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/renderer/content_renderer_client.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/renderer/content_renderer_client.h
@@ -417,6 +417,16 @@ class CONTENT_EXPORT ContentRendererClie
   virtual void DidInitializeWorkerContextOnWorkerThread(
       v8::Local<v8::Context> context) {}
 
+  // Notifies that a worker script has been downloaded, scope initialized and
+  // ready for evaluation. This function is called from the worker thread.
+  virtual void WorkerScriptReadyForEvaluationOnWorkerThread(
+      v8::Local<v8::Context> context) {}
+
+  // Notifies that a worker context will be destroyed. This function is called
+  // from the worker thread.
+  virtual void WillDestroyWorkerContextOnWorkerThread(
+      v8::Local<v8::Context> context) {}
+
   // Overwrites the given URL to use an HTML5 embed if possible.
   // An empty URL is returned if the URL is not overriden.
   virtual GURL OverrideFlashEmbedWithHTML(const GURL& url);
