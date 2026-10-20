$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/src/node_platform.cc.orig	2026-10-20 08:24:53.480699448 +0000
+++ third_party/electron_node/src/node_platform.cc
@@ -548,6 +548,12 @@ void NodePlatform::AddIsolateFinishedCal
 void NodePlatform::Shutdown() {
   if (has_shut_down_) return;
   has_shut_down_ = true;
+
+  // V8 background tasks may be parked waiting for foreground GC work before
+  // they can return from the worker thread task.
+  while (FlushForegroundTasksForAllIsolates()) {
+  }
+
   worker_thread_task_runner_->Shutdown();
 
   {
@@ -739,6 +745,25 @@ bool NodePlatform::FlushForegroundTasks(
   return per_isolate->FlushForegroundTasksInternal();
 }
 
+bool NodePlatform::FlushForegroundTasksForAllIsolates() {
+  std::vector<std::shared_ptr<PerIsolatePlatformData>> per_isolates;
+  {
+    Mutex::ScopedLock lock(per_isolate_mutex_);
+    per_isolates.reserve(per_isolate_.size());
+    for (const auto& entry : per_isolate_) {
+      if (entry.second.second) {
+        per_isolates.push_back(entry.second.second);
+      }
+    }
+  }
+
+  bool did_work = false;
+  for (const auto& per_isolate : per_isolates) {
+    did_work |= per_isolate->FlushForegroundTasksInternal();
+  }
+  return did_work;
+}
+
 std::unique_ptr<v8::JobHandle> NodePlatform::CreateJobImpl(
     v8::TaskPriority priority,
     std::unique_ptr<v8::JobTask> job_task,
