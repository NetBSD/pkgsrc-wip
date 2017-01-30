$NetBSD$

--- source/Plugins/Process/POSIX/ProcessPOSIXLog.cpp.orig	2016-12-14 14:10:24.000000000 +0000
+++ source/Plugins/Process/POSIX/ProcessPOSIXLog.cpp
@@ -15,10 +15,13 @@
 #include "lldb/Core/StreamFile.h"
 #include "lldb/Interpreter/Args.h"
 
+#include "llvm/Support/Threading.h"
+
 #include "ProcessPOSIXLog.h"
 
 using namespace lldb;
 using namespace lldb_private;
+using namespace llvm;
 
 // We want to avoid global constructors where code needs to be run so here we
 // control access to our static g_log_sp by hiding it in a singleton function
@@ -33,9 +36,9 @@ static Log *GetLog() {
 }
 
 void ProcessPOSIXLog::Initialize(ConstString name) {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, [name]() {
+  llvm::call_once(g_once_flag, [name]() {
     Log::Callbacks log_callbacks = {DisableLog, EnableLog, ListLogCategories};
 
     Log::RegisterLogChannel(name, log_callbacks);
