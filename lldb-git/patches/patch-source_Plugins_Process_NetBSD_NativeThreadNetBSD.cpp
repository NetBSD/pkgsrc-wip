$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp.orig	2017-03-20 16:13:14.305070457 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp
@@ -0,0 +1,97 @@
+//===-- NativeThreadNetBSD.cpp -------------------------------- -*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#include "NativeThreadNetBSD.h"
+#include "NativeRegisterContextNetBSD.h"
+
+#include "NativeProcessNetBSD.h"
+
+using namespace lldb;
+using namespace lldb_private;
+using namespace lldb_private::process_netbsd;
+
+namespace {
+void LogThreadStopInfo(Log &log, const ThreadStopInfo &stop_info,
+                       const char *const header) {}
+} // namespace
+
+NativeThreadNetBSD::NativeThreadNetBSD(NativeProcessNetBSD *process,
+                                       lldb::tid_t tid)
+    : NativeThreadProtocol(process, tid), m_state(StateType::eStateInvalid),
+      m_stop_info(), m_reg_context_sp(), m_stop_description() {}
+
+std::string NativeThreadNetBSD::GetName() { return std::string(); }
+
+lldb::StateType NativeThreadNetBSD::GetState() { return m_state; }
+
+bool NativeThreadNetBSD::GetStopReason(ThreadStopInfo &stop_info,
+                                       std::string &description) {
+  return false;
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
+void NativeThreadNetBSD::SetStoppedBySignal(uint32_t signo,
+                                            const siginfo_t *info) {}
+
+void NativeThreadNetBSD::SetStopped() {}
+
+void NativeThreadNetBSD::SetStoppedByExec() {}
+
+void NativeThreadNetBSD::SetRunning() {}
+
+void NativeThreadNetBSD::SetStepping() {}
+
+void NativeThreadNetBSD::SetStoppedByTrace() {}
+
+void NativeThreadNetBSD::SetStoppedByBreakpoint() {}
+
+NativeProcessNetBSD &NativeThreadNetBSD::GetProcess() {
+  auto process_sp = std::static_pointer_cast<NativeProcessNetBSD>(
+      NativeThreadProtocol::GetProcess());
+  assert(process_sp);
+  return *process_sp;
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
