$NetBSD$

--- source/Plugins/Process/MacOSX-Kernel/ProcessKDP.cpp.orig	2017-01-31 17:20:57.000000000 +0000
+++ source/Plugins/Process/MacOSX-Kernel/ProcessKDP.cpp
@@ -39,6 +39,8 @@
 #include "lldb/Target/Thread.h"
 #include "lldb/Utility/StringExtractor.h"
 
+#include "llvm/Support/Threading.h"
+
 #define USEC_PER_SEC 1000000
 
 // Project includes
@@ -718,9 +720,9 @@ Error ProcessKDP::DoSignal(int signo) {
 }
 
 void ProcessKDP::Initialize() {
-  static std::once_flag g_once_flag;
+  static llvm::once_flag g_once_flag;
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(), CreateInstance,
                                   DebuggerInitialize);
