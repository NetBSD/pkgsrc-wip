$NetBSD$

--- source/Plugins/Process/mach-core/ProcessMachCore.cpp.orig	2016-12-17 10:30:06.000000000 +0000
+++ source/Plugins/Process/mach-core/ProcessMachCore.cpp
@@ -45,6 +45,7 @@
 
 using namespace lldb;
 using namespace lldb_private;
+using namespace llvm;
 
 ConstString ProcessMachCore::GetPluginNameStatic() {
   static ConstString g_name("mach-o-core");
@@ -579,9 +580,9 @@ Error ProcessMachCore::GetMemoryRegionIn
 void ProcessMachCore::Clear() { m_thread_list.Clear(); }
 
 void ProcessMachCore::Initialize() {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(), CreateInstance);
   });
