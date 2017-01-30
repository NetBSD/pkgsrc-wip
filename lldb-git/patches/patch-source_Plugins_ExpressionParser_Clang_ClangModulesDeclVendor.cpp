$NetBSD$

--- source/Plugins/ExpressionParser/Clang/ClangModulesDeclVendor.cpp.orig	2017-01-28 19:35:15.000000000 +0000
+++ source/Plugins/ExpressionParser/Clang/ClangModulesDeclVendor.cpp
@@ -35,6 +35,7 @@
 #include "lldb/Utility/LLDBAssert.h"
 
 using namespace lldb_private;
+using namespace llvm;
 
 namespace {
 // Any Clang compiler requires a consumer for diagnostics.  This one stores them
@@ -143,9 +144,9 @@ void StoringDiagnosticConsumer::DumpDiag
 static FileSpec GetResourceDir() {
   static FileSpec g_cached_resource_dir;
 
-  static std::once_flag g_once_flag;
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
 
-  std::call_once(g_once_flag, []() {
+  llvm::call_once(g_once_flag, []() {
     HostInfo::GetLLDBPath(lldb::ePathTypeClangDir, g_cached_resource_dir);
   });
 
