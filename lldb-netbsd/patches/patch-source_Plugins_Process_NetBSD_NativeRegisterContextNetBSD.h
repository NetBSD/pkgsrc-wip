$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h.orig	2017-03-29 00:14:15.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h
@@ -37,13 +37,26 @@ public:
 protected:
   virtual Error ReadGPR();
   virtual Error WriteGPR();
+
+  virtual Error ReadFPR();
+  virtual Error WriteFPR();
+
   virtual void *GetGPRBuffer() { return nullptr; }
   virtual size_t GetGPRSize() {
     return GetRegisterInfoInterface().GetGPRSize();
   }
+
+  virtual void *GetFPRBuffer() { return nullptr; }
+  virtual size_t GetFPRSize() {
+    return 0;
+  }
+
   virtual Error DoReadGPR(void *buf);
   virtual Error DoWriteGPR(void *buf);
 
+  virtual Error DoReadFPR(void *buf);
+  virtual Error DoWriteFPR(void *buf);
+
   virtual NativeProcessNetBSD &GetProcess();
   virtual ::pid_t GetProcessPid();
 };
