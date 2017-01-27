$NetBSD$

--- source/Plugins/ScriptInterpreter/Python/ScriptInterpreterPython.cpp.orig	2016-12-17 10:29:36.000000000 +0000
+++ source/Plugins/ScriptInterpreter/Python/ScriptInterpreterPython.cpp
@@ -51,9 +51,11 @@
 
 #include "llvm/ADT/STLExtras.h"
 #include "llvm/ADT/StringRef.h"
+#include "llvm/Support/Threading.h"
 
 using namespace lldb;
 using namespace lldb_private;
+using namespace llvm;
 
 static ScriptInterpreterPython::SWIGInitCallback g_swig_init_callback = nullptr;
 static ScriptInterpreterPython::SWIGBreakpointCallbackFunction
@@ -338,9 +340,9 @@ ScriptInterpreterPython::~ScriptInterpre
 }
 
 void ScriptInterpreterPython::Initialize() {
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     PluginManager::RegisterPlugin(GetPluginNameStatic(),
                                   GetPluginDescriptionStatic(),
                                   lldb::eScriptLanguagePython, CreateInstance);
