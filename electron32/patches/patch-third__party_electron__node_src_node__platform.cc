$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_platform.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/node_platform.cc
@@ -245,11 +245,13 @@ void PerIsolatePlatformData::FlushTasks(
   platform_data->FlushForegroundTasksInternal();
 }
 
-void PerIsolatePlatformData::PostIdleTask(std::unique_ptr<v8::IdleTask> task) {
+void PerIsolatePlatformData::PostIdleTaskImpl(std::unique_ptr<v8::IdleTask> task,
+                                              const v8::SourceLocation& location) {
   UNREACHABLE();
 }
 
-void PerIsolatePlatformData::PostTask(std::unique_ptr<Task> task) {
+void PerIsolatePlatformData::PostTaskImpl(std::unique_ptr<Task> task,
+                                          const v8::SourceLocation& location) {
   if (flush_tasks_ == nullptr) {
     // V8 may post tasks during Isolate disposal. In that case, the only
     // sensible path forward is to discard the task.
@@ -259,8 +261,10 @@ void PerIsolatePlatformData::PostTask(st
   uv_async_send(flush_tasks_);
 }
 
-void PerIsolatePlatformData::PostDelayedTask(
-    std::unique_ptr<Task> task, double delay_in_seconds) {
+void PerIsolatePlatformData::PostDelayedTaskImpl(
+    std::unique_ptr<Task> task,
+    double delay_in_seconds,
+    const v8::SourceLocation& location) {
   if (flush_tasks_ == nullptr) {
     // V8 may post tasks during Isolate disposal. In that case, the only
     // sensible path forward is to discard the task.
@@ -274,13 +278,15 @@ void PerIsolatePlatformData::PostDelayed
   uv_async_send(flush_tasks_);
 }
 
-void PerIsolatePlatformData::PostNonNestableTask(std::unique_ptr<Task> task) {
+void PerIsolatePlatformData::PostNonNestableTaskImpl(std::unique_ptr<Task> task,
+                                                     const v8::SourceLocation& location) {
   PostTask(std::move(task));
 }
 
-void PerIsolatePlatformData::PostNonNestableDelayedTask(
+void PerIsolatePlatformData::PostNonNestableDelayedTaskImpl(
     std::unique_ptr<Task> task,
-    double delay_in_seconds) {
+    double delay_in_seconds,
+    const v8::SourceLocation& location) {
   PostDelayedTask(std::move(task), delay_in_seconds);
 }
 
@@ -501,17 +507,22 @@ bool PerIsolatePlatformData::FlushForegr
   return did_work;
 }
 
-void NodePlatform::CallOnWorkerThread(std::unique_ptr<Task> task) {
+void NodePlatform::PostTaskOnWorkerThreadImpl(
+    v8::TaskPriority priority,
+    std::unique_ptr<v8::Task> task,
+    const v8::SourceLocation& location) {
   worker_thread_task_runner_->PostTask(std::move(task));
 }
 
-void NodePlatform::CallDelayedOnWorkerThread(std::unique_ptr<Task> task,
-                                             double delay_in_seconds) {
+void NodePlatform::PostDelayedTaskOnWorkerThreadImpl(
+    v8::TaskPriority priority,
+    std::unique_ptr<v8::Task> task,
+    double delay_in_seconds,
+    const v8::SourceLocation& location) {
   worker_thread_task_runner_->PostDelayedTask(std::move(task),
                                               delay_in_seconds);
 }
 
-
 IsolatePlatformDelegate* NodePlatform::ForIsolate(Isolate* isolate) {
   Mutex::ScopedLock lock(per_isolate_mutex_);
   auto data = per_isolate_[isolate];
@@ -533,8 +544,10 @@ bool NodePlatform::FlushForegroundTasks(
   return per_isolate->FlushForegroundTasksInternal();
 }
 
-std::unique_ptr<v8::JobHandle> NodePlatform::CreateJob(
-    v8::TaskPriority priority, std::unique_ptr<v8::JobTask> job_task) {
+std::unique_ptr<v8::JobHandle> NodePlatform::CreateJobImpl(
+    v8::TaskPriority priority,
+    std::unique_ptr<v8::JobTask> job_task,
+    const v8::SourceLocation& location) {
   return v8::platform::NewDefaultJobHandle(
       this, priority, std::move(job_task), NumberOfWorkerThreads());
 }
