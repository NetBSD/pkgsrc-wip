$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h.orig	2017-03-30 22:14:30.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.h
@@ -41,6 +41,9 @@ protected:
   virtual Error ReadFPR();
   virtual Error WriteFPR();
 
+  virtual Error ReadDBR();
+  virtual Error WriteDBR();
+
   virtual void *GetGPRBuffer() { return nullptr; }
   virtual size_t GetGPRSize() {
     return GetRegisterInfoInterface().GetGPRSize();
@@ -49,12 +52,18 @@ protected:
   virtual void *GetFPRBuffer() { return nullptr; }
   virtual size_t GetFPRSize() { return 0; }
 
+  virtual void *GetDBRBuffer() { return nullptr; }
+  virtual size_t GetDBRSize() { return 0; }
+
   virtual Error DoReadGPR(void *buf);
   virtual Error DoWriteGPR(void *buf);
 
   virtual Error DoReadFPR(void *buf);
   virtual Error DoWriteFPR(void *buf);
 
+  virtual Error DoReadDBR(void *buf);
+  virtual Error DoWriteDBR(void *buf);
+
   virtual NativeProcessNetBSD &GetProcess();
   virtual ::pid_t GetProcessPid();
 };
