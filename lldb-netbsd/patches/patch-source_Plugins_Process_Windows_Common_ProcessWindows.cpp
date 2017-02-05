$NetBSD$

--- source/Plugins/Process/Windows/Common/ProcessWindows.cpp.orig	2016-12-17 10:30:06.000000000 +0000
+++ source/Plugins/Process/Windows/Common/ProcessWindows.cpp
@@ -30,6 +30,7 @@
 
 #include "llvm/Support/ConvertUTF.h"
 #include "llvm/Support/Format.h"
+#include "llvm/Support/Threading.h"
 #include "llvm/Support/raw_ostream.h"
 
 #include "DebuggerThread.h"
@@ -102,9 +103,9 @@ ProcessSP ProcessWindows::CreateInstance
 }
 
 void ProcessWindows::Initialize() {
-  static std::once_flag g_once_flag;
+  static llvm::once_flag g_once_flag;
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(), CreateInstance);
   });
