$NetBSD$

--- source/Plugins/Process/minidump/ProcessMinidump.cpp.orig	2017-02-27 20:47:52.000000000 +0000
+++ source/Plugins/Process/minidump/ProcessMinidump.cpp
@@ -159,7 +159,8 @@ void ProcessMinidump::RefreshStateAfterS
   stop_thread = Process::m_thread_list.GetSelectedThread();
   ArchSpec arch = GetArchitecture();
 
-  if (arch.GetTriple().getOS() == llvm::Triple::Linux) {
+  if (arch.GetTriple().getOS() == llvm::Triple::Linux ||
+      arch.GetTriple().getOS() == llvm::Triple::NetBSD) {
     stop_info = StopInfo::CreateStopReasonWithSignal(
         *stop_thread, m_active_exception->exception_record.exception_code);
   } else {
