$NetBSD$

--- source/Plugins/Language/CPlusPlus/CPlusPlusLanguage.cpp.orig	2017-01-31 17:20:57.000000000 +0000
+++ source/Plugins/Language/CPlusPlus/CPlusPlusLanguage.cpp
@@ -33,6 +33,7 @@
 #include "lldb/DataFormatters/DataVisualization.h"
 #include "lldb/DataFormatters/FormattersHelpers.h"
 #include "lldb/DataFormatters/VectorType.h"
+#include "llvm/Support/Threading.h"
 
 #include "BlockPointer.h"
 #include "CxxStringTypes.h"
@@ -1036,10 +1037,10 @@ std::unique_ptr<Language::TypeScavenger>
 }
 
 lldb::TypeCategoryImplSP CPlusPlusLanguage::GetFormatters() {
-  static std::once_flag g_initialize;
+  LLVM_DEFINE_ONCE_FLAG(g_initialize);
   static TypeCategoryImplSP g_category;
 
-  std::call_once(g_initialize, [this]() -> void {
+  llvm::call_once(g_initialize, [this]() -> void {
     DataVisualization::Categories::GetCategory(GetPluginName(), g_category);
     if (g_category) {
       LoadLibCxxFormatters(g_category);
@@ -1052,11 +1053,11 @@ lldb::TypeCategoryImplSP CPlusPlusLangua
 
 HardcodedFormatters::HardcodedSummaryFinder
 CPlusPlusLanguage::GetHardcodedSummaries() {
-  static std::once_flag g_initialize;
+  LLVM_DEFINE_ONCE_FLAG(g_initialize);
   static ConstString g_vectortypes("VectorTypes");
   static HardcodedFormatters::HardcodedSummaryFinder g_formatters;
 
-  std::call_once(g_initialize, []() -> void {
+  llvm::call_once(g_initialize, []() -> void {
     g_formatters.push_back(
         [](lldb_private::ValueObject &valobj, lldb::DynamicValueType,
            FormatManager &) -> TypeSummaryImpl::SharedPointer {
@@ -1116,11 +1117,11 @@ CPlusPlusLanguage::GetHardcodedSummaries
 
 HardcodedFormatters::HardcodedSyntheticFinder
 CPlusPlusLanguage::GetHardcodedSynthetics() {
-  static std::once_flag g_initialize;
+  LLVM_DEFINE_ONCE_FLAG(g_initialize);
   static ConstString g_vectortypes("VectorTypes");
   static HardcodedFormatters::HardcodedSyntheticFinder g_formatters;
 
-  std::call_once(g_initialize, []() -> void {
+  llvm::call_once(g_initialize, []() -> void {
     g_formatters.push_back([](lldb_private::ValueObject &valobj,
                               lldb::DynamicValueType,
                               FormatManager &
