$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h.orig	2017-03-21 20:01:05.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h
@@ -33,6 +33,53 @@ public:
   CreateHostNativeRegisterContextNetBSD(const ArchSpec &target_arch,
                                         NativeThreadProtocol &native_thread,
                                         uint32_t concrete_frame_idx);
+
+  // This function is implemented in the NativeRegisterContextNetBSD_* subclasses
+  // to create a new
+  // instance of the host specific NativeRegisterContextNetBSD. The
+  // implementations can't collide
+  // as only one NativeRegisterContextNetBSD_* variant should be compiled into
+  // the final
+  // executable.
+  static NativeRegisterContextNetBSD *
+  CreateHostNativeRegisterContextNetBSD(const ArchSpec &target_arch,
+                                       NativeThreadProtocol &native_thread,
+                                       uint32_t concrete_frame_idx);
+
+protected:
+  lldb::ByteOrder GetByteOrder() const;
+
+  virtual Error ReadGPR();
+
+  virtual Error WriteGPR();
+
+  virtual Error ReadFPR();
+
+  virtual Error WriteFPR();
+
+  virtual void *GetGPRBuffer() { return nullptr; }
+
+  virtual size_t GetGPRSize() {
+    return GetRegisterInfoInterface().GetGPRSize();
+  }
+
+  virtual void *GetFPRBuffer() { return nullptr; }
+
+  virtual void *GetDBRBuffer() { return nullptr; }
+
+  virtual size_t GetFPRSize() { return 0; }
+
+  virtual Error DoReadGPR(void *buf);
+
+  virtual Error DoWriteGPR(void *buf);
+
+  virtual Error DoReadFPR(void *buf);
+
+  virtual Error DoWriteFPR(void *buf);
+
+  virtual NativeProcessNetBSD &GetProcess();
+
+  virtual pid_t GetProcessPid();
 };
 
 } // namespace process_netbsd
