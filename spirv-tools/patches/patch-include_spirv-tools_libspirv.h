$NetBSD$

The symbol for FPEncoding is provided by the grammar of spirv-headers in
version 1.3.296. But it is not handle in the latest stable version of
spirv-tools.

--- include/spirv-tools/libspirv.h.orig	2024-11-30 21:16:16.095487983 +0000
+++ include/spirv-tools/libspirv.h
@@ -175,6 +175,7 @@ typedef enum spv_operand_type_t {
   SPV_OPERAND_TYPE_KERNEL_ENQ_FLAGS,              // SPIR-V Sec 3.29
   SPV_OPERAND_TYPE_KERNEL_PROFILING_INFO,         // SPIR-V Sec 3.30
   SPV_OPERAND_TYPE_CAPABILITY,                    // SPIR-V Sec 3.31
+  SPV_OPERAND_TYPE_FPENCODING,                    // SPIR-V Sec 3.51
 
   // NOTE: New concrete enum values should be added at the end.
 
@@ -236,6 +237,8 @@ typedef enum spv_operand_type_t {
   // assemble regardless of where they occur -- literals, IDs, immediate
   // integers, etc.
   SPV_OPERAND_TYPE_OPTIONAL_CIV,
+  // An optional floating point encoding enum
+  SPV_OPERAND_TYPE_OPTIONAL_FPENCODING,
 
   // A variable operand represents zero or more logical operands.
   // In an instruction definition, this may only appear at the end of the
