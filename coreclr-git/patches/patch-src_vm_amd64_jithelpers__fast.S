$NetBSD$

--- src/vm/amd64/jithelpers_fast.S.orig	2016-05-03 01:25:01.000000000 +0000
+++ src/vm/amd64/jithelpers_fast.S
@@ -110,7 +110,7 @@ LEAF_ENTRY JIT_WriteBarrier, _TEXT
         movabs  rax, 0xF0F0F0F0F0F0F0F0
 
         // Touch the card table entry, if not already dirty.
-        shr     rdi, 0Bh
+        shr     rdi, 0x0B
         cmp     byte ptr [rdi + rax], 0FFh
         .byte 0x75, 0x02
         // jne     UpdateCardTable
@@ -301,7 +301,7 @@ LEAF_ENTRY JIT_ByRefWriteBarrier, _TEXT
 
         // Check if we need to update the card table
         // Calc pCardByte
-        shr     rcx, 0Bh
+        shr     rcx, 0x0B
         PREPARE_EXTERNAL_VAR g_card_table, rax
         add     rcx, [rax]
 
