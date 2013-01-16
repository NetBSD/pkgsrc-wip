$NetBSD: patch-ipc_ipc__path__manager.cc,v 1.3 2013/01/16 12:35:59 ryo-on Exp $

--- ipc/ipc_path_manager.cc.orig	2012-08-31 05:37:07.000000000 +0000
+++ ipc/ipc_path_manager.cc
@@ -284,7 +284,7 @@ bool IPCPathManager::GetPathName(string 
   *ipc_name = kIPCPrefix;
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
@@ -377,7 +377,7 @@ bool IPCPathManager::IsValidServer(uint3
   }
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX)
   // load from /proc/<pid>/exe
   char proc[128];
   char filename[512];
@@ -397,7 +397,7 @@ bool IPCPathManager::IsValidServer(uint3
     return true;
   }
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   if ((server_path + " (deleted)") == server_path_) {
     LOG(WARNING) << server_path << " on disk is modified";
     // If a user updates the server binary on disk during the server is running,
