$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2017-03-30 22:14:30.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -224,36 +224,75 @@ void NativeProcessNetBSD::MonitorSIGTRAP
       PtraceWrapper(PT_GET_SIGINFO, pid, &info, sizeof(info));
 
   // Get details on the signal raised.
-  if (siginfo_err.Success()) {
-    switch (info.psi_siginfo.si_code) {
-    case TRAP_BRKPT:
+  if (siginfo_err.Fail()) {
+    return;
+  }
+
+  switch (info.psi_siginfo.si_code) {
+  case TRAP_BRKPT:
+    for (const auto &thread_sp : m_threads) {
+      static_pointer_cast<NativeThreadNetBSD>(thread_sp)
+          ->SetStoppedByBreakpoint();
+      FixupBreakpointPCAsNeeded(
+          *static_pointer_cast<NativeThreadNetBSD>(thread_sp));
+    }
+    SetState(StateType::eStateStopped, true);
+    break;
+  case TRAP_TRACE:
+    for (const auto &thread_sp : m_threads) {
+      static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedByTrace();
+    }
+    SetState(StateType::eStateStopped, true);
+    break;
+  case TRAP_EXEC: {
+    Error error = ReinitializeThreads();
+    if (error.Fail()) {
+      SetState(StateType::eStateInvalid);
+      return;
+    }
+
+    // Let our delegate know we have just exec'd.
+    NotifyDidExec();
+
+    SetState(StateType::eStateStopped, true);
+  } break;
+  case TRAP_DBREG: {
+    // If a watchpoint was hit, report it
+    uint32_t wp_index;
+    Error error = static_pointer_cast<NativeThreadNetBSD>(m_threads[info.psi_lwpid])->GetRegisterContext()->GetWatchpointHitIndex(
+        wp_index, (uintptr_t)info.psi_siginfo.si_addr);
+    if (error.Fail())
+      LLDB_LOG(log,
+               "received error while checking for watchpoint hits, pid = "
+               "{0}, LWP = {1}, error = {2}",
+               GetID(), info.psi_lwpid, error);
+    if (wp_index != LLDB_INVALID_INDEX32) {
       for (const auto &thread_sp : m_threads) {
         static_pointer_cast<NativeThreadNetBSD>(thread_sp)
-            ->SetStoppedByBreakpoint();
-        FixupBreakpointPCAsNeeded(
-            *static_pointer_cast<NativeThreadNetBSD>(thread_sp));
+          ->SetStoppedByWatchpoint(wp_index);
       }
       SetState(StateType::eStateStopped, true);
       break;
-    case TRAP_TRACE:
+    }
+
+    // If a breakpoint was hit, report it
+    uint32_t bp_index;
+    error = static_pointer_cast<NativeThreadNetBSD>(m_threads[info.psi_lwpid])->GetRegisterContext()->GetHardwareBreakHitIndex(
+        bp_index, (uintptr_t)info.psi_siginfo.si_addr);
+    if (error.Fail())
+      LLDB_LOG(log,
+               "received error while checking for hardware "
+               "breakpoint hits, pid = {0}, LWP = {1}, error = {2}",
+               GetID(), info.psi_lwpid, error);
+    if (bp_index != LLDB_INVALID_INDEX32) {
       for (const auto &thread_sp : m_threads) {
-        static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedByTrace();
+        static_pointer_cast<NativeThreadNetBSD>(thread_sp)
+            ->SetStoppedByBreakpoint();
       }
       SetState(StateType::eStateStopped, true);
       break;
-    case TRAP_EXEC: {
-      Error error = ReinitializeThreads();
-      if (error.Fail()) {
-        SetState(StateType::eStateInvalid);
-        return;
-      }
-
-      // Let our delegate know we have just exec'd.
-      NotifyDidExec();
-
-      SetState(StateType::eStateStopped, true);
-    } break;
     }
+  } break;
   }
 }
 
@@ -328,8 +367,8 @@ Error NativeProcessNetBSD::FixupBreakpoi
     return error;
   } else
     LLDB_LOG(log, "breakpoint size: {0}", breakpoint_size);
-  // First try probing for a breakpoint at a software breakpoint location: PC -
-  // breakpoint size.
+  // First try probing for a breakpoint at a software breakpoint location: PC
+  // - breakpoint size.
   const lldb::addr_t initial_pc_addr =
       context_sp->GetPCfromBreakpointLocation();
   lldb::addr_t breakpoint_addr = initial_pc_addr;
@@ -439,7 +478,7 @@ Error NativeProcessNetBSD::Resume(const 
     llvm_unreachable("Unexpected state");
 
   default:
-    return Error("NativeProcessLinux::%s (): unexpected state %s specified "
+    return Error("NativeProcessNetBSD::%s (): unexpected state %s specified "
                  "for pid %" PRIu64 ", tid %" PRIu64,
                  __FUNCTION__, StateAsCString(action->state), GetID(),
                  thread_sp->GetID());
@@ -540,8 +579,8 @@ Error NativeProcessNetBSD::GetMemoryRegi
            "descending memory map entries detected, unexpected");
     prev_base_address = proc_entry_info.GetRange().GetRangeBase();
     UNUSED_IF_ASSERT_DISABLED(prev_base_address);
-    // If the target address comes before this entry, indicate distance to next
-    // region.
+    // If the target address comes before this entry, indicate distance to
+    // next region.
     if (load_addr < proc_entry_info.GetRange().GetRangeBase()) {
       range_info.GetRange().SetRangeBase(load_addr);
       range_info.GetRange().SetByteSize(
@@ -561,9 +600,8 @@ Error NativeProcessNetBSD::GetMemoryRegi
   }
   // If we made it here, we didn't find an entry that contained the given
   // address. Return the
-  // load_addr as start and the amount of bytes betwwen load address and the end
-  // of the memory as
-  // size.
+  // load_addr as start and the amount of bytes betwwen load address and the
+  // end of the memory as size.
   range_info.GetRange().SetRangeBase(load_addr);
   range_info.GetRange().SetRangeEnd(LLDB_INVALID_ADDRESS);
   range_info.SetReadable(MemoryRegionInfo::OptionalBool::eNo);
@@ -722,8 +760,8 @@ Error NativeProcessNetBSD::LaunchInferio
     LLDB_LOG(log, "waitpid for inferior failed with %s", error);
 
     // Mark the inferior as invalid.
-    // FIXME this could really use a new state - eStateLaunchFailure.  For now,
-    // using eStateInvalid.
+    // FIXME this could really use a new state - eStateLaunchFailure.  For
+    // now, using eStateInvalid.
     SetState(StateType::eStateInvalid);
 
     return error;
