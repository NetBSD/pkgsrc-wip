$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2017-03-21 17:54:57.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -11,6 +11,7 @@
 
 // C Includes
 
+
 // C++ Includes
 
 // Other libraries and framework includes
@@ -20,6 +21,8 @@
 // System includes - They have to be included after framework includes because
 // they define some
 // macros which collide with variable names in other modules
+#include <sys/types.h>
+#include <sys/ptrace.h>
 
 using namespace lldb;
 using namespace lldb_private;
@@ -49,3 +52,155 @@ Error NativeProcessProtocol::Attach(
 
 NativeProcessNetBSD::NativeProcessNetBSD()
     : NativeProcessProtocol(LLDB_INVALID_PROCESS_ID) {}
+
+// Handles all waitpid events from the inferior process.
+void NativeProcessNetBSD::MonitorCallback(lldb::pid_t pid,
+                                         int signal) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
+
+  ptrace_siginfo_t info;
+  const auto siginfo_err = PtraceWrapper(PT_GET_SIGINFO, pid, &info, sizeof(info));
+    
+  ptrace_state_t state;
+  const auto state_err = PtraceWrapper(PT_GET_PROCESS_STATE, pid, &state, sizeof(state));
+    
+  printf("Signal received signo=%d errno=%d code=%d\n", info.psi_siginfo.si_signo,
+    info.psi_siginfo.si_errno, info.psi_siginfo.si_code); 
+                  
+  // Get details on the signal raised.
+  if (siginfo_err.Success() && state_err.Success()) {
+    switch (info.psi_siginfo.si_signo) {
+    case SIGTRAP:
+      switch (info.psi_siginfo.si_code) {
+      case TRAP_BRKPT:
+        for (const auto &thread_sp : m_threads) {                                                                                     
+          static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedByBreakpoint();
+          FixupBreakpointPCAsNeeded(*static_pointer_cast<NativeThreadNetBSD>(thread_sp));
+        }
+        SetState(StateType::eStateStopped, true);
+        break;
+      case TRAP_TRACE:
+        for (const auto &thread_sp : m_threads) {
+          static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedByTrace();
+        }
+        SetState(StateType::eStateStopped, true);
+        break;
+      case TRAP_EXEC:
+        {
+        // Clear old threads
+        m_threads.clear();
+                                                                                                                                      
+        // Initialize new thread
+        struct ptrace_lwpinfo info = {};
+        Error error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
+        if (error.Fail()) {
+          SetState(StateType::eStateInvalid);
+          return;
+        }
+
+        // Reinitialize from scratch threads and register them in process
+        while (info.pl_lwpid != 0) {
+          NativeThreadNetBSDSP thread_sp = AddThread(info.pl_lwpid);
+          thread_sp->SetStoppedByExec();
+          error = PtraceWrapper(PT_LWPINFO, pid, &info, sizeof(info));
+          if (error.Fail()) {
+            SetState(StateType::eStateInvalid);
+            return;                                                                                                                   
+          }
+        }
+
+
+    case SIGSTOP:
+      break;
+    default:
+      // Other signals
+#if 0
+      if (m_signals_to_ignore.find(signo) != m_signals_to_ignore.end()) {
+        ResumeThread(thread, thread.GetState(), signo);                                                                               
+        return;
+      }
+#endif
+
+      for (const auto &thread_sp : m_threads) {
+        static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(info.psi_siginfo.si_signo, &info.psi_siginfo);
+      }
+      SetState(StateType::eStateStopped, true);
+    }
+  }
+}
+
+void NativeProcessNetBSD::MonitorExited(lldb::pid_t pid, int signal, int status) {
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
+  const auto siginfo_err = PtraceWrapper(PT_GET_SIGINFO, pid, &info, sizeof(info));
+
+  // Get details on the signal raised.
+  if (siginfo_err.Success()) {
+    // Handle SIGSTOP from LLGS (LLDB GDB Server)
+    if (info.psi_siginfo.si_code == SI_USER && info.psi_siginfo.si_pid == ::getpid()) {
+      /* Stop Tracking All Threads attached to Process */
+      for (const auto &thread_sp : m_threads) {
+        static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedBySignal(SIGSTOP, &info.psi_siginfo);
+      }
+    }
+  }
+}
+
+void NativeProcessNetBSD::MonitorSIGTRAP(lldb::pid_t pid) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
+  ptrace_siginfo_t info;
+
+  const auto siginfo_err = PtraceWrapper(PT_GET_SIGINFO, pid, &info, sizeof(info));
+
+  // Get details on the signal raised.
+  if (siginfo_err.Success()) {
+    switch (info.psi_siginfo.si_code) {
+    case TRAP_BRKPT:
+      for (const auto &thread_sp : m_threads) {
+        static_pointer_cast<NativeThreadNetBSD>(thread_sp)->SetStoppedByBreakpoint();                                                                                                       
+        FixupBreakpointPCAsNeeded(*static_pointer_cast<NativeThreadNetBSD>(thread_sp));
+      }
+      SetState(StateType::eStateStopped, true);
+      break;
+  }
+}
+
+Error NativeProcessNetBSD::PtraceWrapper(int req, lldb::pid_t pid, void *addr,
+                                        int data, int *result) {
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
+  LLDB_LOG(log, "ptrace({0}, {1}, {2}, {3}, {4})={6:x}", req, pid, addr,
+           data, ret);
+
+  if (error.Fail())
+    LLDB_LOG(log, "ptrace() failed: {0}", error);
+
+  return error;
+}
