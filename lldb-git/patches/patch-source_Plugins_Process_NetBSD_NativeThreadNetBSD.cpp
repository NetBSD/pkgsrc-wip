$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp.orig	2017-03-21 17:54:57.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp
@@ -12,10 +12,145 @@
 
 #include "NativeProcessNetBSD.h"
 
+#include "Plugins/Process/POSIX/CrashReason.h"
+#include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
+#include "lldb/Core/RegisterValue.h"
+#include "lldb/Core/State.h"
+
 using namespace lldb;
 using namespace lldb_private;
 using namespace lldb_private::process_netbsd;
 
 NativeThreadNetBSD::NativeThreadNetBSD(NativeProcessNetBSD *process,
                                        lldb::tid_t tid)
-    : NativeThreadProtocol(process, tid) {}
+    : NativeThreadProtocol(process, tid), m_state(StateType::eStateInvalid),
+      m_stop_info(), m_reg_context_sp(), m_stop_description() {}
+
+void NativeThreadNetBSD::SetStoppedBySignal(uint32_t signo,
+                                            const siginfo_t *info) {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_THREAD));
+  if (log)
+    log->Printf("NativeThreadNetBSD::%s called with signal 0x%02" PRIx32,
+                __FUNCTION__, signo);
+
+  SetStopped();
+
+  m_stop_info.reason = StopReason::eStopReasonSignal;
+  m_stop_info.details.signal.signo = signo;
+
+  m_stop_description.clear();
+  if (info) {
+    switch (signo) {
+    case SIGSEGV:
+    case SIGBUS:
+    case SIGFPE:
+    case SIGILL:
+      const auto reason = GetCrashReason(*info);
+      m_stop_description = GetCrashReasonString(reason, *info);
+      break;
+    }
+  }
+}
+
+void NativeThreadNetBSD::SetStoppedByBreakpoint() {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_THREAD));
+  if (log)
+    log->Printf("NativeThreadNetBSD::%s()", __FUNCTION__);
+  SetStopped();
+  m_stop_info.reason = StopReason::eStopReasonBreakpoint;
+  m_stop_info.details.signal.signo = SIGTRAP;
+}
+
+void NativeThreadNetBSD::SetStopped() {
+  const StateType new_state = StateType::eStateStopped;
+  m_state = new_state;
+  m_stop_description.clear();
+}
+
+void NativeThreadNetBSD::SetRunning() {
+  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_THREAD));
+  if (log)
+    log->Printf("NativeThreadNetBSD::%s()", __FUNCTION__);
+
+  m_state = StateType::eStateRunning;
+  m_stop_info.reason = StopReason::eStopReasonNone;
+}
+
+std::string NativeThreadNetBSD::GetName() {
+  return std::string("");
+}
+
+lldb::StateType NativeThreadNetBSD::GetState() { return m_state; }
+
+bool NativeThreadNetBSD::GetStopReason(ThreadStopInfo &stop_info,
+                                       std::string &description) {
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
+    stop_info = m_stop_info;
+    description = m_stop_description;
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
+  // Return the register context if we already created it.
+  if (m_reg_context_sp)
+    return m_reg_context_sp;
+
+  NativeProcessProtocolSP m_process_sp = m_process_wp.lock();
+  if (!m_process_sp)
+    return NativeRegisterContextSP();
+
+  ArchSpec target_arch;
+  if (!m_process_sp->GetArchitecture(target_arch))
+    return NativeRegisterContextSP();
+
+  const uint32_t concrete_frame_idx = 0;
+  m_reg_context_sp.reset(
+      NativeRegisterContextNetBSD::CreateHostNativeRegisterContextNetBSD(
+          target_arch, *this, concrete_frame_idx));
+
+  return m_reg_context_sp;
+}
+
+Error NativeThreadNetBSD::SetWatchpoint(lldb::addr_t addr, size_t size,
+                                        uint32_t watch_flags, bool hardware) {
+  return Error();
+}
+
+Error NativeThreadNetBSD::RemoveWatchpoint(lldb::addr_t addr) {
+  return Error();
+}
+
+Error NativeThreadNetBSD::SetHardwareBreakpoint(lldb::addr_t addr,
+                                                size_t size) {
+  return Error();
+}
+
+Error NativeThreadNetBSD::RemoveHardwareBreakpoint(lldb::addr_t addr) {
+  return Error();
+}
