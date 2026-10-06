$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/tracing/agent.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/tracing/agent.h
@@ -27,7 +27,9 @@ class Agent;
 class AsyncTraceWriter {
  public:
   virtual ~AsyncTraceWriter() = default;
+#ifndef V8_USE_PERFETTO
   virtual void AppendTraceEvent(TraceObject* trace_event) = 0;
+#endif
   virtual void Flush(bool blocking) = 0;
   virtual void InitializeOnThread(uv_loop_t* loop) {}
 };
@@ -36,6 +38,7 @@ class TracingController : public v8::pla
  public:
   TracingController() : v8::platform::tracing::TracingController() {}
 
+#ifndef V8_USE_PERFETTO
   int64_t CurrentTimestampMicroseconds() override {
     return uv_hrtime() / 1000;
   }
@@ -48,6 +51,7 @@ class TracingController : public v8::pla
       const uint64_t* arg_values,
       std::unique_ptr<v8::ConvertableToTraceFormat>* convertable_values,
       unsigned int flags);
+#endif
 };
 
 class AgentWriterHandle {
@@ -108,11 +112,12 @@ class Agent {
 
   // Returns a comma-separated list of enabled categories.
   std::string GetEnabledCategories() const;
-
+#ifndef V8_USE_PERFETTO
   // Writes to all writers registered through AddClient().
   void AppendTraceEvent(TraceObject* trace_event);
 
   void AddMetadataEvent(std::unique_ptr<TraceObject> event);
+#endif
   // Flushes all writers registered through AddClient().
   void Flush(bool blocking);
 
@@ -152,7 +157,9 @@ class Agent {
   std::set<AsyncTraceWriter*> to_be_initialized_;
 
   Mutex metadata_events_mutex_;
+#ifndef V8_USE_PERFETTO
   std::list<std::unique_ptr<TraceObject>> metadata_events_;
+#endif
 };
 
 void AgentWriterHandle::reset() {
