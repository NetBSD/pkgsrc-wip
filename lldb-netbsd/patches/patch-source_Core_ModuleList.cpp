$NetBSD$

--- source/Core/ModuleList.cpp.orig	2016-12-17 10:30:30.000000000 +0000
+++ source/Core/ModuleList.cpp
@@ -26,6 +26,8 @@
 #include "lldb/Symbol/SymbolFile.h"
 #include "lldb/Symbol/VariableList.h"
 
+#include "llvm/Support/Threading.h"
+
 using namespace lldb;
 using namespace lldb_private;
 
@@ -644,8 +646,8 @@ size_t ModuleList::GetIndexForModule(con
 
 static ModuleList &GetSharedModuleList() {
   static ModuleList *g_shared_module_list = nullptr;
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  static llvm::once_flag g_once_flag;
+  llvm::call_once(g_once_flag, []() {
     // NOTE: Intentionally leak the module list so a program doesn't have to
     // cleanup all modules and object files as it exits. This just wastes time
     // doing a bunch of cleanup that isn't required.
