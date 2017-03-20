$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2017-03-20 16:10:36.201719451 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -0,0 +1,200 @@
+//===-- NativeProcessNetBSD.cpp ------------------------------- -*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#include "NativeProcessNetBSD.h"
+
+// C Includes
+
+// C++ Includes
+
+// Other libraries and framework includes
+
+#include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
+
+// System includes - They have to be included after framework includes because
+// they define some
+// macros which collide with variable names in other modules
+
+using namespace lldb;
+using namespace lldb_private;
+using namespace lldb_private::process_netbsd;
+using namespace llvm;
+
+namespace {
+void MaybeLogLaunchInfo(const ProcessLaunchInfo &info) {}
+
+void DisplayBytes(StreamString &s, void *bytes, uint32_t count) {}
+
+void PtraceDisplayBytes(int &req, void *addr, int data) {}
+
+} // end of anonymous namespace
+
+// -----------------------------------------------------------------------------
+// Public Static Methods
+// -----------------------------------------------------------------------------
+
+Error NativeProcessProtocol::Launch(
+    ProcessLaunchInfo &launch_info,
+    NativeProcessProtocol::NativeDelegate &native_delegate, MainLoop &mainloop,
+    NativeProcessProtocolSP &native_process_sp) {
+  return Error();
+}
+
+Error NativeProcessProtocol::Attach(
+    lldb::pid_t pid, NativeProcessProtocol::NativeDelegate &native_delegate,
+    MainLoop &mainloop, NativeProcessProtocolSP &native_process_sp) {
+  return Error();
+}
+
+// -----------------------------------------------------------------------------
+// Public Instance Methods
+// -----------------------------------------------------------------------------
+
+NativeProcessNetBSD::NativeProcessNetBSD()
+    : NativeProcessProtocol(LLDB_INVALID_PROCESS_ID), m_arch(),
+      m_supports_mem_region(eLazyBoolCalculate), m_mem_region_cache(),
+      m_pending_notification_tid(LLDB_INVALID_THREAD_ID) {}
+
+void NativeProcessNetBSD::AttachToInferior(MainLoop &mainloop, lldb::pid_t pid,
+                                           Error &error) {}
+
+Error NativeProcessNetBSD::LaunchInferior(MainLoop &mainloop,
+                                          ProcessLaunchInfo &launch_info) {
+  return Error();
+}
+
+::pid_t NativeProcessNetBSD::Attach(lldb::pid_t pid, Error &error) {
+  return -1;
+}
+
+Error NativeProcessNetBSD::SetDefaultPtraceOpts(lldb::pid_t pid) {
+  return Error();
+}
+
+// Handles all waitpid events from the inferior process.
+void NativeProcessNetBSD::MonitorCallback(lldb::pid_t pid, bool exited,
+                                          int signal, int status) {}
+
+Error NativeProcessNetBSD::Resume(const ResumeActionList &resume_actions) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::Halt() { return Error(); }
+
+Error NativeProcessNetBSD::Detach() { return Error(); }
+
+Error NativeProcessNetBSD::Signal(int signo) { return Error(); }
+
+Error NativeProcessNetBSD::Interrupt() { return Error(); }
+
+Error NativeProcessNetBSD::Kill() { return Error(); }
+
+Error NativeProcessNetBSD::GetMemoryRegionInfo(lldb::addr_t load_addr,
+                                               MemoryRegionInfo &range_info) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::PopulateMemoryRegionCache() { return Error(); }
+
+Error NativeProcessNetBSD::AllocateMemory(size_t size, uint32_t permissions,
+                                          lldb::addr_t &addr) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::DeallocateMemory(lldb::addr_t addr) {
+  return Error("not implemented");
+}
+
+lldb::addr_t NativeProcessNetBSD::GetSharedLibraryInfoAddress() {
+  return LLDB_INVALID_ADDRESS;
+}
+
+size_t NativeProcessNetBSD::UpdateThreads() { return 0; }
+
+bool NativeProcessNetBSD::GetArchitecture(ArchSpec &arch) const {
+  arch = m_arch;
+  return true;
+}
+
+Error NativeProcessNetBSD::FixupBreakpointPCAsNeeded(
+    NativeThreadNetBSD &thread) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::SetBreakpoint(lldb::addr_t addr, uint32_t size,
+                                         bool hardware) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::GetSoftwareBreakpointTrapOpcode(
+    size_t trap_opcode_size_hint, size_t &actual_opcode_size,
+    const uint8_t *&trap_opcode_bytes) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::GetSoftwareBreakpointPCOffset(
+    uint32_t &actual_opcode_size) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::ReadMemory(lldb::addr_t addr, void *buf, size_t size,
+                                      size_t &bytes_read) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::ReadMemoryWithoutTrap(lldb::addr_t addr, void *buf,
+                                                 size_t size,
+                                                 size_t &bytes_read) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::WriteMemory(lldb::addr_t addr, const void *buf,
+                                       size_t size, size_t &bytes_written) {
+  return Error();
+}
+
+bool NativeProcessNetBSD::HasThreadNoLock(lldb::tid_t thread_id) {
+  return false;
+}
+
+NativeThreadNetBSDSP NativeProcessNetBSD::AddThread(lldb::tid_t thread_id) {
+  auto thread_sp = std::make_shared<NativeThreadNetBSD>(this, thread_id);
+  m_threads.push_back(thread_sp);
+  return thread_sp;
+}
+
+Error NativeProcessNetBSD::GetLoadedModuleFileSpec(const char *module_path,
+                                                   FileSpec &file_spec) {
+  return Error();
+}
+
+Error NativeProcessNetBSD::GetFileLoadAddress(const llvm::StringRef &file_name,
+                                              lldb::addr_t &load_addr) {
+  return Error();
+}
+
+NativeThreadNetBSDSP NativeProcessNetBSD::GetThreadByID(lldb::tid_t tid) {
+  return std::static_pointer_cast<NativeThreadNetBSD>(
+      NativeProcessProtocol::GetThreadByID(tid));
+}
+
+llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>>
+NativeProcessNetBSD::GetAuxvData() const {}
+
+//===----------------------------------------------------------------------===//
+
+void NativeProcessNetBSD::SigchldHandler() {}
+
+// Wrapper for ptrace to catch errors and log calls.
+// Note that ptrace sets errno on error because -1 can be a valid result (i.e.
+// for PT_READ*)
+Error NativeProcessNetBSD::PtraceWrapper(int req, lldb::pid_t pid, void *addr,
+                                         int data, int *result) {
+  return Error();
+}
