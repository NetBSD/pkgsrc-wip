$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/src/node_platform.h.orig	2026-11-03 19:08:32.733845371 +0000
+++ third_party/electron_node/src/node_platform.h
@@ -266,6 +266,7 @@ class NodePlatform : public MultiIsolate
  private:
   IsolatePlatformDelegate* ForIsolate(v8::Isolate* isolate);
   std::shared_ptr<PerIsolatePlatformData> ForNodeIsolate(v8::Isolate* isolate);
+  bool FlushForegroundTasksForAllIsolates();
 
   Mutex per_isolate_mutex_;
   using DelegatePair = std::pair<IsolatePlatformDelegate*,
