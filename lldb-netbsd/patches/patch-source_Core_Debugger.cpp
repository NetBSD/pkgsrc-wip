$NetBSD$

--- source/Core/Debugger.cpp.orig	2017-02-04 18:35:35.000000000 +0000
+++ source/Core/Debugger.cpp
@@ -17,6 +17,7 @@
 // Other libraries and framework includes
 #include "llvm/ADT/StringRef.h"
 #include "llvm/Support/DynamicLibrary.h"
+#include "llvm/Support/Threading.h"
 
 // Project includes
 #include "lldb/Core/FormatEntity.h"
@@ -762,7 +763,7 @@ void Debugger::Clear() {
   //     static void Debugger::Destroy(lldb::DebuggerSP &debugger_sp);
   //     static void Debugger::Terminate();
   //----------------------------------------------------------------------
-  std::call_once(m_clear_once, [this]() {
+  llvm::call_once(m_clear_once, [this]() {
     ClearIOHandlers();
     StopIOHandlerThread();
     StopEventHandlerThread();
