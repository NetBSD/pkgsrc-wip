$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Bra.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Bra.h
@@ -1,64 +1,105 @@
 /* Bra.h -- Branch converters for executables
-2013-01-18 : Igor Pavlov : Public domain */
+2024-01-20 : Igor Pavlov : Public domain */
 
-#ifndef __BRA_H
-#define __BRA_H
+#ifndef ZIP7_INC_BRA_H
+#define ZIP7_INC_BRA_H
 
 #include "7zTypes.h"
 
 EXTERN_C_BEGIN
 
-/*
-These functions convert relative addresses to absolute addresses
-in CALL instructions to increase the compression ratio.
-  
-  In:
-    data     - data buffer
-    size     - size of data
-    ip       - current virtual Instruction Pinter (IP) value
-    state    - state variable for x86 converter
-    encoding - 0 (for decoding), 1 (for encoding)
-  
-  Out:
-    state    - state variable for x86 converter
+/* #define PPC BAD_PPC_11 // for debug */
+
+#define Z7_BRANCH_CONV_DEC_2(name)  z7_ ## name ## _Dec
+#define Z7_BRANCH_CONV_ENC_2(name)  z7_ ## name ## _Enc
+#define Z7_BRANCH_CONV_DEC(name)    Z7_BRANCH_CONV_DEC_2(BranchConv_ ## name)
+#define Z7_BRANCH_CONV_ENC(name)    Z7_BRANCH_CONV_ENC_2(BranchConv_ ## name)
+#define Z7_BRANCH_CONV_ST_DEC(name) z7_BranchConvSt_ ## name ## _Dec
+#define Z7_BRANCH_CONV_ST_ENC(name) z7_BranchConvSt_ ## name ## _Enc
+
+#define Z7_BRANCH_CONV_DECL(name)    Byte * name(Byte *data, SizeT size, UInt32 pc)
+#define Z7_BRANCH_CONV_ST_DECL(name) Byte * name(Byte *data, SizeT size, UInt32 pc, UInt32 *state)
+
+typedef Z7_BRANCH_CONV_DECL(   (*z7_Func_BranchConv));
+typedef Z7_BRANCH_CONV_ST_DECL((*z7_Func_BranchConvSt));
+
+#define Z7_BRANCH_CONV_ST_X86_STATE_INIT_VAL 0
+Z7_BRANCH_CONV_ST_DECL (Z7_BRANCH_CONV_ST_DEC(X86));
+Z7_BRANCH_CONV_ST_DECL (Z7_BRANCH_CONV_ST_ENC(X86));
+
+#define Z7_BRANCH_FUNCS_DECL(name) \
+Z7_BRANCH_CONV_DECL (Z7_BRANCH_CONV_DEC_2(name)); \
+Z7_BRANCH_CONV_DECL (Z7_BRANCH_CONV_ENC_2(name));
+
+Z7_BRANCH_FUNCS_DECL (BranchConv_ARM64)
+Z7_BRANCH_FUNCS_DECL (BranchConv_ARM)
+Z7_BRANCH_FUNCS_DECL (BranchConv_ARMT)
+Z7_BRANCH_FUNCS_DECL (BranchConv_PPC)
+Z7_BRANCH_FUNCS_DECL (BranchConv_SPARC)
+Z7_BRANCH_FUNCS_DECL (BranchConv_IA64)
+Z7_BRANCH_FUNCS_DECL (BranchConv_RISCV)
 
-  Returns:
-    The number of processed bytes. If you call these functions with multiple calls,
-    you must start next call with first byte after block of processed bytes.
+/*
+These functions convert data that contain CPU instructions.
+Each such function converts relative addresses to absolute addresses in some
+branch instructions: CALL (in all converters) and JUMP (X86 converter only).
+Such conversion allows to increase compression ratio, if we compress that data.
+
+There are 2 types of converters:
+  Byte * Conv_RISC (Byte *data, SizeT size, UInt32 pc);
+  Byte * ConvSt_X86(Byte *data, SizeT size, UInt32 pc, UInt32 *state);
+Each Converter supports 2 versions: one for encoding
+and one for decoding (_Enc/_Dec postfixes in function name).
+
+In params:
+  data  : data buffer
+  size  : size of data
+  pc    : current virtual Program Counter (Instruction Pointer) value
+In/Out param:
+  state : pointer to state variable (for X86 converter only)
+
+Return:
+  The pointer to position in (data) buffer after last byte that was processed.
+  If the caller calls converter again, it must call it starting with that position.
+  But the caller is allowed to move data in buffer. So pointer to
+  current processed position also will be changed for next call.
+  Also the caller must increase internal (pc) value for next call.
   
+Each converter has some characteristics: Endian, Alignment, LookAhead.
   Type   Endian  Alignment  LookAhead
   
-  x86    little      1          4
+  X86    little      1          4
   ARMT   little      2          2
+  RISCV  little      2          6
   ARM    little      4          0
+  ARM64  little      4          0
   PPC     big        4          0
   SPARC   big        4          0
   IA64   little     16          0
 
-  size must be >= Alignment + LookAhead, if it's not last block.
-  If (size < Alignment + LookAhead), converter returns 0.
-
-  Example:
-
-    UInt32 ip = 0;
-    for ()
-    {
-      ; size must be >= Alignment + LookAhead, if it's not last block
-      SizeT processed = Convert(data, size, ip, 1);
-      data += processed;
-      size -= processed;
-      ip += processed;
-    }
+  (data) must be aligned for (Alignment).
+  processed size can be calculated as:
+    SizeT processed = Conv(data, size, pc) - data;
+  if (processed == 0)
+    it means that converter needs more data for processing.
+  If (size < Alignment + LookAhead)
+    then (processed == 0) is allowed.
+
+Example code for conversion in loop:
+  UInt32 pc = 0;
+  size = 0;
+  for (;;)
+  {
+    size += Load_more_input_data(data + size);
+    SizeT processed = Conv(data, size, pc) - data;
+    if (processed == 0 && no_more_input_data_after_size)
+      break; // we stop convert loop
+    data += processed;
+    size -= processed;
+    pc += processed;
+  }
 */
 
-#define x86_Convert_Init(state) { state = 0; }
-SizeT x86_Convert(Byte *data, SizeT size, UInt32 ip, UInt32 *state, int encoding);
-SizeT ARM_Convert(Byte *data, SizeT size, UInt32 ip, int encoding);
-SizeT ARMT_Convert(Byte *data, SizeT size, UInt32 ip, int encoding);
-SizeT PPC_Convert(Byte *data, SizeT size, UInt32 ip, int encoding);
-SizeT SPARC_Convert(Byte *data, SizeT size, UInt32 ip, int encoding);
-SizeT IA64_Convert(Byte *data, SizeT size, UInt32 ip, int encoding);
-
 EXTERN_C_END
 
 #endif
