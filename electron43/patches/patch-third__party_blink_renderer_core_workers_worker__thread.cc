$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/workers/worker_thread.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/workers/worker_thread.cc
@@ -762,6 +762,12 @@ void WorkerThread::PrepareForShutdownOnW
   }
   pause_handle_.reset();
 
+  {
+    v8::HandleScope handle_scope(GetIsolate());
+    Platform::Current()->WorkerContextWillDestroy(
+        GlobalScope()->ScriptController()->GetContext());
+  }
+
   if (WorkerThreadDebugger* debugger = WorkerThreadDebugger::From(GetIsolate()))
     debugger->WorkerThreadDestroyed(this);
 
