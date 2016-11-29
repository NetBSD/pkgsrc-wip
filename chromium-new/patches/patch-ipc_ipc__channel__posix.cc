$NetBSD$

--- ipc/ipc_channel_posix.cc.orig	2016-11-10 20:02:15.000000000 +0000
+++ ipc/ipc_channel_posix.cc
@@ -183,9 +183,9 @@ void Channel::NotifyProcessForkedForTest
 
 //------------------------------------------------------------------------------
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 int ChannelPosix::global_pid_ = 0;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)
 
 ChannelPosix::ChannelPosix(const IPC::ChannelHandle& channel_handle,
                            Mode mode,
@@ -613,7 +613,7 @@ bool ChannelPosix::IsNamedServerInitiali
   return base::PathExists(base::FilePath(channel_id));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 void ChannelPosix::SetGlobalPid(int pid) {
   global_pid_ = pid;
@@ -622,7 +622,7 @@ void ChannelPosix::SetGlobalPid(int pid)
 int ChannelPosix::GetGlobalPid() {
   return global_pid_;
 }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)
 
 // Called by libevent when we can read from the pipe without blocking.
 void ChannelPosix::OnFileCanReadWithoutBlocking(int fd) {
@@ -811,12 +811,12 @@ int ChannelPosix::GetHelloMessageProcId(
   return -1;
 #else
   int pid = base::GetCurrentProcId();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Our process may be in a sandbox with a separate PID namespace.
   if (global_pid_) {
     pid = global_pid_;
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   return pid;
 #endif  // defined(OS_NACL_NONSFI)
 }
@@ -1133,7 +1133,7 @@ bool Channel::IsNamedServerInitialized(
   return ChannelPosix::IsNamedServerInitialized(channel_id);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 void Channel::SetGlobalPid(int pid) {
   ChannelPosix::SetGlobalPid(pid);
@@ -1141,6 +1141,6 @@ void Channel::SetGlobalPid(int pid) {
 int Channel::GetGlobalPid() {
   return ChannelPosix::GetGlobalPid();
 }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)
 
 }  // namespace IPC
