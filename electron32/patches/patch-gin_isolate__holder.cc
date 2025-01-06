$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gin/isolate_holder.cc.orig	2024-10-18 12:34:18.336388300 +0000
+++ gin/isolate_holder.cc
@@ -75,7 +75,8 @@ IsolateHolder::IsolateHolder(
     IsolateCreationMode isolate_creation_mode,
     v8::CreateHistogramCallback create_histogram_callback,
     v8::AddHistogramSampleCallback add_histogram_sample_callback,
-    scoped_refptr<base::SingleThreadTaskRunner> low_priority_task_runner)
+    scoped_refptr<base::SingleThreadTaskRunner> low_priority_task_runner,
+    v8::Isolate* isolate)
     : IsolateHolder(std::move(task_runner),
                     access_mode,
                     isolate_type,
@@ -84,7 +85,8 @@ IsolateHolder::IsolateHolder(
                                              create_histogram_callback,
                                              add_histogram_sample_callback),
                     isolate_creation_mode,
-                    std::move(low_priority_task_runner)) {}
+                    std::move(low_priority_task_runner),
+                    isolate) {}
 
 IsolateHolder::IsolateHolder(
     scoped_refptr<base::SingleThreadTaskRunner> task_runner,
@@ -92,7 +94,8 @@ IsolateHolder::IsolateHolder(
     IsolateType isolate_type,
     std::unique_ptr<v8::Isolate::CreateParams> params,
     IsolateCreationMode isolate_creation_mode,
-    scoped_refptr<base::SingleThreadTaskRunner> low_priority_task_runner)
+    scoped_refptr<base::SingleThreadTaskRunner> low_priority_task_runner,
+    v8::Isolate* isolate)
     : access_mode_(access_mode), isolate_type_(isolate_type) {
   CHECK(Initialized())
       << "You need to invoke gin::IsolateHolder::Initialize first";
@@ -103,7 +106,7 @@ IsolateHolder::IsolateHolder(
   v8::ArrayBuffer::Allocator* allocator = params->array_buffer_allocator;
   DCHECK(allocator);
 
-  isolate_ = v8::Isolate::Allocate();
+  isolate_ = isolate ? isolate : v8::Isolate::Allocate();
   isolate_data_ = std::make_unique<PerIsolateData>(
       isolate_, allocator, access_mode_, task_runner,
       std::move(low_priority_task_runner));
@@ -151,9 +154,10 @@ void IsolateHolder::Initialize(ScriptMod
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
