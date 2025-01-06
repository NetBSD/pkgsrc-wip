$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/tracing/agent.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/tracing/agent.cc
@@ -50,7 +50,9 @@ using v8::platform::tracing::TraceWriter
 using std::string;
 
 Agent::Agent() : tracing_controller_(new TracingController()) {
+#ifndef V8_USE_PERFETTO
   tracing_controller_->Initialize(nullptr);
+#endif
 
   CHECK_EQ(uv_loop_init(&tracing_loop_), 0);
   CHECK_EQ(uv_async_init(&tracing_loop_,
@@ -86,10 +88,14 @@ Agent::~Agent() {
 void Agent::Start() {
   if (started_)
     return;
-
+#ifdef V8_USE_PERFETTO
+  std::ostringstream perfetto_output;
+  tracing_controller_->InitializeForPerfetto(&perfetto_output);
+#else
   NodeTraceBuffer* trace_buffer_ = new NodeTraceBuffer(
       NodeTraceBuffer::kBufferChunks, this, &tracing_loop_);
   tracing_controller_->Initialize(trace_buffer_);
+#endif
 
   // This thread should be created *after* async handles are created
   // (within NodeTraceWriter and NodeTraceBuffer constructors).
@@ -143,8 +149,10 @@ void Agent::StopTracing() {
     return;
   // Perform final Flush on TraceBuffer. We don't want the tracing controller
   // to flush the buffer again on destruction of the V8::Platform.
-  tracing_controller_->StopTracing();
+#ifndef V8_USE_PERFETTO
   tracing_controller_->Initialize(nullptr);
+#endif
+  tracing_controller_->StopTracing();
   started_ = false;
 
   // Thread should finish when the tracing loop is stopped.
@@ -202,6 +210,7 @@ std::string Agent::GetEnabledCategories(
   return categories;
 }
 
+#ifndef V8_USE_PERFETTO
 void Agent::AppendTraceEvent(TraceObject* trace_event) {
   for (const auto& id_writer : writers_)
     id_writer.second->AppendTraceEvent(trace_event);
@@ -211,18 +220,21 @@ void Agent::AddMetadataEvent(std::unique
   Mutex::ScopedLock lock(metadata_events_mutex_);
   metadata_events_.push_back(std::move(event));
 }
+#endif
 
 void Agent::Flush(bool blocking) {
+#ifndef V8_USE_PERFETTO
   {
     Mutex::ScopedLock lock(metadata_events_mutex_);
     for (const auto& event : metadata_events_)
       AppendTraceEvent(event.get());
   }
-
+#endif
   for (const auto& id_writer : writers_)
     id_writer.second->Flush(blocking);
 }
 
+#ifndef V8_USE_PERFETTO
 void TracingController::AddMetadataEvent(
     const unsigned char* category_group_enabled,
     const char* name,
@@ -246,6 +258,6 @@ void TracingController::AddMetadataEvent
   if (node_agent != nullptr)
     node_agent->AddMetadataEvent(std::move(trace_event));
 }
-
+#endif
 }  // namespace tracing
 }  // namespace node
