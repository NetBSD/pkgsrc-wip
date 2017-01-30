$NetBSD$

--- source/Plugins/Process/gdb-remote/GDBRemoteCommunicationServerPlatform.cpp.orig	2017-01-28 19:35:15.000000000 +0000
+++ source/Plugins/Process/gdb-remote/GDBRemoteCommunicationServerPlatform.cpp
@@ -36,6 +36,8 @@
 #include "lldb/Target/UnixSignals.h"
 #include "lldb/Utility/JSON.h"
 
+#include "llvm/Support/Threading.h"
+
 // Project includes
 #include "Utility/StringExtractorGDBRemote.h"
 #include "Utility/UriParser.h"
@@ -528,9 +530,9 @@ bool GDBRemoteCommunicationServerPlatfor
 
 const FileSpec &GDBRemoteCommunicationServerPlatform::GetDomainSocketDir() {
   static FileSpec g_domainsocket_dir;
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     const char *domainsocket_dir_env =
         ::getenv("LLDB_DEBUGSERVER_DOMAINSOCKET_DIR");
     if (domainsocket_dir_env != nullptr)
