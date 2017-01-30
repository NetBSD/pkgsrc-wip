$NetBSD$

--- source/Plugins/Process/MacOSX-Kernel/ProcessKDP.cpp.orig	2017-01-28 19:35:15.000000000 +0000
+++ source/Plugins/Process/MacOSX-Kernel/ProcessKDP.cpp
@@ -50,6 +50,7 @@
 
 using namespace lldb;
 using namespace lldb_private;
+using namespace llvm;
 
 namespace {
 
@@ -718,9 +719,9 @@ Error ProcessKDP::DoSignal(int signo) {
 }
 
 void ProcessKDP::Initialize() {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(), CreateInstance,
                                   DebuggerInitialize);
