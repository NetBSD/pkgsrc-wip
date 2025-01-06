$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/tracing/node_trace_buffer.cc.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/src/tracing/node_trace_buffer.cc
@@ -55,6 +55,7 @@ TraceObject* InternalTraceBuffer::GetEve
 }
 
 void InternalTraceBuffer::Flush(bool blocking) {
+#ifndef V8_USE_PERFETTO
   {
     Mutex::ScopedLock scoped_lock(mutex_);
     if (total_chunks_ > 0) {
@@ -75,6 +76,7 @@ void InternalTraceBuffer::Flush(bool blo
       flushing_ = false;
     }
   }
+#endif
   agent_->Flush(blocking);
 }
 
