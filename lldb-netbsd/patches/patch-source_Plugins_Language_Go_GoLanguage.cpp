$NetBSD$

--- source/Plugins/Language/Go/GoLanguage.cpp.orig	2017-02-04 18:35:34.000000000 +0000
+++ source/Plugins/Language/Go/GoLanguage.cpp
@@ -15,6 +15,7 @@
 
 // Other libraries and framework includes
 #include "llvm/ADT/StringRef.h"
+#include "llvm/Support/Threading.h"
 
 // Project includes
 #include "GoLanguage.h"
@@ -62,10 +63,10 @@ Language *GoLanguage::CreateInstance(lld
 
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
@@ -104,10 +105,10 @@ GoLanguage::GetHardcodedSummaries() {
 
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
