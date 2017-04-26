$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2017-04-19 03:59:21.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -207,7 +207,8 @@ void NativeProcessNetBSD::MonitorSIGSTOP
     // Handle SIGSTOP from LLGS (LLDB GDB Server)
     if (info.psi_siginfo.si_code == SI_USER &&
         info.psi_siginfo.si_pid == ::getpid()) {
-      /* Stop Tracking All Threads attached to Process */
+      // Stop Tracking All Threads attached to Process
+      // SIGSTOP is always passed to all LWPs
       for (const auto &thread_sp : m_threads) {
         static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(
             SIGSTOP, &info.psi_siginfo);
@@ -229,21 +230,32 @@ void NativeProcessNetBSD::MonitorSIGTRAP
   }
 
   switch (info.psi_siginfo.si_code) {
-  case TRAP_BRKPT:
-    for (const auto &thread_sp : m_threads) {
-      static_pointer_cast<NativeThreadNetBSD>(thread_sp)
-          ->SetStoppedByBreakpoint();
-      FixupBreakpointPCAsNeeded(
-          *static_pointer_cast<NativeThreadNetBSD>(thread_sp));
+  case TRAP_BRKPT: {
+    size_t index;
+    Error error = GetThreadIndexByTid(info.psi_lwpid, index);
+    if (error.Fail()) {
+      LLDB_LOG(log, "failed to find thread by tid: {0}", error);
+      SetState(StateType::eStateInvalid);
+      return;
     }
+    static_pointer_cast<NativeThreadNetBSD>(m_threads[index])
+        ->SetStoppedByBreakpoint();
+    FixupBreakpointPCAsNeeded(
+        *static_pointer_cast<NativeThreadNetBSD>(m_threads[index]));
     SetState(StateType::eStateStopped, true);
-    break;
-  case TRAP_TRACE:
-    for (const auto &thread_sp : m_threads) {
-      static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedByTrace();
+  } break;
+  case TRAP_TRACE: {
+    size_t index;
+    Error error = GetThreadIndexByTid(info.psi_lwpid, index);
+    if (error.Fail()) {
+      LLDB_LOG(log, "failed to find thread by tid: {0}", error);
+      SetState(StateType::eStateInvalid);
+      return;
     }
+    static_pointer_cast<NativeThreadNetBSD>(m_threads[index])
+        ->SetStoppedByTrace();
     SetState(StateType::eStateStopped, true);
-    break;
+  } break;
   case TRAP_EXEC: {
     Error error = ReinitializeThreads();
     if (error.Fail()) {
@@ -254,11 +266,59 @@ void NativeProcessNetBSD::MonitorSIGTRAP
     // Let our delegate know we have just exec'd.
     NotifyDidExec();
 
-    for (const auto &thread_sp : m_threads) {
-      static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedByExec();
-    }
+    // There is only one thread
+    static_pointer_cast<NativeThreadNetBSD>(m_threads[0])->SetStoppedByExec();
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
+    case PTRACE_LWP_CREATE: {
+      auto thread = AddThread(state.pe_lwp);
+      switch (GetState()) {
+      case eStateRunning:
+        thread->SetRunning();
+        break;
+      case eStateStepping:
+        thread->SetStepping();
+        break;
+      default:
+        llvm_unreachable("Unexpected state");
+      }
+    } break;
+    case PTRACE_LWP_EXIT:
+      error = RemoveThread(state.pe_lwp);
+      if (error.Fail()) {
+        LLDB_LOG(log, "received error while remioving thread: {0} ", error);
+      }
+      break;
+    default:
+      llvm_unreachable("Unexpected state");
+    };
+    switch (GetState()) {
+    case eStateRunning:
+      error = NativeProcessNetBSD::PtraceWrapper(PT_CONTINUE, GetID(),
+                                                 (void *)1, 0);
+      break;
+    case eStateStepping:
+      error =
+          NativeProcessNetBSD::PtraceWrapper(PT_STEP, GetID(), (void *)1, 0);
+      break;
+    default:
+      llvm_unreachable("Unexpected state");
+    }
+    if (error.Fail()) {
+      LLDB_LOG(log, "received error while resuming process: {0} ", error);
+    }
+  } break;
   case TRAP_DBREG: {
     // If a watchpoint was hit, report it
     uint32_t wp_index;
@@ -267,16 +327,25 @@ void NativeProcessNetBSD::MonitorSIGTRAP
             ->GetRegisterContext()
             ->GetWatchpointHitIndex(wp_index,
                                     (uintptr_t)info.psi_siginfo.si_addr);
-    if (error.Fail())
+    if (error.Fail()) {
       LLDB_LOG(log,
                "received error while checking for watchpoint hits, pid = "
                "{0}, LWP = {1}, error = {2}",
                GetID(), info.psi_lwpid, error);
+      SetState(StateType::eStateInvalid);
+      return;
+    }
     if (wp_index != LLDB_INVALID_INDEX32) {
-      for (const auto &thread_sp : m_threads) {
-        static_pointer_cast<NativeThreadNetBSD>(thread_sp)
-            ->SetStoppedByWatchpoint(wp_index);
+      size_t index;
+      Error error = GetThreadIndexByTid(info.psi_lwpid, index);
+      if (error.Fail()) {
+        LLDB_LOG(log, "failed to find thread by tid: {0}", error);
+        SetState(StateType::eStateInvalid);
+        return;
       }
+      static_pointer_cast<NativeThreadNetBSD>(m_threads[index])
+          ->SetStoppedByWatchpoint(wp_index);
+
       SetState(StateType::eStateStopped, true);
       break;
     }
@@ -287,19 +356,33 @@ void NativeProcessNetBSD::MonitorSIGTRAP
                 ->GetRegisterContext()
                 ->GetHardwareBreakHitIndex(bp_index,
                                            (uintptr_t)info.psi_siginfo.si_addr);
-    if (error.Fail())
+    if (error.Fail()) {
       LLDB_LOG(log,
                "received error while checking for hardware "
                "breakpoint hits, pid = {0}, LWP = {1}, error = {2}",
                GetID(), info.psi_lwpid, error);
+      SetState(StateType::eStateInvalid);
+      return;
+    }
     if (bp_index != LLDB_INVALID_INDEX32) {
-      for (const auto &thread_sp : m_threads) {
-        static_pointer_cast<NativeThreadNetBSD>(thread_sp)
-            ->SetStoppedByBreakpoint();
+      size_t index;
+      Error error = GetThreadIndexByTid(info.psi_lwpid, index);
+      if (error.Fail()) {
+        LLDB_LOG(log, "failed to find thread by tid: {0}", error);
+        SetState(StateType::eStateInvalid);
+        return;
       }
+      static_pointer_cast<NativeThreadNetBSD>(m_threads[index])
+          ->SetStoppedByBreakpoint();
       SetState(StateType::eStateStopped, true);
       break;
     }
+
+    LLDB_LOG(log,
+             "received unknown hardware debug register trap, "
+             "pid = {0}, LWP = {1}",
+             GetID(), info.psi_lwpid);
+    SetState(StateType::eStateInvalid);
   } break;
   }
 }
@@ -311,10 +394,23 @@ void NativeProcessNetBSD::MonitorSignal(
   const auto siginfo_err =
       PtraceWrapper(PT_GET_SIGINFO, pid, &info, sizeof(info));
 
-  for (const auto &thread_sp : m_threads) {
-    static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(
-        info.psi_siginfo.si_signo, &info.psi_siginfo);
+  if (info.psi_lwpid == 0) {
+    for (const auto &thread_sp : m_threads) {
+      static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(
+          info.psi_siginfo.si_signo, &info.psi_siginfo);
+    }
+  } else {
+    size_t index;
+    Error error = GetThreadIndexByTid(info.psi_lwpid, index);
+    if (error.Fail()) {
+      LLDB_LOG(log, "failed to find thread by tid: {0}", error);
+      SetState(StateType::eStateInvalid);
+      return;
+    }
+    static_pointer_cast<NativeThreadNetBSD>(m_threads[index])
+        ->SetStoppedBySignal(info.psi_siginfo.si_signo, &info.psi_siginfo);
   }
+
   SetState(StateType::eStateStopped, true);
 }
 
@@ -444,55 +540,71 @@ Error NativeProcessNetBSD::Resume(const 
   Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
   LLDB_LOG(log, "pid {0}", GetID());
 
-  const auto &thread_sp = m_threads[0];
-  const ResumeAction *const action =
-      resume_actions.GetActionForThread(thread_sp->GetID(), true);
-
-  if (action == nullptr) {
-    LLDB_LOG(log, "no action specified for pid {0} tid {1}", GetID(),
-             thread_sp->GetID());
-    return Error();
-  }
+  int sig = 0;
+  bool step = false;
 
-  Error error;
+  for (auto thread_sp : m_threads) {
+    assert(thread_sp && "thread list should not contain NULL threads");
 
-  switch (action->state) {
-  case eStateRunning: {
-    // Run the thread, possibly feeding it the signal.
-    error = NativeProcessNetBSD::PtraceWrapper(PT_CONTINUE, GetID(), (void *)1,
-                                               action->signal);
-    if (!error.Success())
-      return error;
-    for (const auto &thread_sp : m_threads) {
+    const ResumeAction *const action =
+        resume_actions.GetActionForThread(thread_sp->GetID(), true);
+
+    if (action == nullptr) {
+      LLDB_LOG(log, "no action specified for pid {0} tid {1}", GetID(),
+               thread_sp->GetID());
+      continue;
+    }
+
+    LLDB_LOG(log, "processing resume action state {0} for pid {1} tid {2}",
+             action->state, GetID(), thread_sp->GetID());
+
+    sig = action->signal; // No support for several signals per LWP
+
+    switch (action->state) {
+    case eStateRunning: {
+      // Run the thread, possibly feeding it the signal.
+      Error error = NativeProcessNetBSD::PtraceWrapper(PT_CLEARSTEP, GetID(), 0,
+                                                       action->tid);
+      if (!error.Success())
+        return error;
       static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetRunning();
+    } break;
+    case eStateStepping: {
+      // Run the thread, possibly feeding it the signal.
+      Error error = NativeProcessNetBSD::PtraceWrapper(PT_SETSTEP, GetID(), 0,
+                                                       action->tid);
+      if (!error.Success())
+        return error;
+      static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStepping();
+      step = true;
+    } break;
+
+    case eStateSuspended:
+    case eStateStopped:
+      llvm_unreachable("Unexpected state");
+
+    default:
+      return Error("NativeProcessNetBSD::%s (): unexpected state %s specified "
+                   "for pid %" PRIu64 ", tid %" PRIu64,
+                   __FUNCTION__, StateAsCString(action->state), GetID(),
+                   thread_sp->GetID());
     }
-    SetState(eStateRunning, true);
-    break;
-  }
-  case eStateStepping:
-    // Run the thread, possibly feeding it the signal.
-    error = NativeProcessNetBSD::PtraceWrapper(PT_STEP, GetID(), (void *)1,
-                                               action->signal);
-    if (!error.Success())
+
+    Error error;
+
+    error = NativeProcessNetBSD::PtraceWrapper(PT_CONTINUE, GetID(), (void *)1,
+                                               sig);
+    if (error.Fail()) {
       return error;
-    for (const auto &thread_sp : m_threads) {
-      static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStepping();
     }
-    SetState(eStateStepping, true);
-    break;
 
-  case eStateSuspended:
-  case eStateStopped:
-    llvm_unreachable("Unexpected state");
+    if (step)
+      SetState(eStateStepping, true);
+    else
+      SetState(eStateRunning, true);
 
-  default:
-    return Error("NativeProcessNetBSD::%s (): unexpected state %s specified "
-                 "for pid %" PRIu64 ", tid %" PRIu64,
-                 __FUNCTION__, StateAsCString(action->state), GetID(),
-                 thread_sp->GetID());
+    return Error();
   }
-
-  return Error();
 }
 
 Error NativeProcessNetBSD::Halt() {
@@ -812,6 +924,18 @@ Error NativeProcessNetBSD::LaunchInferio
     return error;
   }
 
+  error = SetDefaultPtraceOpts();
+  if (error.Fail()) {
+    LLDB_LOG(log, "failed to set default ptrace options: {0}", error);
+
+    // Mark the inferior as invalid.
+    // FIXME this could really use a new state - eStateLaunchFailure.  For
+    // now, using eStateInvalid.
+    SetState(StateType::eStateInvalid);
+
+    return error;
+  }
+
   for (const auto &thread_sp : m_threads) {
     static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(
         SIGSTOP);
@@ -898,6 +1022,42 @@ void NativeProcessNetBSD::SigchldHandler
     MonitorCallback(wait_pid, signal);
 }
 
+Error NativeProcessNetBSD::GetThreadIndexByTid(lldb::tid_t thread_id,
+                                               size_t &index) {
+
+  assert(thread_id > 0);
+
+  bool removed = false;
+  for (decltype(m_threads.size()) i = 0; i < m_threads.size(); i++) {
+    auto thread = static_pointer_cast<NativeThreadNetBSD>(m_threads[i]);
+
+    if (thread->GetID() == thread_id) {
+      index = i;
+      return Error();
+    }
+  }
+
+  return Error("Thread not registered");
+}
+
+Error NativeProcessNetBSD::RemoveThread(lldb::tid_t thread_id) {
+
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_THREAD));
+  LLDB_LOG(log, "pid {0} removing thread with tid {1}", GetID(), thread_id);
+
+  size_t index;
+  Error error = GetThreadIndexByTid(thread_id, index);
+
+  if (error.Fail()) {
+    LLDB_LOG(log, "failed to find thread by tid: {0}", error);
+    return error;
+  }
+
+  m_threads.erase(m_threads.begin() + index);
+
+  return Error();
+}
+
 NativeThreadNetBSDSP NativeProcessNetBSD::AddThread(lldb::tid_t thread_id) {
 
   Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_THREAD));
@@ -912,6 +1072,7 @@ NativeThreadNetBSDSP NativeProcessNetBSD
 
   auto thread_sp = std::make_shared<NativeThreadNetBSD>(this, thread_id);
   m_threads.push_back(thread_sp);
+  printf("Added thread thread_id=%" PRIu64 "\n", thread_id);
   return thread_sp;
 }
 
@@ -945,6 +1106,10 @@ NativeThreadNetBSDSP NativeProcessNetBSD
     return -1;
   }
 
+  error = SetDefaultPtraceOpts();
+  if (error.Fail())
+    return -1;
+
   for (const auto &thread_sp : m_threads) {
     static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(
         SIGSTOP);
@@ -1062,7 +1227,7 @@ Error NativeProcessNetBSD::ReinitializeT
   }
   // Reinitialize from scratch threads and register them in process
   while (info.pl_lwpid != 0) {
-    NativeThreadNetBSDSP thread_sp = AddThread(info.pl_lwpid);
+    AddThread(info.pl_lwpid);
     error = PtraceWrapper(PT_LWPINFO, GetID(), &info, sizeof(info));
     if (error.Fail()) {
       return error;
@@ -1071,3 +1236,13 @@ Error NativeProcessNetBSD::ReinitializeT
 
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
