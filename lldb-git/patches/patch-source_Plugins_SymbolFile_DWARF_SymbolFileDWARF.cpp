$NetBSD$

--- source/Plugins/SymbolFile/DWARF/SymbolFileDWARF.cpp.orig	2016-12-14 14:10:24.000000000 +0000
+++ source/Plugins/SymbolFile/DWARF/SymbolFileDWARF.cpp
@@ -11,6 +11,7 @@
 
 // Other libraries and framework includes
 #include "llvm/Support/Casting.h"
+#include "llvm/Support/Threading.h"
 
 #include "lldb/Core/ArchSpec.h"
 #include "lldb/Core/Module.h"
@@ -553,7 +554,8 @@ uint32_t SymbolFileDWARF::CalculateAbili
 const DWARFDataExtractor &
 SymbolFileDWARF::GetCachedSectionData(lldb::SectionType sect_type,
                                       DWARFDataSegment &data_segment) {
-  std::call_once(data_segment.m_flag, &SymbolFileDWARF::LoadSectionData, this,
+  LLVM_DEFINE_ONCE_FLAG(m_flag);
+  llvm::call_once(m_flag, &SymbolFileDWARF::LoadSectionData, this,
                  sect_type, std::ref(data_segment.m_data));
   return data_segment.m_data;
 }
@@ -1630,13 +1632,13 @@ SymbolFileDWARF::GlobalVariableMap &Symb
               VariableSP var_sp = globals_sp->GetVariableAtIndex(g);
               if (var_sp && !var_sp->GetLocationIsConstantValueData()) {
                 const DWARFExpression &location = var_sp->LocationExpression();
-                Value location_result;
+                lldb_private::Value location_result;
                 Error error;
                 if (location.Evaluate(nullptr, nullptr, nullptr,
                                       LLDB_INVALID_ADDRESS, nullptr, nullptr,
                                       location_result, &error)) {
                   if (location_result.GetValueType() ==
-                      Value::eValueTypeFileAddress) {
+                      lldb_private::Value::eValueTypeFileAddress) {
                     lldb::addr_t file_addr =
                         location_result.GetScalar().ULongLong();
                     lldb::addr_t byte_size = 1;
