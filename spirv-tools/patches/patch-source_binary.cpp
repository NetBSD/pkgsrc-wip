$NetBSD$

The symbol for FPEncoding is provided by the grammar of spirv-headers in
version 1.3.296. But it is not handle in the latest stable version of
spirv-tools.

--- source/binary.cpp.orig	2024-11-30 21:08:50.580118424 +0000
+++ source/binary.cpp
@@ -671,6 +671,8 @@ spv_result_t Parser::parseOperand(size_t
     case SPV_OPERAND_TYPE_OVERFLOW_MODES:
     case SPV_OPERAND_TYPE_PACKED_VECTOR_FORMAT:
     case SPV_OPERAND_TYPE_OPTIONAL_PACKED_VECTOR_FORMAT:
+    case SPV_OPERAND_TYPE_FPENCODING:
+    case SPV_OPERAND_TYPE_OPTIONAL_FPENCODING:
     case SPV_OPERAND_TYPE_NAMED_MAXIMUM_NUMBER_OF_REGISTERS: {
       // A single word that is a plain enum value.
 
@@ -679,6 +681,8 @@ spv_result_t Parser::parseOperand(size_t
         parsed_operand.type = SPV_OPERAND_TYPE_ACCESS_QUALIFIER;
       if (type == SPV_OPERAND_TYPE_OPTIONAL_PACKED_VECTOR_FORMAT)
         parsed_operand.type = SPV_OPERAND_TYPE_PACKED_VECTOR_FORMAT;
+      if (type == SPV_OPERAND_TYPE_OPTIONAL_FPENCODING)
+        parsed_operand.type = SPV_OPERAND_TYPE_FPENCODING;
 
       spv_operand_desc entry;
       if (grammar_.lookupOperand(type, word, &entry)) {
