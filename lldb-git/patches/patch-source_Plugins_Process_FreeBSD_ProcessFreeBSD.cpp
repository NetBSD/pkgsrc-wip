$NetBSD$

--- source/Plugins/Process/FreeBSD/ProcessFreeBSD.cpp.orig	2017-01-28 19:35:15.000000000 +0000
+++ source/Plugins/Process/FreeBSD/ProcessFreeBSD.cpp
@@ -48,6 +48,7 @@
 
 using namespace lldb;
 using namespace lldb_private;
+using namespace llvm;
 
 namespace {
 UnixSignalsSP &GetFreeBSDSignals() {
@@ -71,9 +72,9 @@ ProcessFreeBSD::CreateInstance(lldb::Tar
 }
 
 void ProcessFreeBSD::Initialize() {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(), CreateInstance);
     ProcessPOSIXLog::Initialize(GetPluginNameStatic());
