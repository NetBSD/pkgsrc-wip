$NetBSD$

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.h.orig	2017-03-30 22:14:30.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.h
@@ -133,6 +133,8 @@ private:
   ::pid_t Attach(lldb::pid_t pid, Error &error);
 
   Error ReinitializeThreads();
+
+  Error SetDefaultPtraceOpts();
 };
 
 } // namespace process_netbsd
