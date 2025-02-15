$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/service_worker/web_service_worker_fetch_context_impl.cc.orig	2024-10-18 12:34:36.155838700 +0000
+++ third_party/blink/renderer/modules/service_worker/web_service_worker_fetch_context_impl.cc
@@ -18,6 +18,7 @@
 #include "third_party/blink/public/platform/url_loader_throttle_provider.h"
 #include "third_party/blink/public/platform/web_url_request_extra_data.h"
 #include "third_party/blink/public/platform/websocket_handshake_throttle_provider.h"
+#include "third_party/blink/renderer/platform/accept_languages_watcher.h"
 #include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_factory.h"
 #include "third_party/blink/renderer/platform/loader/internet_disconnected_url_loader.h"
 
@@ -226,9 +227,12 @@ void WebServiceWorkerFetchContextImpl::U
 
 void WebServiceWorkerFetchContextImpl::NotifyUpdate(
     const RendererPreferences& new_prefs) {
-  DCHECK(accept_languages_watcher_);
-  if (renderer_preferences_.accept_languages != new_prefs.accept_languages)
-    accept_languages_watcher_->NotifyUpdate();
+  // Reserving `watcher` on the stack ensures it is not GC'd within this scope.
+  auto* watcher = accept_languages_watcher_.Get();
+  if (watcher &&
+      renderer_preferences_.accept_languages != new_prefs.accept_languages) {
+    watcher->NotifyUpdate();
+  }
   renderer_preferences_ = new_prefs;
 }
 
