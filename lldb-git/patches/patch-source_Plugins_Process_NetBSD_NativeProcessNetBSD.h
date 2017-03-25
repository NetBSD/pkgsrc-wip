$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.h.orig	2017-03-21 17:54:57.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.h
@@ -39,8 +39,28 @@ class NativeProcessNetBSD : public Nativ
       lldb::pid_t pid, NativeProcessProtocol::NativeDelegate &native_delegate,
       MainLoop &mainloop, NativeProcessProtocolSP &process_sp);
 
+  // ---------------------------------------------------------------------
+  // Interface used by NativeRegisterContext-derived classes.
+  // ---------------------------------------------------------------------
+  static Error PtraceWrapper(int req, lldb::pid_t pid, void *addr = nullptr,
+                             int data = 0, int *result = nullptr);
+
 private:
+  ArchSpec m_arch;
+
+  // ---------------------------------------------------------------------
+  // Private Instance Methods
+  // ---------------------------------------------------------------------
   NativeProcessNetBSD();
+
+  void MonitorCallback(lldb::pid_t pid, int signal);
+  void MonitorExited(lldb::pid_t pid, int signal, int status);
+  void MonitorSIGSTOP(lldb::pid_t pid);
+  void MonitorSIGTRAP(lldb::pid_t pid);
+  void MonitorSignal(lldb::pid_t pid, int signal);
+
+  Error GetSoftwareBreakpointPCOffset(uint32_t &actual_opcode_size);
+  Error FixupBreakpointPCAsNeeded(NativeThreadNetBSD &thread);
 };
 
 } // namespace process_netbsd
