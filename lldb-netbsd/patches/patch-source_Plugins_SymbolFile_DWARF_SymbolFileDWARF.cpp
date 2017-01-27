$NetBSD$

--- source/Plugins/SymbolFile/DWARF/SymbolFileDWARF.cpp.orig	2016-12-17 10:29:45.000000000 +0000
+++ source/Plugins/SymbolFile/DWARF/SymbolFileDWARF.cpp
@@ -87,6 +87,7 @@
 
 using namespace lldb;
 using namespace lldb_private;
+using namespace llvm;
 
 // static inline bool
 // child_requires_parent_class_union_or_struct_to_be_completed (dw_tag_t tag)
@@ -1630,13 +1631,13 @@ SymbolFileDWARF::GlobalVariableMap &Symb
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
