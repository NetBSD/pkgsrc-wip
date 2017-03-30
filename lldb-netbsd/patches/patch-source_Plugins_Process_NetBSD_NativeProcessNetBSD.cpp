$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2017-03-29 00:14:15.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -235,6 +235,24 @@ void NativeProcessNetBSD::MonitorSIGTRAP
       }
       SetState(StateType::eStateStopped, true);
       break;
+    case TRAP_TRACE:
+      for (const auto &thread_sp : m_threads) {
+        static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedByTrace();
+      }
+      SetState(StateType::eStateStopped, true);
+      break;
+    case TRAP_EXEC: {
+      Error error = ReinitializeThreads();
+      if (error.Fail()) {
+        SetState(StateType::eStateInvalid);
+        return;
+      }
+
+      // Let our delegate know we have just exec'd.
+      NotifyDidExec();
+
+      SetState(StateType::eStateStopped, true);
+    } break;
     }
   }
 }
@@ -389,11 +407,13 @@ Error NativeProcessNetBSD::Resume(const 
     return Error();
   }
 
+  Error error;
+
   switch (action->state) {
   case eStateRunning: {
     // Run the thread, possibly feeding it the signal.
-    Error error = NativeProcessNetBSD::PtraceWrapper(PT_CONTINUE, GetID(),
-                                                     (void *)1, action->signal);
+    error = NativeProcessNetBSD::PtraceWrapper(PT_CONTINUE, GetID(), (void *)1,
+                                               action->signal);
     if (!error.Success())
       return error;
     for (const auto &thread_sp : m_threads) {
@@ -403,7 +423,15 @@ Error NativeProcessNetBSD::Resume(const 
     break;
   }
   case eStateStepping:
-    return Error("Not implemented");
+    // Run the thread, possibly feeding it the signal.
+    error = NativeProcessNetBSD::PtraceWrapper(PT_STEP, GetID(), (void *)1,
+                                               action->signal);
+    if (!error.Success())
+      return error;
+    for (const auto &thread_sp : m_threads) {
+      static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStepping();
+    }
+    SetState(eStateStepping, true);
     break;
 
   case eStateSuspended:
@@ -732,22 +760,11 @@ Error NativeProcessNetBSD::LaunchInferio
 
   ResolveProcessArchitecture(m_pid, m_arch);
 
-  /* Initialize threads */
-  struct ptrace_lwpinfo info = {};
-  error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
+  error = ReinitializeThreads();
   if (error.Fail()) {
     SetState(StateType::eStateInvalid);
     return error;
   }
-  while (info.pl_lwpid != 0) {
-    NativeThreadNetBSDSP thread_sp = AddThread(info.pl_lwpid);
-    thread_sp->SetStoppedBySignal(SIGSTOP);
-    error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
-    if (error.Fail()) {
-      SetState(StateType::eStateInvalid);
-      return error;
-    }
-  }
 
   /* Set process stopped */
   SetState(StateType::eStateStopped);
@@ -850,9 +867,6 @@ NativeThreadNetBSDSP NativeProcessNetBSD
 ::pid_t NativeProcessNetBSD::Attach(lldb::pid_t pid, Error &error) {
   Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
 
-  // Use a map to keep track of the threads which we have attached/need to
-  // attach.
-  Host::TidMap tids_to_attach;
   if (pid <= 1) {
     error.SetErrorToGenericError();
     error.SetErrorString("Attaching to process 1 is not allowed.");
@@ -874,21 +888,11 @@ NativeThreadNetBSDSP NativeProcessNetBSD
   m_pid = pid;
 
   /* Initialize threads */
-  struct ptrace_lwpinfo info = {};
-  error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
+  error = ReinitializeThreads();
   if (error.Fail()) {
     SetState(StateType::eStateInvalid);
     return -1;
   }
-  while (info.pl_lwpid != 0) {
-    NativeThreadNetBSDSP thread_sp = AddThread(info.pl_lwpid);
-    thread_sp->SetStoppedBySignal(SIGSTOP);
-    error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
-    if (error.Fail()) {
-      SetState(StateType::eStateInvalid);
-      return -1;
-    }
-  }
 
   // Let our process instance know the thread has stopped.
   SetState(StateType::eStateStopped);
@@ -989,3 +993,26 @@ NativeProcessNetBSD::GetAuxvData() const
 
   return buf;
 }
+
+Error NativeProcessNetBSD::ReinitializeThreads() {
+  // Clear old threads
+  m_threads.clear();
+
+  // Initialize new thread
+  struct ptrace_lwpinfo info = {};
+  Error error = PtraceWrapper(PT_LWPINFO, GetID(), &info, sizeof(info));
+  if (error.Fail()) {
+    return error;
+  }
+  // Reinitialize from scratch threads and register them in process
+  while (info.pl_lwpid != 0) {
+    NativeThreadNetBSDSP thread_sp = AddThread(info.pl_lwpid);
+    thread_sp->SetStoppedByExec();
+    error = PtraceWrapper(PT_LWPINFO, GetID(), &info, sizeof(info));
+    if (error.Fail()) {
+      return error;
+    }
+  }
+
+  return error;
+}
