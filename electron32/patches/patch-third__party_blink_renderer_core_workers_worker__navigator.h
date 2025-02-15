$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/workers/worker_navigator.h.orig	2024-10-18 12:34:35.760020500 +0000
+++ third_party/blink/renderer/core/workers/worker_navigator.h
@@ -29,6 +29,7 @@
 #include "third_party/blink/public/platform/web_worker_fetch_context.h"
 #include "third_party/blink/renderer/core/core_export.h"
 #include "third_party/blink/renderer/core/execution_context/navigator_base.h"
+#include "third_party/blink/renderer/platform/accept_languages_watcher.h"
 #include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
 
 namespace blink {
@@ -46,6 +47,9 @@ class CORE_EXPORT WorkerNavigator final 
 
   // AcceptLanguagesWatcher override
   void NotifyUpdate() override;
+
+  // Both NavigatorLanguage and AcceptLanguagesWatcher override
+  void Trace(Visitor* visitor) const override;
 };
 
 }  // namespace blink
