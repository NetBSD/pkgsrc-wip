$NetBSD$

--- source/Plugins/Process/mach-core/ProcessMachCore.cpp.orig	2016-12-17 10:30:06.000000000 +0000
+++ source/Plugins/Process/mach-core/ProcessMachCore.cpp
@@ -39,12 +39,15 @@
 // Needed for the plug-in names for the dynamic loaders.
 #include "lldb/Utility/SafeMachO.h"
 
+#include "llvm/Support/Threading.h"
+
 #include "Plugins/DynamicLoader/Darwin-Kernel/DynamicLoaderDarwinKernel.h"
 #include "Plugins/DynamicLoader/MacOSX-DYLD/DynamicLoaderMacOSXDYLD.h"
 #include "Plugins/ObjectFile/Mach-O/ObjectFileMachO.h"
 
 using namespace lldb;
 using namespace lldb_private;
+using namespace llvm;
 
 ConstString ProcessMachCore::GetPluginNameStatic() {
   static ConstString g_name("mach-o-core");
@@ -579,9 +582,9 @@ Error ProcessMachCore::GetMemoryRegionIn
 void ProcessMachCore::Clear() { m_thread_list.Clear(); }
 
 void ProcessMachCore::Initialize() {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(), CreateInstance);
   });
