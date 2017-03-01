$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.cpp.orig	2017-03-01 11:04:39.184136620 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.cpp
@@ -0,0 +1,135 @@
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
+  size_t buf_size = GetGPRSize();
+
+  return DoReadGPR(buf, buf_size);
+}
+
+Error NativeRegisterContextNetBSD::WriteGPR() {
+  void *buf = GetGPRBuffer();
+  if (!buf)
+    return Error("GPR buffer is NULL");
+  size_t buf_size = GetGPRSize();
+
+  return DoWriteGPR(buf, buf_size);
+}
+
+Error NativeRegisterContextNetBSD::ReadFPR() {
+  void *buf = GetFPRBuffer();
+  if (!buf)
+    return Error("FPR buffer is NULL");
+  size_t buf_size = GetFPRSize();
+
+  return DoReadFPR(buf, buf_size);
+}
+
+Error NativeRegisterContextNetBSD::WriteFPR() {
+  void *buf = GetFPRBuffer();
+  if (!buf)
+    return Error("FPR buffer is NULL");
+  size_t buf_size = GetFPRSize();
+
+  return DoWriteFPR(buf, buf_size);
+}
+
+Error NativeRegisterContextNetBSD::DoReadRegisterValue(uint32_t offset,
+                                                      const char *reg_name,
+                                                      uint32_t size,
+                                                      RegisterValue &value) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_REGISTERS));
+
+  long data;
+  Error error; /* = NativeProcessNetBSD::PtraceWrapper(
+      PTRACE_PEEKUSER, m_thread.GetID(), reinterpret_cast<void *>(offset),
+      nullptr, 0, &data); */
+
+  if (error.Success())
+    // First cast to an unsigned of the same size to avoid sign extension.
+    value.SetUInt(static_cast<unsigned long>(data), size);
+
+  LLDB_LOG(log, "{0}: {1:x}", reg_name, data);
+  return error;
+}
+
+Error NativeRegisterContextNetBSD::DoWriteRegisterValue(
+    uint32_t offset, const char *reg_name, const RegisterValue &value) {
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_REGISTERS));
+
+  void *buf = reinterpret_cast<void *>(value.GetAsUInt64());
+  LLDB_LOG(log, "{0}: {1}", reg_name, buf);
+
+#if 0
+  return NativeProcessNetBSD::PtraceWrapper(
+      PTRACE_POKEUSER, m_thread.GetID(), reinterpret_cast<void *>(offset), buf);
+#else
+  return Error();
+#endif
+}
+
+Error NativeRegisterContextNetBSD::DoReadGPR(void *buf, size_t buf_size) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_GETREGS, m_thread.GetID(),
+                                           nullptr, 0);
+}
+
+Error NativeRegisterContextNetBSD::DoWriteGPR(void *buf, size_t buf_size) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_SETREGS, m_thread.GetID(),
+                                           nullptr, 0);
+}
+
+Error NativeRegisterContextNetBSD::DoReadFPR(void *buf, size_t buf_size) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_GETFPREGS, m_thread.GetID(),
+                                           nullptr, 0);
+}
+
+Error NativeRegisterContextNetBSD::DoWriteFPR(void *buf, size_t buf_size) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_SETFPREGS, m_thread.GetID(),
+                                           nullptr, 0);
+}
