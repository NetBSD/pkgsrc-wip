$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.cpp.orig	2017-03-30 22:14:30.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.cpp
@@ -57,6 +57,22 @@ Error NativeRegisterContextNetBSD::Write
   return DoWriteFPR(buf);
 }
 
+Error NativeRegisterContextNetBSD::ReadDBR() {
+  void *buf = GetDBRBuffer();
+  if (!buf)
+    return Error("DBR buffer is NULL");
+
+  return DoReadDBR(buf);
+}
+
+Error NativeRegisterContextNetBSD::WriteDBR() {
+  void *buf = GetDBRBuffer();
+  if (!buf)
+    return Error("DBR buffer is NULL");
+
+  return DoWriteDBR(buf);
+}
+
 Error NativeRegisterContextNetBSD::DoReadGPR(void *buf) {
   return NativeProcessNetBSD::PtraceWrapper(PT_GETREGS, GetProcessPid(), buf,
                                             m_thread.GetID());
@@ -77,6 +93,16 @@ Error NativeRegisterContextNetBSD::DoWri
                                             m_thread.GetID());
 }
 
+Error NativeRegisterContextNetBSD::DoReadDBR(void *buf) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_GETDBREGS, GetProcessPid(), buf,
+                                            m_thread.GetID());
+}
+
+Error NativeRegisterContextNetBSD::DoWriteDBR(void *buf) {
+  return NativeProcessNetBSD::PtraceWrapper(PT_SETDBREGS, GetProcessPid(), buf,
+                                            m_thread.GetID());
+}
+
 NativeProcessNetBSD &NativeRegisterContextNetBSD::GetProcess() {
   auto process_sp =
       std::static_pointer_cast<NativeProcessNetBSD>(m_thread.GetProcess());
