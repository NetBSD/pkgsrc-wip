$NetBSD$

--- source/Plugins/ScriptInterpreter/Python/ScriptInterpreterPython.cpp.orig	2017-02-05 16:52:24.757230241 +0000
+++ source/Plugins/ScriptInterpreter/Python/ScriptInterpreterPython.cpp
@@ -326,9 +326,9 @@ ScriptInterpreterPython::~ScriptInterpre
 }
 
 void ScriptInterpreterPython::Initialize() {
-  static std::once_flag g_once_flag;
+  static llvm::once_flag g_once_flag;
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(),
                                   lldb::eScriptLanguagePython, CreateInstance);
