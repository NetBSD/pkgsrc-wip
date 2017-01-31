$NetBSD$

--- source/Plugins/ScriptInterpreter/Python/ScriptInterpreterPython.cpp.orig	2017-01-31 17:20:57.000000000 +0000
+++ source/Plugins/ScriptInterpreter/Python/ScriptInterpreterPython.cpp
@@ -51,6 +51,7 @@
 
 #include "llvm/ADT/STLExtras.h"
 #include "llvm/ADT/StringRef.h"
+#include "llvm/Support/Threading.h"
 
 using namespace lldb;
 using namespace lldb_private;
@@ -338,9 +339,9 @@ ScriptInterpreterPython::~ScriptInterpre
 }
 
 void ScriptInterpreterPython::Initialize() {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(),
                                   lldb::eScriptLanguagePython, CreateInstance);
