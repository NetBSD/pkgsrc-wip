$NetBSD$

--- ipc/ipc_channel_posix.h.orig	2016-11-10 20:02:15.000000000 +0000
+++ ipc/ipc_channel_posix.h
@@ -63,10 +63,10 @@ class IPC_EXPORT ChannelPosix : public C
   void CloseClientFileDescriptor();
 
   static bool IsNamedServerInitialized(const std::string& channel_id);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   static void SetGlobalPid(int pid);
   static int GetGlobalPid();
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)
 
  private:
   bool CreatePipe(const IPC::ChannelHandle& channel_handle);
@@ -209,10 +209,10 @@ class IPC_EXPORT ChannelPosix : public C
   // True if we are responsible for unlinking the unix domain socket file.
   bool must_unlink_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // If non-zero, overrides the process ID sent in the hello message.
   static int global_pid_;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || defined(OS_BSD)
 
   DISALLOW_IMPLICIT_CONSTRUCTORS(ChannelPosix);
 };
