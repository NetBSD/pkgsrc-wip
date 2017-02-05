$NetBSD$

--- source/Plugins/Process/minidump/ProcessMinidump.cpp.orig	2016-12-17 10:29:54.000000000 +0000
+++ source/Plugins/Process/minidump/ProcessMinidump.cpp
@@ -25,6 +25,8 @@
 #include "lldb/Target/UnixSignals.h"
 #include "lldb/Utility/LLDBAssert.h"
 
+#include "llvm/Support/Threading.h"
+
 // C includes
 // C++ includes
 
@@ -92,9 +94,9 @@ ProcessMinidump::~ProcessMinidump() {
 }
 
 void ProcessMinidump::Initialize() {
-  static std::once_flag g_once_flag;
+  static llvm::once_flag g_once_flag;
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(),
                                   ProcessMinidump::CreateInstance);
