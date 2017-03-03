$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.cpp.orig	2017-03-03 15:35:02.265865750 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.cpp
@@ -0,0 +1,111 @@
+//===-- NativeRegisterContextNetBSD.cpp --------------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#include "NativeRegisterContextNetBSD.h"
+
+#include "lldb/Core/RegisterValue.h"
+#include "lldb/Host/common/NativeProcessProtocol.h"
+#include "lldb/Host/common/NativeThreadProtocol.h"
+
+#include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
+
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/ptrace.h>
+
+using namespace lldb_private;
+using namespace lldb_private::process_netbsd;
+
+NativeRegisterContextNetBSD::NativeRegisterContextNetBSD(
+    NativeThreadProtocol &native_thread, uint32_t concrete_frame_idx,
+    RegisterInfoInterface *reg_info_interface_p)
+    : NativeRegisterContextRegisterInfo(native_thread, concrete_frame_idx,
+                                        reg_info_interface_p) {}
+
+lldb::ByteOrder NativeRegisterContextNetBSD::GetByteOrder() const {
+  // Get the target process whose privileged thread was used for the register
+  // read.
+  lldb::ByteOrder byte_order = lldb::eByteOrderInvalid;
+
+  NativeProcessProtocolSP process_sp(m_thread.GetProcess());
+  if (!process_sp)
+    return byte_order;
+
+  if (!process_sp->GetByteOrder(byte_order)) {
+    // FIXME log here
+  }
+
+  return byte_order;
+}
+
+Error NativeRegisterContextNetBSD::ReadGPR() {
+  void *buf = GetGPRBuffer();
+  if (!buf)
+    return Error("GPR buffer is NULL");
+
+  return DoReadGPR(buf);
+}
+
+Error NativeRegisterContextNetBSD::WriteGPR() {
+  void *buf = GetGPRBuffer();
+  if (!buf)
+    return Error("GPR buffer is NULL");
+
+  return DoWriteGPR(buf);
+}
+
+Error NativeRegisterContextNetBSD::ReadFPR() {
+  void *buf = GetFPRBuffer();
+  if (!buf)
+    return Error("FPR buffer is NULL");
+
+  return DoReadFPR(buf);
+}
+
+Error NativeRegisterContextNetBSD::WriteFPR() {
+  void *buf = GetFPRBuffer();
+  if (!buf)
+    return Error("FPR buffer is NULL");
+
+  return DoWriteFPR(buf);
+}
+
+Error NativeRegisterContextNetBSD::DoReadGPR(void *buf) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_GETREGS, GetProcessPid(),
+                                            buf, m_thread.GetID());
+}
+
+Error NativeRegisterContextNetBSD::DoWriteGPR(void *buf) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_SETREGS, GetProcessPid(),
+                                            buf, m_thread.GetID());
+}
+
+Error NativeRegisterContextNetBSD::DoReadFPR(void *buf) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_GETFPREGS, GetProcessPid(),
+                                            buf, m_thread.GetID());
+}
+
+Error NativeRegisterContextNetBSD::DoWriteFPR(void *buf) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_SETFPREGS, GetProcessPid(),
+                                            buf, m_thread.GetID());
+}
+
+NativeProcessNetBSD &NativeRegisterContextNetBSD::GetProcess() {
+  auto process_sp = std::static_pointer_cast<NativeProcessNetBSD>(
+      m_thread.GetProcess());
+  assert(process_sp);
+  return *process_sp;
+}
+
+pid_t NativeRegisterContextNetBSD::GetProcessPid() {
+  NativeProcessNetBSD &process = GetProcess();
+  lldb::pid_t pid = process.GetID();
+
+  return pid;
+}
