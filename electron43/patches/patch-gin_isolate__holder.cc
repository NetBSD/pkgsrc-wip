$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/isolate_holder.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ gin/isolate_holder.cc
@@ -34,6 +34,8 @@ v8::ArrayBuffer::Allocator* g_array_buff
 const intptr_t* g_reference_table = nullptr;
 v8::FatalErrorCallback g_fatal_error_callback = nullptr;
 v8::OOMErrorCallback g_oom_error_callback = nullptr;
+bool g_initialized_microtasks_runner = false;
+bool g_destroyed_microtasks_runner = false;
 
 std::unique_ptr<v8::Isolate::CreateParams> getModifiedIsolateParams(
     std::unique_ptr<v8::Isolate::CreateParams> params,
@@ -76,7 +78,8 @@ IsolateHolder::IsolateHolder(
     v8::CreateHistogramCallback create_histogram_callback,
     v8::AddHistogramSampleCallback add_histogram_sample_callback,
     scoped_refptr<base::SingleThreadTaskRunner> user_visible_task_runner,
-    scoped_refptr<base::SingleThreadTaskRunner> best_effort_task_runner)
+    scoped_refptr<base::SingleThreadTaskRunner> best_effort_task_runner,
+    v8::Isolate* isolate)
     : IsolateHolder(std::move(task_runner),
                     access_mode,
                     isolate_type,
@@ -86,7 +89,8 @@ IsolateHolder::IsolateHolder(
                                              add_histogram_sample_callback),
                     isolate_creation_mode,
                     std::move(user_visible_task_runner),
-                    std::move(best_effort_task_runner)) {}
+                    std::move(best_effort_task_runner),
+                    isolate) {}
 
 IsolateHolder::IsolateHolder(
     scoped_refptr<base::SingleThreadTaskRunner> task_runner,
@@ -95,7 +99,8 @@ IsolateHolder::IsolateHolder(
     std::unique_ptr<v8::Isolate::CreateParams> params,
     IsolateCreationMode isolate_creation_mode,
     scoped_refptr<base::SingleThreadTaskRunner> user_visible_task_runner,
-    scoped_refptr<base::SingleThreadTaskRunner> best_effort_task_runner)
+    scoped_refptr<base::SingleThreadTaskRunner> best_effort_task_runner,
+    v8::Isolate* isolate)
     : access_mode_(access_mode), isolate_type_(isolate_type) {
   CHECK(Initialized())
       << "You need to invoke gin::IsolateHolder::Initialize first";
@@ -106,7 +111,7 @@ IsolateHolder::IsolateHolder(
   v8::ArrayBuffer::Allocator* allocator = params->array_buffer_allocator;
   DCHECK(allocator);
 
-  isolate_ = v8::Isolate::Allocate();
+  isolate_ = isolate ? isolate : v8::Isolate::Allocate();
   isolate_data_ = std::make_unique<PerIsolateData>(
       isolate_, allocator, access_mode_, task_runner,
       std::move(user_visible_task_runner), std::move(best_effort_task_runner));
@@ -154,9 +159,10 @@ void IsolateHolder::Initialize(ScriptMod
                                const intptr_t* reference_table,
                                const std::string js_command_line_flags,
                                v8::FatalErrorCallback fatal_error_callback,
-                               v8::OOMErrorCallback oom_error_callback) {
+                               v8::OOMErrorCallback oom_error_callback,
+                               bool create_v8_platform) {
   CHECK(allocator);
-  V8Initializer::Initialize(mode, js_command_line_flags, oom_error_callback);
+  V8Initializer::Initialize(mode, js_command_line_flags, oom_error_callback, create_v8_platform);
   g_array_buffer_allocator = allocator;
   g_reference_table = reference_table;
   g_fatal_error_callback = fatal_error_callback;
@@ -190,10 +196,26 @@ IsolateHolder::getDefaultIsolateParams()
   return params;
 }
 
+// static
+bool IsolateHolder::DestroyedMicrotasksRunner() {
+  return g_initialized_microtasks_runner &&
+         g_destroyed_microtasks_runner;
+}
+
 void IsolateHolder::EnableIdleTasks(
     std::unique_ptr<V8IdleTaskRunner> idle_task_runner) {
   DCHECK(isolate_data_.get());
   isolate_data_->EnableIdleTasks(std::move(idle_task_runner));
 }
 
+void IsolateHolder::WillCreateMicrotasksRunner() {
+  DCHECK(!g_initialized_microtasks_runner);
+  g_initialized_microtasks_runner = true;
+}
+
+void IsolateHolder::WillDestroyMicrotasksRunner() {
+  DCHECK(g_initialized_microtasks_runner);
+  g_destroyed_microtasks_runner = true;
+}
+
 }  // namespace gin
