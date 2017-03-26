$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h.orig	2017-03-22 18:17:31.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h
@@ -33,6 +33,19 @@ public:
   CreateHostNativeRegisterContextNetBSD(const ArchSpec &target_arch,
                                         NativeThreadProtocol &native_thread,
                                         uint32_t concrete_frame_idx);
+
+protected:
+  virtual Error ReadGPR();
+  virtual Error WriteGPR();
+  virtual void *GetGPRBuffer() { return nullptr; }
+  virtual size_t GetGPRSize() {
+    return GetRegisterInfoInterface().GetGPRSize();
+  }
+  virtual Error DoReadGPR(void *buf);
+  virtual Error DoWriteGPR(void *buf);
+
+  virtual NativeProcessNetBSD &GetProcess();
+  virtual pid_t GetProcessPid();
 };
 
 } // namespace process_netbsd
