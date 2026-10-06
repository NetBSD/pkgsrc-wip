$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/Asm/x86/LzmaDecOpt.asm.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/Asm/x86/LzmaDecOpt.asm
@@ -1,5 +1,5 @@
 ; LzmaDecOpt.asm -- ASM version of LzmaDec_DecodeReal_3() function
-; 2021-02-23: Igor Pavlov : Public domain
+; 2024-06-18: Igor Pavlov : Public domain
 ;
 ; 3 - is the code compatibility version of LzmaDec_DecodeReal_*()
 ; function for check at link time.
@@ -17,11 +17,43 @@ include 7zAsm.asm
 
 MY_ASM_START
 
-LZMADEC SEGMENT ALIGN(64) 'CODE'
+; if Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT is     defined, we use additional SEGMENT with 64-byte alignment.
+; if Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT is not defined, we use default SEGMENT (where default 16-byte alignment of segment is expected).
+; The performance is almost identical in our tests.
+; But the performance can depend from position of lzmadec code inside instruction cache
+; or micro-op cache line (depending from low address bits in 32-byte/64-byte cache lines).
+; And 64-byte alignment provides a more consistent speed regardless
+; of the code's position in the executable.
+; But also it's possible that code without Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT can be
+; slightly faster than 64-bytes aligned code in some cases, if offset of lzmadec
+; code in 64-byte block after compilation provides better speed by some reason.
+; Note that Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT adds an extra section to the ELF file.
+; If you don't want to get that extra section, do not define Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT.
+
+ifndef Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT
+if (IS_LINUX gt 0)
+  Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT equ 1
+else
+  Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT equ 1
+endif
+endif
 
+ifdef Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT
+; Make this deterministic
+; _TEXT$LZMADECOPT SEGMENT ALIGN(64) 'CODE'
+LZMADEC SEGMENT ALIGN(64) 'CODE'
 MY_ALIGN macro num:req
         align  num
+        ; align  16
 endm
+else
+MY_ALIGN macro num:req
+        ; We expect that ".text" is aligned for 16-bytes.
+        ; So we don't need large alignment inside out function.
+        align  16
+endm
+endif
+
 
 MY_ALIGN_16 macro
         MY_ALIGN 16
@@ -610,7 +642,11 @@ PARAM_lzma      equ REG_ABI_PARAM_0
 PARAM_limit     equ REG_ABI_PARAM_1
 PARAM_bufLimit  equ REG_ABI_PARAM_2
 
+ifdef Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT
 ; MY_ALIGN_64
+else
+  MY_ALIGN_16
+endif
 MY_PROC LzmaDec_DecodeReal_3, 3
 MY_PUSH_PRESERVED_ABI_REGS
 
@@ -1298,6 +1334,8 @@ fin:
 MY_POP_PRESERVED_ABI_REGS
 MY_ENDP
 
+ifdef Z7_LZMA_DEC_OPT_ASM_USE_SEGMENT
 LZMADEC ENDS
+endif
 
 end
