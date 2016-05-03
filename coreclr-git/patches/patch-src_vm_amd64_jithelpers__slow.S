$NetBSD$

--- src/vm/amd64/jithelpers_slow.S.orig	2016-05-03 01:25:01.000000000 +0000
+++ src/vm/amd64/jithelpers_slow.S
@@ -93,7 +93,7 @@ LEAF_ENTRY JIT_WriteBarrier_Debug, _TEXT
 
         // Check if we need to update the card table
         // Calc pCardByte
-        shr     rdi, 0Bh
+        shr     rdi, 0x0B
         PREPARE_EXTERNAL_VAR g_card_table, r10
         add     rdi, [r10]
 
@@ -111,4 +111,3 @@ LEAF_ENTRY JIT_WriteBarrier_Debug, _TEXT
         REPRET
 LEAF_END_MARKED JIT_WriteBarrier_Debug, _TEXT
 #endif
-
