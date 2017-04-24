$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2017-04-19 03:59:21.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -259,6 +259,30 @@ void NativeProcessNetBSD::MonitorSIGTRAP
     }
     SetState(StateType::eStateStopped, true);
   } break;
+  case TRAP_LWP: {
+    ptrace_state_t state;
+    Error error =
+        PtraceWrapper(PT_GET_PROCESS_STATE, GetID(), &state, sizeof(state));
+    if (error.Fail()) {
+      LLDB_LOG(log,
+               "received error while checking process state, "
+               " pid = {0}, LWP = {1}, error = {2}",
+               GetID(), info.psi_lwpid, error);
+    }
+    switch (state.pe_report_event) {
+    case PTRACE_LWP_CREATE:
+      AddThread(state.pe_lwp);
+      break;
+    case PTRACE_LWP_EXIT:
+      error = RemoveThread(state.pe_lwp);
+      if (error.Fail()) {
+        LLDB_LOG(log, "received error while remiving thread: {0} ", error);
+      }
+      break;
+    default:
+      llvm_unreachable("Unexpected state");
+    };
+  } break;
   case TRAP_DBREG: {
     // If a watchpoint was hit, report it
     uint32_t wp_index;
@@ -812,6 +836,18 @@ Error NativeProcessNetBSD::LaunchInferio
     return error;
   }
 
+  error = SetDefaultPtraceOpts();
+  if (error.Fail()) {
+    LLDB_LOG(log, "failed to set default ptrace options: {0}", error);
+
+    // Mark the inferior as invalid.
+    // FIXME this could really use a new state - eStateLaunchFailure.  For now,
+    // using eStateInvalid.
+    SetState(StateType::eStateInvalid);
+
+    return error;
+  }
+
   for (const auto &thread_sp : m_threads) {
     static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(
         SIGSTOP);
@@ -898,6 +934,29 @@ void NativeProcessNetBSD::SigchldHandler
     MonitorCallback(wait_pid, signal);
 }
 
+Error NativeProcessNetBSD::RemoveThread(lldb::tid_t thread_id) {
+
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_THREAD));
+  LLDB_LOG(log, "pid {0} removing thread with tid {1}", GetID(), thread_id);
+
+  bool removed = false;
+  for (decltype(m_threads.size()) i = 0; i < m_threads.size(); i++) {
+    auto thread =
+        static_pointer_cast<NativeThreadNetBSD>(m_threads[i]);
+
+    if (thread->GetID() == thread_id) {
+      m_threads.erase(m_threads.begin() + i);
+      removed = true;
+      break;
+    }
+  }
+
+  if (!remove)
+    return Error("Attempt to remove invalid thread");
+
+  return Error();
+}
+
 NativeThreadNetBSDSP NativeProcessNetBSD::AddThread(lldb::tid_t thread_id) {
 
   Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_THREAD));
@@ -945,6 +1004,10 @@ NativeThreadNetBSDSP NativeProcessNetBSD
     return -1;
   }
 
+  error = SetDefaultPtraceOpts();
+  if (error.Fail())
+    return -1;
+
   for (const auto &thread_sp : m_threads) {
     static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(
         SIGSTOP);
@@ -1062,7 +1125,7 @@ Error NativeProcessNetBSD::ReinitializeT
   }
   // Reinitialize from scratch threads and register them in process
   while (info.pl_lwpid != 0) {
-    NativeThreadNetBSDSP thread_sp = AddThread(info.pl_lwpid);
+    AddThread(info.pl_lwpid);
     error = PtraceWrapper(PT_LWPINFO, GetID(), &info, sizeof(info));
     if (error.Fail()) {
       return error;
@@ -1071,3 +1134,13 @@ Error NativeProcessNetBSD::ReinitializeT
 
   return error;
 }
+
+Error NativeProcessNetBSD::SetDefaultPtraceOpts() {
+  ptrace_event_t event;
+
+  // Trace thread (LWP) creation and termination
+  // These events will trigger SIGTRAP with si_code TRAP_LWP
+  event.pe_set_event = PTRACE_LWP_CREATE | PTRACE_LWP_EXIT;
+
+  return PtraceWrapper(PT_SET_EVENT_MASK, GetID(), &event, sizeof(event));
+}
