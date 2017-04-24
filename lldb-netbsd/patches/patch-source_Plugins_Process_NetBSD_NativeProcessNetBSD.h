$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.h.orig	2017-03-30 22:14:30.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.h
@@ -114,6 +114,7 @@ private:
   // ---------------------------------------------------------------------
   NativeProcessNetBSD();
 
+  Error RemoveThread(lldb::tid_t thread_id);
   NativeThreadNetBSDSP AddThread(lldb::tid_t thread_id);
 
   Error LaunchInferior(MainLoop &mainloop, ProcessLaunchInfo &launch_info);
@@ -133,6 +134,8 @@ private:
   ::pid_t Attach(lldb::pid_t pid, Error &error);
 
   Error ReinitializeThreads();
+
+  Error SetDefaultPtraceOpts();
 };
 
 } // namespace process_netbsd
