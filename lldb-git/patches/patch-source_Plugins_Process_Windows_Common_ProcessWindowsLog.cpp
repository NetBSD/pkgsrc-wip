$NetBSD$

--- source/Plugins/Process/Windows/Common/ProcessWindowsLog.cpp.orig	2016-09-10 17:36:23.000000000 +0000
+++ source/Plugins/Process/Windows/Common/ProcessWindowsLog.cpp
@@ -14,6 +14,7 @@
 #include "lldb/Core/StreamFile.h"
 #include "lldb/Interpreter/Args.h"
 #include "llvm/Support/ManagedStatic.h"
+#include "llvm/Support/Threading.h"
 
 using namespace lldb;
 using namespace lldb_private;
@@ -25,12 +26,12 @@ using namespace lldb_private;
 static bool g_log_enabled = false;
 static Log *g_log = nullptr;
 
-static llvm::ManagedStatic<std::once_flag> g_once_flag;
+static llvm::ManagedStatic<llvm::once_flag> g_once_flag;
 
 void ProcessWindowsLog::Initialize() {
   static ConstString g_name("windows");
 
-  std::call_once(*g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     Log::Callbacks log_callbacks = {DisableLog, EnableLog, ListLogCategories};
 
     Log::RegisterLogChannel(g_name, log_callbacks);
