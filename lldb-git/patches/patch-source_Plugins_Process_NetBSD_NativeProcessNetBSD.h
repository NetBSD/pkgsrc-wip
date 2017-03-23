$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.h.orig	2017-03-21 17:54:57.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.h
@@ -39,8 +39,20 @@ class NativeProcessNetBSD : public Nativ
       lldb::pid_t pid, NativeProcessProtocol::NativeDelegate &native_delegate,
       MainLoop &mainloop, NativeProcessProtocolSP &process_sp);
 
+
+  // ---------------------------------------------------------------------
+  // Interface used by NativeRegisterContext-derived classes.
+  // ---------------------------------------------------------------------
+  static Error PtraceWrapper(int req, lldb::pid_t pid, void *addr = nullptr,
+                             int data = 0, int *result = nullptr);
+
 private:
+  // ---------------------------------------------------------------------
+  // Private Instance Methods
+  // ---------------------------------------------------------------------
   NativeProcessNetBSD();
+
+  void MonitorCallback(lldb::pid_t pid, bool exited, int signal, int status);
 };
 
 } // namespace process_netbsd
