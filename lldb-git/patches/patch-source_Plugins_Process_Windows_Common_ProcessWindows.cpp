$NetBSD$

--- source/Plugins/Process/Windows/Common/ProcessWindows.cpp.orig	2016-12-14 14:10:24.000000000 +0000
+++ source/Plugins/Process/Windows/Common/ProcessWindows.cpp
@@ -102,9 +102,9 @@ ProcessSP ProcessWindows::CreateInstance
 }
 
 void ProcessWindows::Initialize() {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(), CreateInstance);
   });
