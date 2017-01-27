$NetBSD$

--- source/Plugins/ScriptInterpreter/None/ScriptInterpreterNone.cpp.orig	2016-12-17 10:29:35.000000000 +0000
+++ source/Plugins/ScriptInterpreter/None/ScriptInterpreterNone.cpp
@@ -15,10 +15,13 @@
 #include "lldb/Core/StringList.h"
 #include "lldb/Interpreter/CommandInterpreter.h"
 
+#include "llvm/Support/Threading.h"
+
 #include <mutex>
 
 using namespace lldb;
 using namespace lldb_private;
+using namespace llvm;
 
 ScriptInterpreterNone::ScriptInterpreterNone(CommandInterpreter &interpreter)
     : ScriptInterpreter(interpreter, eScriptLanguageNone) {}
@@ -39,9 +42,9 @@ void ScriptInterpreterNone::ExecuteInter
 }
 
 void ScriptInterpreterNone::Initialize() {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(),
                                   lldb::eScriptLanguageNone, CreateInstance);
