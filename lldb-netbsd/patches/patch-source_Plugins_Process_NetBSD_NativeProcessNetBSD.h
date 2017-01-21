$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.h.orig	2017-01-20 20:30:48.337095578 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.h
@@ -0,0 +1,183 @@
+//===-- NativeProcessNetBSD.h ---------------------------------- -*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#ifndef liblldb_NativeProcessNetBSD_H_
+#define liblldb_NativeProcessNetBSD_H_
+
+// C++ Includes
+#include <unordered_set>
+
+// Other libraries and framework includes
+#include "lldb/Core/ArchSpec.h"
+#include "lldb/Host/Debug.h"
+#include "lldb/Host/FileSpec.h"
+#include "lldb/Host/HostThread.h"
+#include "lldb/Target/MemoryRegionInfo.h"
+#include "lldb/lldb-types.h"
+
+#include "NativeThreadNetBSD.h"
+#include "lldb/Host/common/NativeProcessProtocol.h"
+
+namespace lldb_private {
+class Error;
+class Scalar;
+
+namespace process_netbsd {
+/// @class NativeProcessNetBSD
+/// @brief Manages communication with the inferior (debugee) process.
+///
+/// Upon construction, this class prepares and launches an inferior process for
+/// debugging.
+///
+/// Changes in the inferior process state are broadcasted.
+class NativeProcessNetBSD : public NativeProcessProtocol {
+  friend Error NativeProcessProtocol::Launch(
+      ProcessLaunchInfo &launch_info, NativeDelegate &native_delegate,
+      MainLoop &mainloop, NativeProcessProtocolSP &process_sp);
+
+  friend Error NativeProcessProtocol::Attach(
+      lldb::pid_t pid, NativeProcessProtocol::NativeDelegate &native_delegate,
+      MainLoop &mainloop, NativeProcessProtocolSP &process_sp);
+
+public:
+  // ---------------------------------------------------------------------
+  // NativeProcessProtocol Interface
+  // ---------------------------------------------------------------------
+  Error Resume(const ResumeActionList &resume_actions) override;
+
+  Error Halt() override;
+
+  Error Detach() override;
+
+  Error Signal(int signo) override;
+
+  Error Interrupt() override;
+
+  Error Kill() override;
+
+  Error GetMemoryRegionInfo(lldb::addr_t load_addr,
+                            MemoryRegionInfo &range_info) override;
+
+  Error ReadMemory(lldb::addr_t addr, void *buf, size_t size,
+                   size_t &bytes_read) override;
+
+  Error ReadMemoryWithoutTrap(lldb::addr_t addr, void *buf, size_t size,
+                              size_t &bytes_read) override;
+
+  Error WriteMemory(lldb::addr_t addr, const void *buf, size_t size,
+                    size_t &bytes_written) override;
+
+  Error AllocateMemory(size_t size, uint32_t permissions,
+                       lldb::addr_t &addr) override;
+
+  Error DeallocateMemory(lldb::addr_t addr) override;
+
+  lldb::addr_t GetSharedLibraryInfoAddress() override;
+
+  size_t UpdateThreads() override;
+
+  bool GetArchitecture(ArchSpec &arch) const override;
+
+  Error SetBreakpoint(lldb::addr_t addr, uint32_t size, bool hardware) override;
+
+  void DoStopIDBumped(uint32_t newBumpId) override;
+
+  Error GetLoadedModuleFileSpec(const char *module_path,
+                                FileSpec &file_spec) override;
+
+  Error GetFileLoadAddress(const llvm::StringRef &file_name,
+                           lldb::addr_t &load_addr) override;
+
+  NativeThreadNetBSDSP GetThreadByID(lldb::tid_t id);
+
+  // ---------------------------------------------------------------------
+  // Interface used by NativeRegisterContext-derived classes.
+  // ---------------------------------------------------------------------
+  static Error PtraceWrapper(int req, lldb::pid_t pid, void *addr = nullptr,
+                             int data = 0, int *result = nullptr);
+
+protected:
+  // ---------------------------------------------------------------------
+  // NativeProcessProtocol protected interface
+  // ---------------------------------------------------------------------
+
+  Error
+  GetSoftwareBreakpointTrapOpcode(size_t trap_opcode_size_hint,
+                                  size_t &actual_opcode_size,
+                                  const uint8_t *&trap_opcode_bytes) override;
+
+private:
+  MainLoop::SignalHandleUP m_sigchld_handle;
+  ArchSpec m_arch;
+
+  LazyBool m_supports_mem_region;
+  std::vector<MemoryRegionInfo> m_mem_region_cache;
+
+  lldb::tid_t m_pending_notification_tid;
+
+  // List of thread ids stepping with a breakpoint with the address of
+  // the relevan breakpoint
+  std::map<lldb::tid_t, lldb::addr_t> m_threads_stepping_with_breakpoint;
+
+  // ---------------------------------------------------------------------
+  // Private Instance Methods
+  // ---------------------------------------------------------------------
+  NativeProcessNetBSD();
+
+  Error LaunchInferior(MainLoop &mainloop, ProcessLaunchInfo &launch_info);
+
+  /// Attaches to an existing process.  Forms the
+  /// implementation of Process::DoAttach
+  void AttachToInferior(MainLoop &mainloop, lldb::pid_t pid, Error &error);
+
+  ::pid_t Attach(lldb::pid_t pid, Error &error);
+
+  static Error SetDefaultPtraceOpts(const lldb::pid_t);
+
+  static void *MonitorThread(void *baton);
+
+  void MonitorCallback(lldb::pid_t pid, bool exited, int signal, int status);
+
+  void MonitorSIGTRAP(const siginfo_t &info, NativeThreadNetBSD &thread);
+
+  Error SetupSoftwareSingleStepping(NativeThreadNetBSD &thread);
+
+
+  bool HasThreadNoLock(lldb::tid_t thread_id);
+
+  NativeThreadNetBSDSP AddThread(lldb::tid_t thread_id);
+
+  Error GetSoftwareBreakpointPCOffset(uint32_t &actual_opcode_size);
+
+  Error FixupBreakpointPCAsNeeded(NativeThreadNetBSD &thread);
+
+  /// Writes a siginfo_t structure corresponding to the given thread ID to the
+  /// memory region pointed to by @p siginfo.
+  Error GetSignalInfo(lldb::tid_t tid, void *siginfo);
+
+  void NotifyThreadDeath(lldb::tid_t tid);
+
+  Error Detach(lldb::tid_t tid);
+
+  // Notify the delegate if all threads have stopped.
+  void SignalIfAllThreadsStopped();
+
+  // Resume the given thread, optionally passing it the given signal. The type
+  // of resume
+  // operation (continue, single-step) depends on the state parameter.
+  Error ResumeThread(NativeThreadNetBSD &thread, lldb::StateType state,
+                     int signo);
+
+  void SigchldHandler();
+};
+
+} // namespace process_netbsd
+} // namespace lldb_private
+
+#endif // #ifndef liblldb_NativeProcessNetBSD_H_
