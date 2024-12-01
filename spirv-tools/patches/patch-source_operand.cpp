$NetBSD$

The symbol for FPEncoding is provided by the grammar of spirv-headers in
version 1.3.296. But it is not handle in the latest stable version of
spirv-tools.

--- source/operand.cpp.orig	2024-11-30 21:05:43.754585540 +0000
+++ source/operand.cpp
@@ -252,6 +252,9 @@ const char* spvOperandTypeStr(spv_operan
       return "OpenCL.DebugInfo.100 debug operation";
     case SPV_OPERAND_TYPE_CLDEBUG100_DEBUG_IMPORTED_ENTITY:
       return "OpenCL.DebugInfo.100 debug imported entity";
+    case SPV_OPERAND_TYPE_FPENCODING:
+    case SPV_OPERAND_TYPE_OPTIONAL_FPENCODING:
+      return "FP encoding";
 
     // The next values are for values returned from an instruction, not actually
     // an operand.  So the specific strings don't matter.  But let's add them
@@ -366,6 +369,7 @@ bool spvOperandIsConcrete(spv_operand_ty
     case SPV_OPERAND_TYPE_LOAD_CACHE_CONTROL:
     case SPV_OPERAND_TYPE_STORE_CACHE_CONTROL:
     case SPV_OPERAND_TYPE_NAMED_MAXIMUM_NUMBER_OF_REGISTERS:
+    case SPV_OPERAND_TYPE_FPENCODING:
       return true;
     default:
       break;
@@ -407,6 +411,7 @@ bool spvOperandIsOptional(spv_operand_ty
     case SPV_OPERAND_TYPE_OPTIONAL_COOPERATIVE_MATRIX_OPERANDS:
     case SPV_OPERAND_TYPE_OPTIONAL_CIV:
     case SPV_OPERAND_TYPE_OPTIONAL_RAW_ACCESS_CHAIN_OPERANDS:
+    case SPV_OPERAND_TYPE_OPTIONAL_FPENCODING:
       return true;
     default:
       break;
