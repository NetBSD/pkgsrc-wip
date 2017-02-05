$NetBSD$

--- source/Symbol/ClangASTContext.cpp.orig	2017-02-02 23:56:41.000000000 +0000
+++ source/Symbol/ClangASTContext.cpp
@@ -14,7 +14,7 @@
 
 // C Includes
 // C++ Includes
-#include <mutex> // std::once
+#include <mutex>
 #include <string>
 #include <vector>
 
@@ -65,6 +65,7 @@
 #endif
 
 #include "llvm/Support/Signals.h"
+#include "llvm/Support/Threading.h"
 
 #include "Plugins/ExpressionParser/Clang/ClangFunctionCaller.h"
 #include "Plugins/ExpressionParser/Clang/ClangUserExpression.h"
@@ -127,8 +128,8 @@ typedef lldb_private::ThreadSafeDenseMap
 
 static ClangASTMap &GetASTMap() {
   static ClangASTMap *g_map_ptr = nullptr;
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  static llvm::once_flag g_once_flag;
+  llvm::call_once(g_once_flag, []() {
     g_map_ptr = new ClangASTMap(); // leaked on purpose to avoid spins
   });
   return *g_map_ptr;
@@ -954,8 +955,8 @@ ClangASTContext::GetBasicTypeEnumeration
   if (name) {
     typedef UniqueCStringMap<lldb::BasicType> TypeNameToBasicTypeMap;
     static TypeNameToBasicTypeMap g_type_map;
-    static std::once_flag g_once_flag;
-    std::call_once(g_once_flag, []() {
+    static llvm::once_flag g_once_flag;
+    llvm::call_once(g_once_flag, []() {
       // "void"
       g_type_map.Append(ConstString("void").GetStringRef(), eBasicTypeVoid);
 
