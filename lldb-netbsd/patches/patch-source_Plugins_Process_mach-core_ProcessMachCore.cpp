$NetBSD$

--- source/Plugins/Process/mach-core/ProcessMachCore.cpp.orig	2016-12-17 10:30:06.000000000 +0000
+++ source/Plugins/Process/mach-core/ProcessMachCore.cpp
@@ -14,6 +14,7 @@
 
 // C++ Includes
 #include "llvm/Support/MathExtras.h"
+#include "llvm/Support/Threading.h"
 #include <mutex>
 
 // Other libraries and framework includes
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
