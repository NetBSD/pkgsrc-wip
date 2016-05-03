$NetBSD$

--- src/vm/amd64/jithelpers_fastwritebarriers.S.orig	2016-05-03 01:25:01.000000000 +0000
+++ src/vm/amd64/jithelpers_fastwritebarriers.S
@@ -32,7 +32,7 @@ PATCH_LABEL JIT_WriteBarrier_PreGrow64_P
         movabs  rax, 0xF0F0F0F0F0F0F0F0
 
         // Touch the card table entry, if not already dirty.
-        shr     rdi, 0Bh
+        shr     rdi, 0x0B
         cmp     byte ptr [rdi + rax], 0FFh
         .byte 0x75, 0x02
         // jne     UpdateCardTable_PreGrow64
@@ -87,7 +87,7 @@ PATCH_LABEL JIT_WriteBarrier_PostGrow64_
         movabs  rax, 0xF0F0F0F0F0F0F0F0
 
         // Touch the card table entry, if not already dirty.
-        shr     rdi, 0Bh
+        shr     rdi, 0x0B
         cmp     byte ptr [rdi + rax], 0FFh
         .byte 0x75, 0x02
         // jne     UpdateCardTable_PostGrow64
@@ -125,7 +125,7 @@ LEAF_ENTRY JIT_WriteBarrier_SVR64, _TEXT
 PATCH_LABEL JIT_WriteBarrier_SVR64_PatchLabel_CardTable
         movabs  rax, 0xF0F0F0F0F0F0F0F0
 
-        shr     rdi, 0Bh
+        shr     rdi, 0x0B
 
         cmp     byte ptr [rdi + rax], 0FFh
         .byte 0x75, 0x02
@@ -178,7 +178,7 @@ PATCH_LABEL JIT_WriteBarrier_WriteWatch_
         // jb      Exit_WriteWatch_PreGrow64
 
         // Touch the card table entry, if not already dirty.
-        shr     rdi, 0Bh
+        shr     rdi, 0x0B
         NOP_2_BYTE // padding for alignment of constant
 PATCH_LABEL JIT_WriteBarrier_WriteWatch_PreGrow64_Patch_Label_CardTable
         movabs  rax, 0xF0F0F0F0F0F0F0F0
@@ -249,7 +249,7 @@ PATCH_LABEL JIT_WriteBarrier_WriteWatch_
         movabs  rax, 0xF0F0F0F0F0F0F0F0
 
         // Touch the card table entry, if not already dirty.
-        shr     rdi, 0Bh
+        shr     rdi, 0x0B
         cmp     byte ptr [rdi + rax], 0FFh
         .byte 0x75, 0x02
         // jne     UpdateCardTable_WriteWatch_PostGrow64
@@ -304,7 +304,7 @@ PATCH_LABEL JIT_WriteBarrier_WriteWatch_
         mov     byte ptr [rax], 0FFh
 
     CheckCardTable_WriteWatch_SVR64:
-        shr     rdi, 0Bh
+        shr     rdi, 0x0B
         cmp     byte ptr [rdi + r11], 0FFh
         .byte 0x75, 0x02
         // jne     UpdateCardTable_WriteWatch_SVR64
