$NetBSD$

--- source/Plugins/Process/gdb-remote/GDBRemoteCommunicationServerPlatform.cpp.orig	2017-02-02 23:56:41.000000000 +0000
+++ source/Plugins/Process/gdb-remote/GDBRemoteCommunicationServerPlatform.cpp
@@ -20,6 +20,7 @@
 
 // Other libraries and framework includes
 #include "llvm/Support/FileSystem.h"
+#include "llvm/Support/Threading.h"
 
 #include "lldb/Core/Log.h"
 #include "lldb/Core/StreamGDBRemote.h"
@@ -528,9 +529,9 @@ bool GDBRemoteCommunicationServerPlatfor
 
 const FileSpec &GDBRemoteCommunicationServerPlatform::GetDomainSocketDir() {
   static FileSpec g_domainsocket_dir;
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     const char *domainsocket_dir_env =
         ::getenv("LLDB_DEBUGSERVER_DOMAINSOCKET_DIR");
     if (domainsocket_dir_env != nullptr)
