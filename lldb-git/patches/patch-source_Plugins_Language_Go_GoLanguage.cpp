$NetBSD$

--- source/Plugins/Language/Go/GoLanguage.cpp.orig	2016-09-10 17:36:23.000000000 +0000
+++ source/Plugins/Language/Go/GoLanguage.cpp
@@ -62,10 +62,10 @@ Language *GoLanguage::CreateInstance(lld
 
 HardcodedFormatters::HardcodedSummaryFinder
 GoLanguage::GetHardcodedSummaries() {
-  static std::once_flag g_initialize;
+  LLVM_DEFINE_ONCE_FLAG(g_initialize);
   static HardcodedFormatters::HardcodedSummaryFinder g_formatters;
 
-  std::call_once(g_initialize, []() -> void {
+  llvm::call_once(g_initialize, []() -> void {
     g_formatters.push_back(
         [](lldb_private::ValueObject &valobj, lldb::DynamicValueType,
            FormatManager &) -> TypeSummaryImpl::SharedPointer {
@@ -104,10 +104,10 @@ GoLanguage::GetHardcodedSummaries() {
 
 HardcodedFormatters::HardcodedSyntheticFinder
 GoLanguage::GetHardcodedSynthetics() {
-  static std::once_flag g_initialize;
+  LLVM_DEFINE_ONCE_FLAG(g_initialize);
   static HardcodedFormatters::HardcodedSyntheticFinder g_formatters;
 
-  std::call_once(g_initialize, []() -> void {
+  llvm::call_once(g_initialize, []() -> void {
     g_formatters.push_back(
         [](lldb_private::ValueObject &valobj, lldb::DynamicValueType,
            FormatManager &fmt_mgr) -> SyntheticChildren::SharedPointer {
