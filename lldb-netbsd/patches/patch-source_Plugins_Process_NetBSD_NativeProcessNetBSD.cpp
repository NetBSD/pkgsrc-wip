$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2017-05-24 01:55:02.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -167,8 +167,6 @@ NativeProcessNetBSD::NativeProcessNetBSD
 
 // Handles all waitpid events from the inferior process.
 void NativeProcessNetBSD::MonitorCallback(lldb::pid_t pid, int signal) {
-  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
-
   switch (signal) {
   case SIGTRAP:
     return MonitorSIGTRAP(pid);
@@ -196,7 +194,6 @@ void NativeProcessNetBSD::MonitorExited(
 }
 
 void NativeProcessNetBSD::MonitorSIGSTOP(lldb::pid_t pid) {
-  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
   ptrace_siginfo_t info;
 
   const auto siginfo_err =
@@ -306,7 +303,6 @@ void NativeProcessNetBSD::MonitorSIGTRAP
 
 void NativeProcessNetBSD::MonitorSignal(lldb::pid_t pid, int signal) {
   Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PROCESS));
-
   ptrace_siginfo_t info;
   const auto siginfo_err =
       PtraceWrapper(PT_GET_SIGINFO, pid, &info, sizeof(info));
@@ -916,8 +912,6 @@ NativeThreadNetBSDSP NativeProcessNetBSD
 }
 
 ::pid_t NativeProcessNetBSD::Attach(lldb::pid_t pid, Status &error) {
-  Log *log(GetLogIfAllCategoriesSet(LIBLLDB_LOG_PROCESS));
-
   if (pid <= 1) {
     error.SetErrorToGenericError();
     error.SetErrorString("Attaching to process 1 is not allowed.");
@@ -1006,7 +1000,7 @@ Status NativeProcessNetBSD::WriteMemory(
   io.piod_len = size;
 
   do {
-    io.piod_addr = (void *)(src + bytes_written);
+    io.piod_addr = const_cast<void *>(static_cast<const void *>(src + bytes_written));
     io.piod_offs = (void *)(addr + bytes_written);
 
     Status error = NativeProcessNetBSD::PtraceWrapper(PT_IO, GetID(), &io);
@@ -1034,10 +1028,11 @@ NativeProcessNetBSD::GetAuxvData() const
   ErrorOr<std::unique_ptr<MemoryBuffer>> buf =
       llvm::MemoryBuffer::getNewMemBuffer(auxv_size);
 
-  struct ptrace_io_desc io = {.piod_op = PIOD_READ_AUXV,
-                              .piod_offs = 0,
-                              .piod_addr = (void *)buf.get()->getBufferStart(),
-                              .piod_len = auxv_size};
+  struct ptrace_io_desc io;
+  io.piod_op = PIOD_READ_AUXV;
+  io.piod_offs = 0;
+  io.piod_addr = const_cast<void *>(static_cast<const void *>(buf.get()->getBufferStart()));
+  io.piod_len = auxv_size;
 
   Status error = NativeProcessNetBSD::PtraceWrapper(PT_IO, GetID(), &io);
 
