$NetBSD: patch-ipc_ipc__path__manager.cc,v 1.1 2013/01/14 06:21:30 ryo-on Exp $

* I am no sure.

--- ipc/ipc_path_manager.cc.orig	2012-08-31 05:37:07.000000000 +0000
+++ ipc/ipc_path_manager.cc
@@ -284,7 +284,7 @@ bool IPCPathManager::GetPathName(string 
   *ipc_name = kIPCPrefix;
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && (!defined(__FreeBSD__) || !defined(__NetBSD__))
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
