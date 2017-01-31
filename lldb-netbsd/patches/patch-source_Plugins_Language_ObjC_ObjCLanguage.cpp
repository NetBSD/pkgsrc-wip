$NetBSD$

--- source/Plugins/Language/ObjC/ObjCLanguage.cpp.orig	2016-12-17 10:29:29.000000000 +0000
+++ source/Plugins/Language/ObjC/ObjCLanguage.cpp
@@ -857,10 +857,10 @@ static void LoadCoreMediaFormatters(Type
 }
 
 lldb::TypeCategoryImplSP ObjCLanguage::GetFormatters() {
-  static std::once_flag g_initialize;
+  LLVM_DEFINE_ONCE_FLAG(g_initialize);
   static TypeCategoryImplSP g_category;
 
-  std::call_once(g_initialize, [this]() -> void {
+  llvm::call_once(g_initialize, [this]() -> void {
     DataVisualization::Categories::GetCategory(GetPluginName(), g_category);
     if (g_category) {
       LoadCoreMediaFormatters(g_category);
