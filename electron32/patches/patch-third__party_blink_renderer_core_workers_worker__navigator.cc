$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/workers/worker_navigator.cc.orig	2024-10-18 12:34:35.760020500 +0000
+++ third_party/blink/renderer/core/workers/worker_navigator.cc
@@ -61,4 +61,9 @@ void WorkerNavigator::NotifyUpdate() {
       *Event::Create(event_type_names::kLanguagechange));
 }
 
+void WorkerNavigator::Trace(Visitor* visitor) const {
+  NavigatorBase::Trace(visitor);
+  AcceptLanguagesWatcher::Trace(visitor);
+}
+
 }  // namespace blink
