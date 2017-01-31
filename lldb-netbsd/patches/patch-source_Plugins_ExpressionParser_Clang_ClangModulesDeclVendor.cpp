$NetBSD$

--- source/Plugins/ExpressionParser/Clang/ClangModulesDeclVendor.cpp.orig	2017-01-31 17:20:57.000000000 +0000
+++ source/Plugins/ExpressionParser/Clang/ClangModulesDeclVendor.cpp
@@ -143,9 +143,9 @@ void StoringDiagnosticConsumer::DumpDiag
 static FileSpec GetResourceDir() {
   static FileSpec g_cached_resource_dir;
 
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     HostInfo::GetLLDBPath(lldb::ePathTypeClangDir, g_cached_resource_dir);
   });
 
