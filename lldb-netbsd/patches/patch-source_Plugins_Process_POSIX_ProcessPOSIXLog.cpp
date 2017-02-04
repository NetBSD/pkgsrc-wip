$NetBSD$

--- source/Plugins/Process/POSIX/ProcessPOSIXLog.cpp.orig	2016-12-17 10:29:54.000000000 +0000
+++ source/Plugins/Process/POSIX/ProcessPOSIXLog.cpp
@@ -15,6 +15,8 @@
 #include "lldb/Core/StreamFile.h"
 #include "lldb/Interpreter/Args.h"
 
+#include "llvm/Support/Threading.h"
+
 #include "ProcessPOSIXLog.h"
 
 using namespace lldb;
@@ -33,9 +35,9 @@ static Log *GetLog() {
 }
 
 void ProcessPOSIXLog::Initialize(ConstString name) {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, [name]() {
+  llvm::call_once(g_once_flag, [name]() {
     Log::Callbacks log_callbacks = {DisableLog, EnableLog, ListLogCategories};
 
     Log::RegisterLogChannel(name, log_callbacks);
