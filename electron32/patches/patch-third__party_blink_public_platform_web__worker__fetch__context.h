$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/platform/web_worker_fetch_context.h.orig	2024-10-18 12:34:34.672521400 +0000
+++ third_party/blink/public/platform/web_worker_fetch_context.h
@@ -33,19 +33,12 @@ class SiteForCookies;
 
 namespace blink {
 
+class AcceptLanguagesWatcher;
 class WebDocumentSubresourceFilter;
 class URLLoaderFactory;
 class WebURLRequest;
 class URLLoaderThrottle;
 
-// Helper class allowing DedicatedOrSharedWorkerFetchContextImpl to notify blink
-// upon an accept languages update. This class will be extended by
-// WorkerNavigator.
-class AcceptLanguagesWatcher {
- public:
-  virtual void NotifyUpdate() = 0;
-};
-
 // WebWorkerFetchContext is a per-worker object created on the main thread,
 // passed to a worker (dedicated, shared and service worker) and initialized on
 // the worker thread by InitializeOnWorkerThread(). It contains information
