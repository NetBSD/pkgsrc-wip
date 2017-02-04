$NetBSD$

--- source/Plugins/ExpressionParser/Clang/ClangModulesDeclVendor.cpp.orig	2017-02-04 18:35:34.000000000 +0000
+++ source/Plugins/ExpressionParser/Clang/ClangModulesDeclVendor.cpp
@@ -21,6 +21,7 @@
 #include "clang/Sema/Lookup.h"
 #include "clang/Serialization/ASTReader.h"
 #include "llvm/Support/Path.h"
+#include "llvm/Support/Threading.h"
 
 // Project includes
 #include "ClangModulesDeclVendor.h"
@@ -143,9 +144,9 @@ void StoringDiagnosticConsumer::DumpDiag
 static FileSpec GetResourceDir() {
   static FileSpec g_cached_resource_dir;
 
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     HostInfo::GetLLDBPath(lldb::ePathTypeClangDir, g_cached_resource_dir);
   });
 
