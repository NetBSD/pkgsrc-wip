$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/api/environment.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/api/environment.cc
@@ -101,6 +101,14 @@ MaybeLocal<Value> PrepareStackTraceCallb
   return result;
 }
 
+NodeArrayBufferAllocator::NodeArrayBufferAllocator() {
+  zero_fill_field_ = static_cast<uint32_t*>(allocator_->Allocate(sizeof(*zero_fill_field_)));
+}
+
+NodeArrayBufferAllocator::~NodeArrayBufferAllocator() {
+  allocator_->Free(zero_fill_field_, sizeof(*zero_fill_field_));
+}
+
 void* NodeArrayBufferAllocator::Allocate(size_t size) {
   void* ret;
   if (zero_fill_field_ || per_process::cli_options->zero_fill_all_buffers)
@@ -236,6 +244,9 @@ void SetIsolateErrorHandlers(v8::Isolate
     auto* prepare_stack_trace_cb = s.prepare_stack_trace_callback ?
         s.prepare_stack_trace_callback : PrepareStackTraceCallback;
     isolate->SetPrepareStackTraceCallback(prepare_stack_trace_cb);
+  } else {
+    auto env = Environment::GetCurrent(isolate);
+    env->set_prepare_stack_trace_callback(Local<Function>());
   }
 }
 
@@ -557,6 +568,10 @@ MultiIsolatePlatform* GetMultiIsolatePla
   return env->platform();
 }
 
+node::tracing::Agent* CreateAgent() {
+  return new node::tracing::Agent();
+}
+
 MultiIsolatePlatform* CreatePlatform(
     int thread_pool_size,
     node::tracing::TracingController* tracing_controller) {
