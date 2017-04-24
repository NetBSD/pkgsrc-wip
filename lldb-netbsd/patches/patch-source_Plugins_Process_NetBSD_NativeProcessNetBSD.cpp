$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2017-04-19 03:59:21.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -778,6 +778,17 @@ Error NativeProcessNetBSD::LaunchInferio
          "Could not sync with inferior process.");
 
   LLDB_LOG(log, "inferior started, now in stopped state");
+  error = SetDefaultPtraceOpts(pid);
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
 
   // Release the master terminal descriptor and pass it off to the
   // NativeProcessNetBSD instance.  Similarly stash the inferior pid.
@@ -945,6 +956,10 @@ NativeThreadNetBSDSP NativeProcessNetBSD
     return -1;
   }
 
+  error = SetDefaultPtraceOpts(tid);
+  if (error.Fail())
+    return -1;
+
   for (const auto &thread_sp : m_threads) {
     static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(
         SIGSTOP);
@@ -1071,3 +1086,13 @@ Error NativeProcessNetBSD::ReinitializeT
 
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
