$NetBSD$

--- source/Plugins/ScriptInterpreter/None/ScriptInterpreterNone.cpp.orig	2017-02-02 23:56:41.000000000 +0000
+++ source/Plugins/ScriptInterpreter/None/ScriptInterpreterNone.cpp
@@ -15,6 +15,8 @@
 #include "lldb/Interpreter/CommandInterpreter.h"
 #include "lldb/Utility/Stream.h"
 
+#include "llvm/Support/Threading.h"
+
 #include <mutex>
 
 using namespace lldb;
@@ -39,9 +41,9 @@ void ScriptInterpreterNone::ExecuteInter
 }
 
 void ScriptInterpreterNone::Initialize() {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(),
                                   lldb::eScriptLanguageNone, CreateInstance);
