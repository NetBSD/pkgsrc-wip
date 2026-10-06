$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/tracing/node_trace_writer.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/tracing/node_trace_writer.h
@@ -20,7 +20,9 @@ class NodeTraceWriter : public AsyncTrac
   ~NodeTraceWriter() override;
 
   void InitializeOnThread(uv_loop_t* loop) override;
+#ifndef V8_USE_PERFETTO
   void AppendTraceEvent(TraceObject* trace_event) override;
+#endif
   void Flush(bool blocking) override;
 
   static const int kTracesPerFile = 1 << 19;
