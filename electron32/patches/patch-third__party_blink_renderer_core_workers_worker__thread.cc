$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/workers/worker_thread.cc.orig	2024-10-18 12:34:35.760020500 +0000
+++ third_party/blink/renderer/core/workers/worker_thread.cc
@@ -764,6 +764,12 @@ void WorkerThread::PrepareForShutdownOnW
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
 
