$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp.orig	2017-01-19 01:40:16.657343698 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp
@@ -0,0 +1,355 @@
+//===-- NativeThreadNetBSD.cpp --------------------------------- -*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#include "NativeThreadNetBSD.h"
+
+#include <signal.h>
+#include <sstream>
+
+#include "NativeProcessNetBSD.h"
+
+#include "lldb/Core/Log.h"
+#include "lldb/Core/State.h"
+#include "lldb/Host/HostNativeThread.h"
+#include "lldb/Utility/LLDBAssert.h"
+#include "lldb/lldb-enumerations.h"
+
+#include "llvm/ADT/SmallString.h"
+
+#include "Plugins/Process/POSIX/CrashReason.h"
+
+#include <sys/ptrace.h>
+#include <sys/syscall.h>
+#include <poll.h>
+
+using namespace lldb;
+using namespace lldb_private;
+using namespace lldb_private::process_netbsd;
+
+namespace {
+void LogThreadStopInfo(Log &log, const ThreadStopInfo &stop_info,
+                       const char *const header) {
+  switch (stop_info.reason) {
+  case eStopReasonNone:
+    log.Printf("%s: %s no stop reason", __FUNCTION__, header);
+    return;
+  case eStopReasonTrace:
+    log.Printf("%s: %s trace, stopping signal 0x%" PRIx32, __FUNCTION__, header,
+               stop_info.details.signal.signo);
+    return;
+  case eStopReasonBreakpoint:
+    log.Printf("%s: %s breakpoint, stopping signal 0x%" PRIx32, __FUNCTION__,
+               header, stop_info.details.signal.signo);
+    return;
+  case eStopReasonSignal:
+    log.Printf("%s: %s signal 0x%02" PRIx32, __FUNCTION__, header,
+               stop_info.details.signal.signo);
+    return;
+  case eStopReasonException:
+    log.Printf("%s: %s exception type 0x%02" PRIx64, __FUNCTION__, header,
+               stop_info.details.exception.type);
+    return;
+  case eStopReasonExec:
+    log.Printf("%s: %s exec, stopping signal 0x%" PRIx32, __FUNCTION__, header,
+               stop_info.details.signal.signo);
+    return;
+  case eStopReasonPlanComplete:
+    log.Printf("%s: %s plan complete", __FUNCTION__, header);
+    return;
+  case eStopReasonThreadExiting:
+    log.Printf("%s: %s thread exiting", __FUNCTION__, header);
+    return;
+  case eStopReasonInstrumentation:
+    log.Printf("%s: %s instrumentation", __FUNCTION__, header);
+    return;
+  default:
+    log.Printf("%s: %s invalid stop reason %" PRIu32, __FUNCTION__, header,
+               static_cast<uint32_t>(stop_info.reason));
+  }
+}
+}
+
+NativeThreadNetBSD::NativeThreadNetBSD(NativeProcessNetBSD *process,
+                                     lldb::tid_t tid)
+    : NativeThreadProtocol(process, tid), m_state(StateType::eStateInvalid),
+      m_stop_info(), m_reg_context_sp(), m_stop_description() {}
+
+std::string NativeThreadNetBSD::GetName() {
+  NativeProcessProtocolSP process_sp = m_process_wp.lock();
+  if (!process_sp)
+    return "<unknown: no process>";
+
+  // const NativeProcessNetBSD *const process =
+  // reinterpret_cast<NativeProcessNetBSD*> (process_sp->get ());
+  llvm::SmallString<32> thread_name;
+  HostNativeThread::GetName(GetID(), thread_name);
+  return thread_name.c_str();
+}
+
+lldb::StateType NativeThreadNetBSD::GetState() { return m_state; }
+
+bool NativeThreadNetBSD::GetStopReason(ThreadStopInfo &stop_info,
+                                      std::string &description) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_THREAD));
+
+  description.clear();
+
+  switch (m_state) {
+  case eStateStopped:
+  case eStateCrashed:
+  case eStateExited:
+  case eStateSuspended:
+  case eStateUnloaded:
+    if (log)
+      LogThreadStopInfo(*log, m_stop_info, "m_stop_info in thread:");
+    stop_info = m_stop_info;
+    description = m_stop_description;
+    if (log)
+      LogThreadStopInfo(*log, stop_info, "returned stop_info:");
+
+    return true;
+
+  case eStateInvalid:
+  case eStateConnected:
+  case eStateAttaching:
+  case eStateLaunching:
+  case eStateRunning:
+  case eStateStepping:
+  case eStateDetached:
+    if (log) {
+      log->Printf("NativeThreadNetBSD::%s tid %" PRIu64
+                  " in state %s cannot answer stop reason",
+                  __FUNCTION__, GetID(), StateAsCString(m_state));
+    }
+    return false;
+  }
+  llvm_unreachable("unhandled StateType!");
+}
+
+NativeRegisterContextSP NativeThreadNetBSD::GetRegisterContext() {
+  return m_reg_context_sp; /* XXX: dummy */
+}
+
+Error NativeThreadNetBSD::SetWatchpoint(lldb::addr_t addr, size_t size,
+                                       uint32_t watch_flags, bool hardware) {
+  return Error();
+}
+
+Error NativeThreadNetBSD::RemoveWatchpoint(lldb::addr_t addr) {
+  return Error();
+}
+
+Error NativeThreadNetBSD::SingleStep(uint32_t signo) {
+  const StateType new_state = StateType::eStateStepping;
+  m_state = new_state;
+  m_stop_info.reason = StopReason::eStopReasonNone;
+
+  intptr_t data = 0;
+  if (signo != LLDB_INVALID_SIGNAL_NUMBER)
+    data = signo;
+
+  return NativeProcessNetBSD::PtraceWrapper(PT_STEP, GetID(), (void *)1, data);
+}
+
+void NativeThreadNetBSD::SetStoppedBySignal(uint32_t signo,
+                                            const siginfo_t *info) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_THREAD));
+  if (log)
+    log->Printf("NativeThreadNetBSD::%s called with signal %s (value 0x%02" PRIx32 ")",
+                __FUNCTION__, strsignal(signo), signo);
+
+  m_state = eStateStopped;
+
+  m_stop_info.reason = StopReason::eStopReasonSignal;
+  m_stop_info.details.signal.signo = signo;
+
+  std::ostringstream stringStream;
+
+  if (!info) {
+    stringStream << "The signal " << strsignal(signo) << " was caught";
+    m_stop_description = stringStream.str();
+    return;
+  }
+
+  switch(info->si_code) {
+  case SI_USER:
+    stringStream << "The signal was generated via kill(2) from pid="
+                 << info->si_pid << ", uid=" << info->si_uid;
+    break;
+  case SI_QUEUE:
+    stringStream << "The signal was generated via sigqueue(2)";
+    break;
+  case SI_TIMER:
+    stringStream << "The signal was generated because a timer set by timer_settime(2) has expired"
+                 << " with si_value set to sival_int=" << info->si_value.sival_int << " and "
+                 << "sival_ptr=" << info->si_value.sival_ptr;
+    break;
+  case SI_ASYNCIO:
+    stringStream << "The signal was generated by completion of an asynchronous I/O operation with "
+                 << info->si_fd << " file descriptor number on which the operation was completed "
+                 << " and side and priority of the operation set to ";
+    switch (info->si_band) {
+    case POLLIN | POLLRDNORM:
+      stringStream << "normal read ";
+      break;
+    case POLLPRI | POLLRDNORM:
+      stringStream << "out-of-band read ";
+      break;
+    case POLLOUT | POLLWRNORM:
+      stringStream << "normal write ";
+      break;
+    case POLLPRI | POLLWRBAND:
+      stringStream << "normal write ";
+      break;
+    default:
+      stringStream << "unspecified value ";
+    }
+    stringStream << std::hex << std::showbase << info->si_band;
+  case SI_MESGQ:
+    stringStream << "The signal was generated by arrival of a message on an empty message queue "
+                 << "with si_value set to sival_int=" << info->si_value.sival_int << " and "
+                 << "sival_ptr=" << info->si_value.sival_ptr;
+  case SI_LWP:
+    stringStream << "The signal was generated via _lwp_kill(2) from pid="
+                 << info->si_pid << ", uid=" << info->si_uid;
+    break;
+  case SI_NOINFO:
+    stringStream << "There is no signal specific info available";
+    break;
+  default:
+    switch (info->si_signo) {
+    case SIGTRAP:
+      stringStream << "SIGTRAP has been caught with ";
+      switch (info->si_code) {
+      case TRAP_BRKPT:
+        stringStream << "Process Breakpoint type";
+        break;
+      case TRAP_TRACE:
+        stringStream << "Process Trace Trap type";
+        break;
+      default:
+        stringStream << "unknown si_code value " << std::hex << std::showbase
+                     << info->si_code;
+      }
+      break;
+    case SIGCHLD:
+      stringStream << "SIGCHLD has been caught with ";
+      switch (info->si_code) {
+      case CLD_EXITED:
+        stringStream << "Child Has Exited type";
+        break;
+      case CLD_KILLED:
+        stringStream << "Child Has Terminated Abnormally "
+                        "(without a core file) type";
+        break;
+      case CLD_DUMPED:
+        stringStream << "Child Has Terminated Abnormally "
+                     << "(with a core file) type";
+        break;
+      case CLD_TRAPPED:
+        stringStream << "Child Has Trapped type";
+        break;
+      case CLD_STOPPED:
+        stringStream << "Child Has Stopped type";
+        break;
+      case CLD_CONTINUED:
+        stringStream << "Child Has Continued type";
+        break;
+      default:
+        stringStream << "unknown si_code value " << std::hex << std::showbase
+                     << info->si_code;
+      }
+      stringStream << "with pid=" << std::dec << info->si_pid << " of the process who's status "
+                   << "changed, user id=" << info->si_uid << " of that process, "
+                   << std::hex << std::showbase << ((info->si_code == CLD_EXITED) ?
+                   "exit code of the process " : "signal number received by the process ")
+                   << std::dec << info->si_status << ", user process accounting time "
+                   << info->si_utime << ", system process accounting time " << info->si_stime;
+      break;
+    case SIGIO:
+      stringStream << "SIGIO has been caught with ";
+      switch (info->si_code) {
+      case POLL_IN:
+        stringStream << "Data Input Available type";
+        break;
+      case POLL_OUT:
+        stringStream << "Output Buffers Available type";
+        break;
+      case POLL_MSG:
+        stringStream << "Input Message type";
+        break;
+      case POLL_ERR:
+        stringStream << "I/O Error type";
+        break;
+      case POLL_PRI:
+        stringStream << "High Priority Input Available type";
+        break;
+      case POLL_HUP:
+        stringStream << "Device Disconnected type";
+        break;
+      default:
+        stringStream << "unknown si_code value " << std::hex << std::showbase
+                     << info->si_code;
+      }
+      stringStream << "with " << std::dec << info->si_fd << " file descriptor number on which the "
+                   << "operation was completed and side and priority of the operation set to ";
+      switch (info->si_band) {
+      case POLLIN | POLLRDNORM:
+        stringStream << "normal read ";
+        break;
+      case POLLPRI | POLLRDNORM:
+        stringStream << "out-of-band read ";
+        break;
+      case POLLOUT | POLLWRNORM:
+        stringStream << "normal write ";
+        break;
+      case POLLPRI | POLLWRBAND:
+        stringStream << "normal write ";
+        break;
+      default:
+        stringStream << "unspecified value ";
+      }
+      stringStream << std::hex << std::showbase << info->si_band;
+
+      break;
+    /* The following signals are defined by POSIX common platform code */
+    case SIGSEGV:
+    case SIGBUS:
+    case SIGFPE:
+    case SIGILL:
+      stringStream << GetCrashReasonString(GetCrashReason(*info), *info);
+      break;
+    default:
+      stringStream << "The signal " << strsignal(info->si_signo) << " was caught";
+    }
+  }
+  m_stop_description = stringStream.str();
+}
+
+void NativeThreadNetBSD::SetStopped() {
+  const StateType new_state = StateType::eStateStopped;
+  m_state = new_state;
+  m_stop_description.clear();
+}
+
+void NativeThreadNetBSD::SetStoppedByExec() {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_THREAD));
+  if (log)
+    log->Printf("NativeThreadNetBSD::%s()", __FUNCTION__);
+  SetStopped();
+  m_stop_info.reason = StopReason::eStopReasonExec;
+  m_stop_info.details.signal.signo = SIGTRAP;
+}
+
+NativeProcessNetBSD &NativeThreadNetBSD::GetProcess() {
+  auto process_sp = std::static_pointer_cast<NativeProcessNetBSD>(
+      NativeThreadProtocol::GetProcess());
+  assert(process_sp);
+  return *process_sp;
+}
