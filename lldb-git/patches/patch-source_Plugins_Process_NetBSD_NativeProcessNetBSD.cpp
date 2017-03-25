$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2017-03-21 17:54:57.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -14,18 +14,49 @@
 // C++ Includes
 
 // Other libraries and framework includes
-
 #include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
+#include "lldb/Host/common/NativeBreakpoint.h"
+#include "lldb/Host/common/NativeRegisterContext.h"
+#include "lldb/Target/Process.h"
 
 // System includes - They have to be included after framework includes because
 // they define some
 // macros which collide with variable names in other modules
+#include <sys/types.h>
+#include <sys/ptrace.h>
+#include <sys/wait.h>
 
 using namespace lldb;
 using namespace lldb_private;
 using namespace lldb_private::process_netbsd;
 using namespace llvm;
 
+static ExitType convert_pid_status_to_exit_type(int status) {
+  if (WIFEXITED(status))
+    return ExitType::eExitTypeExit;
+  else if (WIFSIGNALED(status))
+    return ExitType::eExitTypeSignal;
+  else if (WIFSTOPPED(status))
+    return ExitType::eExitTypeStop;
+  else {
+    // We don't know what this is.
+    return ExitType::eExitTypeInvalid;
+  }
+}
+
+static int convert_pid_status_to_return_code(int status) {
+  if (WIFEXITED(status))
+    return WEXITSTATUS(status);
+  else if (WIFSIGNALED(status))
+    return WTERMSIG(status);
+  else if (WIFSTOPPED(status))
+    return WSTOPSIG(status);
+  else {
+    // We don't know what this is.
+    return ExitType::eExitTypeInvalid;
+  }
+}
+
 // -----------------------------------------------------------------------------
 // Public Static Methods
 // -----------------------------------------------------------------------------
@@ -48,4 +79,215 @@ Error NativeProcessProtocol::Attach(
 // -----------------------------------------------------------------------------
 
 NativeProcessNetBSD::NativeProcessNetBSD()
-    : NativeProcessProtocol(LLDB_INVALID_PROCESS_ID) {}
+    : NativeProcessProtocol(LLDB_INVALID_PROCESS_ID), m_arch() {}
+
+// Handles all waitpid events from the inferior process.
+void NativeProcessNetBSD::MonitorCallback(lldb::pid_t pid, int signal) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
+
+  switch (signal) {
+  case SIGTRAP:
+    return MonitorSIGTRAP(pid);
+  case SIGSTOP:
+    return MonitorSIGSTOP(pid);
+  default:
+    return MonitorSignal(pid, signal);
+  }
+}
+
+void NativeProcessNetBSD::MonitorExited(lldb::pid_t pid, int signal,
+                                        int status) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
+
+  LLDB_LOG(log, "got exit signal({0}) , pid = {1}", signal, pid);
+
+  /* Stop Tracking All Threads attached to Process */
+  m_threads.clear();
+
+  SetExitStatus(convert_pid_status_to_exit_type(status),
+                convert_pid_status_to_return_code(status), nullptr, true);
+
+  // Notify delegate that our process has exited.
+  SetState(StateType::eStateExited, true);
+}
+
+void NativeProcessNetBSD::MonitorSIGSTOP(lldb::pid_t pid) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
+  ptrace_siginfo_t info;
+
+  const auto siginfo_err =
+      PtraceWrapper(PT_GET_SIGINFO, pid, &info, sizeof(info));
+
+  // Get details on the signal raised.
+  if (siginfo_err.Success()) {
+    // Handle SIGSTOP from LLGS (LLDB GDB Server)
+    if (info.psi_siginfo.si_code == SI_USER &&
+        info.psi_siginfo.si_pid == ::getpid()) {
+      /* Stop Tracking All Threads attached to Process */
+      for (const auto &thread_sp : m_threads) {
+        static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(
+            SIGSTOP, &info.psi_siginfo);
+      }
+    }
+  }
+}
+
+void NativeProcessNetBSD::MonitorSIGTRAP(lldb::pid_t pid) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
+  ptrace_siginfo_t info;
+
+  const auto siginfo_err =
+      PtraceWrapper(PT_GET_SIGINFO, pid, &info, sizeof(info));
+
+  // Get details on the signal raised.
+  if (siginfo_err.Success()) {
+    switch (info.psi_siginfo.si_code) {
+    case TRAP_BRKPT:
+      for (const auto &thread_sp : m_threads) {
+        static_pointer_cast<NativeThreadNetBSD>(thread_sp)
+            ->SetStoppedByBreakpoint();
+        FixupBreakpointPCAsNeeded(
+            *static_pointer_cast<NativeThreadNetBSD>(thread_sp));
+      }
+      SetState(StateType::eStateStopped, true);
+      break;
+    }
+  }
+}
+
+void NativeProcessNetBSD::MonitorSignal(lldb::pid_t pid, int signal) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
+
+  ptrace_siginfo_t info;
+  const auto siginfo_err =
+      PtraceWrapper(PT_GET_SIGINFO, pid, &info, sizeof(info));
+
+  for (const auto &thread_sp : m_threads) {
+    static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(
+        info.psi_siginfo.si_signo, &info.psi_siginfo);
+  }
+  SetState(StateType::eStateStopped, true);
+}
+
+Error NativeProcessNetBSD::PtraceWrapper(int req, lldb::pid_t pid, void *addr,
+                                         int data, int *result) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PTRACE));
+  Error error;
+  int ret;
+
+  errno = 0;
+  ret = ptrace(req, static_cast<::pid_t>(pid), addr, data);
+
+  if (ret == -1)
+    error.SetErrorToErrno();
+
+  if (result)
+    *result = ret;
+
+  LLDB_LOG(log, "ptrace({0}, {1}, {2}, {3}, {4})={6:x}", req, pid, addr, data,
+           ret);
+
+  if (error.Fail())
+    LLDB_LOG(log, "ptrace() failed: {0}", error);
+
+  return error;
+}
+
+Error NativeProcessNetBSD::GetSoftwareBreakpointPCOffset(
+    uint32_t &actual_opcode_size) {
+  // FIXME put this behind a breakpoint protocol class that can be
+  // set per architecture.  Need ARM, MIPS support here.
+  static const uint8_t g_i386_opcode[] = {0xCC};
+  switch (m_arch.GetMachine()) {
+  case llvm::Triple::x86_64:
+    actual_opcode_size = static_cast<uint32_t>(sizeof(g_i386_opcode));
+    return Error();
+  default:
+    assert(false && "CPU type not supported!");
+    return Error("CPU type not supported");
+  }
+}
+
+Error NativeProcessNetBSD::FixupBreakpointPCAsNeeded(
+    NativeThreadNetBSD &thread) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_BREAKPOINTS));
+  Error error;
+  // Find out the size of a breakpoint (might depend on where we are in the
+  // code).
+  NativeRegisterContextSP context_sp = thread.GetRegisterContext();
+  if (!context_sp) {
+    error.SetErrorString("cannot get a NativeRegisterContext for the thread");
+    LLDB_LOG(log, "failed: {0}", error);
+    return error;
+  }
+  uint32_t breakpoint_size = 0;
+  error = GetSoftwareBreakpointPCOffset(breakpoint_size);
+  if (error.Fail()) {
+    LLDB_LOG(log, "GetBreakpointSize() failed: {0}", error);
+    return error;
+  } else
+    LLDB_LOG(log, "breakpoint size: {0}", breakpoint_size);
+  // First try probing for a breakpoint at a software breakpoint location: PC -
+  // breakpoint size.
+  const lldb::addr_t initial_pc_addr =
+      context_sp->GetPCfromBreakpointLocation();
+  lldb::addr_t breakpoint_addr = initial_pc_addr;
+  if (breakpoint_size > 0) {
+    // Do not allow breakpoint probe to wrap around.
+    if (breakpoint_addr >= breakpoint_size)
+      breakpoint_addr -= breakpoint_size;
+  }
+  // Check if we stopped because of a breakpoint.
+  NativeBreakpointSP breakpoint_sp;
+  error = m_breakpoint_list.GetBreakpoint(breakpoint_addr, breakpoint_sp);
+  if (!error.Success() || !breakpoint_sp) {
+    // We didn't find one at a software probe location.  Nothing to do.
+    LLDB_LOG(log,
+             "pid {0} no lldb breakpoint found at current pc with "
+             "adjustment: {1}",
+             GetID(), breakpoint_addr);
+    return Error();
+  }
+  // If the breakpoint is not a software breakpoint, nothing to do.
+  if (!breakpoint_sp->IsSoftwareBreakpoint()) {
+    LLDB_LOG(
+        log,
+        "pid {0} breakpoint found at {1:x}, not software, nothing to adjust",
+        GetID(), breakpoint_addr);
+    return Error();
+  }
+  //
+  // We have a software breakpoint and need to adjust the PC.
+  //
+  // Sanity check.
+  if (breakpoint_size == 0) {
+    // Nothing to do!  How did we get here?
+    LLDB_LOG(log,
+             "pid {0} breakpoint found at {1:x}, it is software, but the "
+             "size is zero, nothing to do (unexpected)",
+             GetID(), breakpoint_addr);
+    return Error();
+  }
+  //
+  // We have a software breakpoint and need to adjust the PC.
+  //
+  // Sanity check.
+  if (breakpoint_size == 0) {
+    // Nothing to do!  How did we get here?
+    LLDB_LOG(log,
+             "pid {0} breakpoint found at {1:x}, it is software, but the "
+             "size is zero, nothing to do (unexpected)",
+             GetID(), breakpoint_addr);
+    return Error();
+  }
+  // Change the program counter.
+  LLDB_LOG(log, "pid {0} tid {1}: changing PC from {2:x} to {3:x}", GetID(),
+           thread.GetID(), initial_pc_addr, breakpoint_addr);
+  error = context_sp->SetPC(breakpoint_addr);
+  if (error.Fail()) {
+    LLDB_LOG(log, "pid {0} tid {1}: failed to set PC: {2}", GetID(),
+             thread.GetID(), error);
+    return error;
+  }
+  return error;
+}
