$NetBSD$

--- source/Plugins/Process/minidump/ProcessMinidump.cpp.orig	2016-12-17 10:29:54.000000000 +0000
+++ source/Plugins/Process/minidump/ProcessMinidump.cpp
@@ -25,11 +25,14 @@
 #include "lldb/Target/UnixSignals.h"
 #include "lldb/Utility/LLDBAssert.h"
 
+#include "llvm/Support/Threading.h"
+
 // C includes
 // C++ includes
 
 using namespace lldb_private;
 using namespace minidump;
+using namespace llvm;
 
 ConstString ProcessMinidump::GetPluginNameStatic() {
   static ConstString g_name("minidump");
@@ -92,9 +95,9 @@ ProcessMinidump::~ProcessMinidump() {
 }
 
 void ProcessMinidump::Initialize() {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(),
                                   ProcessMinidump::CreateInstance);
