$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.h.orig	2017-03-29 00:14:15.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.h
@@ -131,6 +131,8 @@ private:
   void SigchldHandler();
 
   ::pid_t Attach(lldb::pid_t pid, Error &error);
+
+  Error ReinitializeThreads();
 };
 
 } // namespace process_netbsd
