$NetBSD$

--- source/Symbol/ClangASTContext.cpp.orig	2017-01-31 17:20:57.000000000 +0000
+++ source/Symbol/ClangASTContext.cpp
@@ -127,8 +127,8 @@ typedef lldb_private::ThreadSafeDenseMap
 
 static ClangASTMap &GetASTMap() {
   static ClangASTMap *g_map_ptr = nullptr;
-  static std::once_flag g_once_flag;
-  std::call_once(g_once_flag, []() {
+  LLVM_DEFINE_ONCE_FLAG(g_once_flag);
+  llvm::call_once(g_once_flag, []() {
     g_map_ptr = new ClangASTMap(); // leaked on purpose to avoid spins
   });
   return *g_map_ptr;
@@ -954,8 +954,8 @@ ClangASTContext::GetBasicTypeEnumeration
   if (name) {
     typedef UniqueCStringMap<lldb::BasicType> TypeNameToBasicTypeMap;
     static TypeNameToBasicTypeMap g_type_map;
-    static std::once_flag g_once_flag;
-    std::call_once(g_once_flag, []() {
+    LLVM_DEFINE_ONCE_FLAG(g_once_flag);
+    llvm::call_once(g_once_flag, []() {
       // "void"
       g_type_map.Append(ConstString("void").GetStringRef(), eBasicTypeVoid);
 
