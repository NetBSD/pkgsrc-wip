$NetBSD$

--- source/Plugins/Language/Java/JavaLanguage.cpp.orig	2016-10-19 22:25:12.000000000 +0000
+++ source/Plugins/Language/Java/JavaLanguage.cpp
@@ -15,6 +15,7 @@
 
 // Other libraries and framework includes
 #include "llvm/ADT/StringRef.h"
+#include "llvm/Support/Threading.h"
 
 // Project includes
 #include "JavaFormatterFunctions.h"
@@ -28,6 +29,7 @@
 using namespace lldb;
 using namespace lldb_private;
 using namespace lldb_private::formatters;
+using namespace llvm;
 
 void JavaLanguage::Initialize() {
   PluginManager::RegisterPlugin(GetPluginNameStatic(), "Java Language",
@@ -64,10 +66,10 @@ bool JavaLanguage::IsNilReference(ValueO
 }
 
 lldb::TypeCategoryImplSP JavaLanguage::GetFormatters() {
-  static std::once_flag g_initialize;
+  LLVM_DEFINE_ONCE_FLAG(g_initialize);
   static TypeCategoryImplSP g_category;
 
-  std::call_once(g_initialize, [this]() -> void {
+  llvm::call_once(g_initialize, [this]() -> void {
     DataVisualization::Categories::GetCategory(GetPluginName(), g_category);
     if (g_category) {
       llvm::StringRef array_regexp("^.*\\[\\]&?$");
