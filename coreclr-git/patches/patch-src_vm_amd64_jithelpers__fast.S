$NetBSD$

--- src/vm/amd64/jithelpers_fast.S.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/amd64/jithelpers_fast.S
@@ -19,7 +19,7 @@ LEAF_END JIT_PatchedCodeStart, _TEXT
 LEAF_ENTRY JIT_WriteBarrier, _TEXT
 #ifdef _DEBUG
         // In debug builds, this just contains jump to the debug version of the write barrier by default
-        jmp C_FUNC(JIT_WriteBarrier_Debug)
+        jmp EXTERNAL_C_FUNC(JIT_WriteBarrier_Debug)
 #endif
 
         // Do the move into the GC .  It is correct to take an AV here, the EH code
