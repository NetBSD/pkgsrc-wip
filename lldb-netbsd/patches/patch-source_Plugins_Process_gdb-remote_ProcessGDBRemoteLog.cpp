$NetBSD$

--- source/Plugins/Process/gdb-remote/ProcessGDBRemoteLog.cpp.orig	2016-12-17 10:30:03.000000000 +0000
+++ source/Plugins/Process/gdb-remote/ProcessGDBRemoteLog.cpp
@@ -14,11 +14,14 @@
 #include "lldb/Core/StreamFile.h"
 #include "lldb/Interpreter/Args.h"
 
+#include "llvm/Support/Threading.h"
+
 #include "ProcessGDBRemote.h"
 
 using namespace lldb;
 using namespace lldb_private;
 using namespace lldb_private::process_gdb_remote;
+using namespace llvm;
 
 // We want to avoid global constructors where code needs to be run so here we
 // control access to our static g_log_sp by hiding it in a singleton function
@@ -34,9 +37,9 @@ static Log *GetLog() {
 
 void ProcessGDBRemoteLog::Initialize() {
   static ConstString g_name("gdb-remote");
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     Log::Callbacks log_callbacks = {DisableLog, EnableLog, ListLogCategories};
 
     Log::RegisterLogChannel(g_name, log_callbacks);
