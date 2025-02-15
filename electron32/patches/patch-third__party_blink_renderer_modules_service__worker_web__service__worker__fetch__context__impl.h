$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/service_worker/web_service_worker_fetch_context_impl.h.orig	2024-10-18 12:34:36.155838700 +0000
+++ third_party/blink/renderer/modules/service_worker/web_service_worker_fetch_context_impl.h
@@ -6,16 +6,16 @@
 #define THIRD_PARTY_BLINK_RENDERER_MODULES_SERVICE_WORKER_WEB_SERVICE_WORKER_FETCH_CONTEXT_IMPL_H_
 
 #include "base/memory/raw_ptr.h"
+#include "base/task/single_thread_task_runner.h"
 #include "mojo/public/cpp/bindings/pending_receiver.h"
 #include "mojo/public/cpp/bindings/receiver.h"
 #include "third_party/blink/public/common/renderer_preferences/renderer_preferences.h"
 #include "third_party/blink/public/mojom/renderer_preference_watcher.mojom-blink.h"
 #include "third_party/blink/public/mojom/service_worker/service_worker.mojom-forward.h"
 #include "third_party/blink/public/mojom/worker/subresource_loader_updater.mojom-blink.h"
-
-#include "base/task/single_thread_task_runner.h"
 #include "third_party/blink/public/platform/modules/service_worker/web_service_worker_fetch_context.h"
 #include "third_party/blink/public/platform/web_common.h"
+#include "third_party/blink/renderer/platform/heap/persistent.h"
 #include "third_party/blink/renderer/platform/weborigin/kurl.h"
 #include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
 #include "third_party/blink/renderer/platform/wtf/vector.h"
@@ -135,7 +135,7 @@ class BLINK_EXPORT WebServiceWorkerFetch
   // This is owned by ThreadedMessagingProxyBase on the main thread.
   raw_ptr<base::WaitableEvent> terminate_sync_load_event_ = nullptr;
 
-  raw_ptr<AcceptLanguagesWatcher> accept_languages_watcher_ = nullptr;
+  WeakPersistent<AcceptLanguagesWatcher> accept_languages_watcher_;
 
   Vector<String> cors_exempt_header_list_;
   bool is_offline_mode_ = false;
