$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/Asm/x86/7zAsm.asm.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/Asm/x86/7zAsm.asm
@@ -1,5 +1,5 @@
 ; 7zAsm.asm -- ASM macros
-; 2022-05-16 : Igor Pavlov : Public domain
+; 2023-12-08 : Igor Pavlov : Public domain
 
 
 ; UASM can require these changes
@@ -43,7 +43,7 @@ else
 endif
 endif
 
-OPTION PROLOGUE:NONE 
+OPTION PROLOGUE:NONE
 OPTION EPILOGUE:NONE
 
 MY_ASM_START macro
@@ -52,7 +52,7 @@ MY_ASM_START macro
   else
     .386
     .model flat
-    SEVENZ SEGMENT PARA PUBLIC 'CODE'
+    _TEXT$00 SEGMENT PARA PUBLIC 'CODE'
   endif
 endm
 
@@ -121,10 +121,29 @@ endif
   x2_H equ DH
   x3_H equ BH
 
+;  r0_L equ AL
+;  r1_L equ CL
+;  r2_L equ DL
+;  r3_L equ BL
+
+;  r0_H equ AH
+;  r1_H equ CH
+;  r2_H equ DH
+;  r3_H equ BH
+
+
 ifdef x64
   x5_L equ BPL
   x6_L equ SIL
   x7_L equ DIL
+  x8_L equ r8b
+  x9_L equ r9b
+  x10_L equ r10b
+  x11_L equ r11b
+  x12_L equ r12b
+  x13_L equ r13b
+  x14_L equ r14b
+  x15_L equ r15b
 
   r0 equ RAX
   r1 equ RCX
@@ -153,6 +172,22 @@ else
   r7 equ x7
 endif
 
+  x0_R equ r0
+  x1_R equ r1
+  x2_R equ r2
+  x3_R equ r3
+  x4_R equ r4
+  x5_R equ r5
+  x6_R equ r6
+  x7_R equ r7
+  x8_R equ r8
+  x9_R equ r9
+  x10_R equ r10
+  x11_R equ r11
+  x12_R equ r12
+  x13_R equ r13
+  x14_R equ r14
+  x15_R equ r15
 
 ifdef x64
 ifdef ABI_LINUX
@@ -200,6 +235,14 @@ REG_ABI_PARAM_0   equ REG_PARAM_0
 REG_ABI_PARAM_1_x equ REG_PARAM_1_x
 REG_ABI_PARAM_1   equ REG_PARAM_1
 
+MY_PUSH_PRESERVED_ABI_REGS_UP_TO_INCLUDING_R11 macro
+        MY_PUSH_4_REGS
+endm
+
+MY_POP_PRESERVED_ABI_REGS_UP_TO_INCLUDING_R11 macro
+        MY_POP_4_REGS
+endm
+
 else
 ; x64
 
@@ -261,12 +304,25 @@ endm
 endif ; IS_LINUX
 
 
-MY_PUSH_PRESERVED_ABI_REGS macro
+MY_PUSH_PRESERVED_ABI_REGS_UP_TO_INCLUDING_R11 macro
     if  (IS_LINUX gt 0)
         MY_PUSH_2_REGS
     else
         MY_PUSH_4_REGS
     endif
+endm
+
+MY_POP_PRESERVED_ABI_REGS_UP_TO_INCLUDING_R11 macro
+    if  (IS_LINUX gt 0)
+        MY_POP_2_REGS
+    else
+        MY_POP_4_REGS
+    endif
+endm
+
+
+MY_PUSH_PRESERVED_ABI_REGS macro
+    MY_PUSH_PRESERVED_ABI_REGS_UP_TO_INCLUDING_R11
         push    r12
         push    r13
         push    r14
@@ -279,11 +335,7 @@ MY_POP_PRESERVED_ABI_REGS macro
         pop     r14
         pop     r13
         pop     r12
-    if  (IS_LINUX gt 0)
-        MY_POP_2_REGS
-    else
-        MY_POP_4_REGS
-    endif
+    MY_POP_PRESERVED_ABI_REGS_UP_TO_INCLUDING_R11
 endm
 
 endif ; x64
