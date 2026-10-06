$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/tracing/node_trace_writer.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/tracing/node_trace_writer.cc
@@ -95,7 +95,7 @@ void NodeTraceWriter::OpenNewFileForStre
     fd_ = -1;
   }
 }
-
+#ifndef V8_USE_PERFETTO
 void NodeTraceWriter::AppendTraceEvent(TraceObject* trace_event) {
   Mutex::ScopedLock scoped_lock(stream_mutex_);
   // If this is the first trace event, open a new file for streaming.
@@ -112,7 +112,7 @@ void NodeTraceWriter::AppendTraceEvent(T
   ++total_traces_;
   json_trace_writer_->AppendTraceEvent(trace_event);
 }
-
+#endif
 void NodeTraceWriter::FlushPrivate() {
   std::string str;
   int highest_request_id;
