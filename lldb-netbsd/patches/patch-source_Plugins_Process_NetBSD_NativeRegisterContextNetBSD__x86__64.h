$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.h.orig	2017-03-29 00:14:15.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.h
@@ -48,13 +48,15 @@ public:
 
 protected:
   void *GetGPRBuffer() override { return &m_gpr_x86_64; }
+  void *GetFPRBuffer() override { return &m_fpr_x86_64; }
 
 private:
   // Private member types.
-  enum { GPRegSet };
+  enum { GPRegSet, FPRegSet };
 
   // Private member variables.
   struct reg m_gpr_x86_64;
+  struct fpreg m_fpr_x86_64;
 
   int GetSetForNativeRegNum(int reg_num) const;
 
