$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_platform.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_platform.h
@@ -59,18 +59,21 @@ class PerIsolatePlatformData :
   ~PerIsolatePlatformData() override;
 
   std::shared_ptr<v8::TaskRunner> GetForegroundTaskRunner() override;
-  void PostTask(std::unique_ptr<v8::Task> task) override;
-  void PostIdleTask(std::unique_ptr<v8::IdleTask> task) override;
-  void PostDelayedTask(std::unique_ptr<v8::Task> task,
-                       double delay_in_seconds) override;
+  void PostTaskImpl(std::unique_ptr<v8::Task> task, const v8::SourceLocation&) override;
+  void PostIdleTaskImpl(std::unique_ptr<v8::IdleTask> task, const v8::SourceLocation&) override;
+  void PostDelayedTaskImpl(std::unique_ptr<v8::Task> task,
+                          double delay_in_seconds,
+                          const v8::SourceLocation&) override;
   bool IdleTasksEnabled() override { return false; }
 
   // Non-nestable tasks are treated like regular tasks.
   bool NonNestableTasksEnabled() const override { return true; }
   bool NonNestableDelayedTasksEnabled() const override { return true; }
-  void PostNonNestableTask(std::unique_ptr<v8::Task> task) override;
-  void PostNonNestableDelayedTask(std::unique_ptr<v8::Task> task,
-                                  double delay_in_seconds) override;
+  void PostNonNestableTaskImpl(std::unique_ptr<v8::Task> task,
+                               const v8::SourceLocation&) override;
+  void PostNonNestableDelayedTaskImpl(std::unique_ptr<v8::Task> task,
+                                      double delay_in_seconds,
+                                      const v8::SourceLocation&) override;
 
   void AddShutdownCallback(void (*callback)(void*), void* data);
   void Shutdown();
@@ -147,17 +150,23 @@ class NodePlatform : public MultiIsolate
 
   // v8::Platform implementation.
   int NumberOfWorkerThreads() override;
-  void CallOnWorkerThread(std::unique_ptr<v8::Task> task) override;
-  void CallDelayedOnWorkerThread(std::unique_ptr<v8::Task> task,
-                                 double delay_in_seconds) override;
+  void PostTaskOnWorkerThreadImpl(v8::TaskPriority priority,
+                                  std::unique_ptr<v8::Task> task,
+                                  const v8::SourceLocation& location) override;
+  void PostDelayedTaskOnWorkerThreadImpl(
+      v8::TaskPriority priority,
+      std::unique_ptr<v8::Task> task,
+      double delay_in_seconds,
+      const v8::SourceLocation& location) override;
   bool IdleTasksEnabled(v8::Isolate* isolate) override;
   double MonotonicallyIncreasingTime() override;
   double CurrentClockTimeMillis() override;
   v8::TracingController* GetTracingController() override;
   bool FlushForegroundTasks(v8::Isolate* isolate) override;
-  std::unique_ptr<v8::JobHandle> CreateJob(
+  std::unique_ptr<v8::JobHandle> CreateJobImpl(
       v8::TaskPriority priority,
-      std::unique_ptr<v8::JobTask> job_task) override;
+      std::unique_ptr<v8::JobTask> job_task,
+      const v8::SourceLocation& location) override;
 
   void RegisterIsolate(v8::Isolate* isolate, uv_loop_t* loop) override;
   void RegisterIsolate(v8::Isolate* isolate,
@@ -168,7 +177,7 @@ class NodePlatform : public MultiIsolate
                                   void (*callback)(void*), void* data) override;
 
   std::shared_ptr<v8::TaskRunner> GetForegroundTaskRunner(
-      v8::Isolate* isolate) override;
+      v8::Isolate* isolate, v8::TaskPriority priority) override;
 
   Platform::StackTracePrinter GetStackTracePrinter() override;
   v8::PageAllocator* GetPageAllocator() override;
