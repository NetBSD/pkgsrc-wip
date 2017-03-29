$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.cpp.orig	2017-03-29 00:14:15.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.cpp
@@ -41,6 +41,22 @@ Error NativeRegisterContextNetBSD::Write
   return DoWriteGPR(buf);
 }
 
+Error NativeRegisterContextNetBSD::ReadFPR() {
+  void *buf = GetFPRBuffer();
+  if (!buf)
+    return Error("FPR buffer is NULL");
+
+  return DoReadFPR(buf);
+}
+
+Error NativeRegisterContextNetBSD::WriteFPR() {
+  void *buf = GetFPRBuffer();
+  if (!buf)
+    return Error("FPR buffer is NULL");
+
+  return DoWriteFPR(buf);
+}
+
 Error NativeRegisterContextNetBSD::DoReadGPR(void *buf) {
   return NativeProcessNetBSD::PtraceWrapper(PT_GETREGS, GetProcessPid(), buf,
                                             m_thread.GetID());
@@ -51,6 +67,16 @@ Error NativeRegisterContextNetBSD::DoWri
                                             m_thread.GetID());
 }
 
+Error NativeRegisterContextNetBSD::DoReadFPR(void *buf) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_GETFPREGS, GetProcessPid(), buf,
+                                            m_thread.GetID());
+}
+
+Error NativeRegisterContextNetBSD::DoWriteFPR(void *buf) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_SETFPREGS, GetProcessPid(), buf,
+                                            m_thread.GetID());
+}
+
 NativeProcessNetBSD &NativeRegisterContextNetBSD::GetProcess() {
   auto process_sp =
       std::static_pointer_cast<NativeProcessNetBSD>(m_thread.GetProcess());
