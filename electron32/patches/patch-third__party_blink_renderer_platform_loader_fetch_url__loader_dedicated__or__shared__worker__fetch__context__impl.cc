$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/loader/fetch/url_loader/dedicated_or_shared_worker_fetch_context_impl.cc.orig	2024-10-18 12:34:36.923487200 +0000
+++ third_party/blink/renderer/platform/loader/fetch/url_loader/dedicated_or_shared_worker_fetch_context_impl.cc
@@ -28,6 +28,7 @@
 #include "third_party/blink/public/platform/web_security_origin.h"
 #include "third_party/blink/public/platform/web_url_request_extra_data.h"
 #include "third_party/blink/public/platform/websocket_handshake_throttle_provider.h"
+#include "third_party/blink/renderer/platform/accept_languages_watcher.h"
 #include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader.h"
 #include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_factory.h"
 #include "url/url_constants.h"
@@ -600,9 +601,13 @@ void DedicatedOrSharedWorkerFetchContext
 
 void DedicatedOrSharedWorkerFetchContextImpl::NotifyUpdate(
     const RendererPreferences& new_prefs) {
-  if (accept_languages_watcher_ &&
-      renderer_preferences_.accept_languages != new_prefs.accept_languages)
-    accept_languages_watcher_->NotifyUpdate();
+  // Reserving `accept_languages_watcher` on the stack ensures it is not GC'd
+  // within this scope.
+  auto* accept_languages_watcher = accept_languages_watcher_.Get();
+  if (accept_languages_watcher &&
+      renderer_preferences_.accept_languages != new_prefs.accept_languages) {
+    accept_languages_watcher->NotifyUpdate();
+  }
   renderer_preferences_ = new_prefs;
   for (auto& watcher : child_preference_watchers_)
     watcher->NotifyUpdate(new_prefs);
