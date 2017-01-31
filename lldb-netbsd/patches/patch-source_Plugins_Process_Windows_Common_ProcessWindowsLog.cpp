$NetBSD$

--- source/Plugins/Process/Windows/Common/ProcessWindowsLog.cpp.orig	2016-12-17 10:30:06.000000000 +0000
+++ source/Plugins/Process/Windows/Common/ProcessWindowsLog.cpp
@@ -25,12 +25,12 @@ using namespace lldb_private;
 static bool g_log_enabled = false;
 static Log *g_log = nullptr;
 
-static llvm::ManagedStatic<std::once_flag> g_once_flag;
+LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
 void ProcessWindowsLog::Initialize() {
   static ConstString g_name("windows");
 
-  std::call_once(*g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     Log::Callbacks log_callbacks = {DisableLog, EnableLog, ListLogCategories};
 
     Log::RegisterLogChannel(g_name, log_callbacks);
