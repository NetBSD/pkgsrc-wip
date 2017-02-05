$NetBSD$

--- source/Plugins/Process/gdb-remote/ProcessGDBRemoteLog.cpp.orig	2016-10-19 22:25:12.000000000 +0000
+++ source/Plugins/Process/gdb-remote/ProcessGDBRemoteLog.cpp
@@ -14,6 +14,8 @@
 #include "lldb/Core/StreamFile.h"
 #include "lldb/Interpreter/Args.h"
 
+#include "llvm/Support/Threading.h"
+
 #include "ProcessGDBRemote.h"
 
 using namespace lldb;
@@ -34,9 +36,9 @@ static Log *GetLog() {
 
 void ProcessGDBRemoteLog::Initialize() {
   static ConstString g_name("gdb-remote");
-  static std::once_flag g_once_flag;
+  static llvm::once_flag g_once_flag;
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     Log::Callbacks log_callbacks = {DisableLog, EnableLog, ListLogCategories};
 
     Log::RegisterLogChannel(g_name, log_callbacks);
