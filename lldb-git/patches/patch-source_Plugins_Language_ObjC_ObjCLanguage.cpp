$NetBSD$

--- source/Plugins/Language/ObjC/ObjCLanguage.cpp.orig	2017-02-02 23:56:41.000000000 +0000
+++ source/Plugins/Language/ObjC/ObjCLanguage.cpp
@@ -26,6 +26,8 @@
 #include "lldb/Utility/ConstString.h"
 #include "lldb/Utility/StreamString.h"
 
+#include "llvm/Support/Threading.h"
+
 #include "CF.h"
 #include "Cocoa.h"
 #include "CoreMedia.h"
@@ -857,10 +859,10 @@ static void LoadCoreMediaFormatters(Type
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
