$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/loader/fetch/url_loader/dedicated_or_shared_worker_fetch_context_impl.h.orig	2024-10-18 12:34:36.923487200 +0000
+++ third_party/blink/renderer/platform/loader/fetch/url_loader/dedicated_or_shared_worker_fetch_context_impl.h
@@ -23,6 +23,7 @@
 #include "third_party/blink/public/platform/web_common.h"
 #include "third_party/blink/public/platform/web_dedicated_or_shared_worker_fetch_context.h"
 #include "third_party/blink/public/platform/web_string.h"
+#include "third_party/blink/renderer/platform/heap/persistent.h"
 #include "third_party/blink/renderer/platform/wtf/casting.h"
 #include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
 #include "third_party/blink/renderer/platform/wtf/vector.h"
@@ -300,7 +301,7 @@ class BLINK_PLATFORM_EXPORT DedicatedOrS
   std::unique_ptr<WeakWrapperResourceLoadInfoNotifier>
       weak_wrapper_resource_load_info_notifier_;
 
-  raw_ptr<AcceptLanguagesWatcher> accept_languages_watcher_ = nullptr;
+  WeakPersistent<AcceptLanguagesWatcher> accept_languages_watcher_;
 };
 
 template <>
