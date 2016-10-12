$NetBSD$

--- assembler/assembler/MIPSAssembler.h.orig	2014-10-10 18:31:12.000000000 +0000
+++ assembler/assembler/MIPSAssembler.h
@@ -226,7 +226,10 @@ public:
 
     void nop()
     {
-        emitInst(0x00000000);
+       /* nop is insufficient for eliminating hazards
+        * in a superscalar CPU. blindly convert all to
+        * MIPSNNR6 ehb / ssnop, at a performance cost. */
+        emitInst(0x000000c0);
     }
 
     /* Need to insert one load data delay nop for mips1.  */
