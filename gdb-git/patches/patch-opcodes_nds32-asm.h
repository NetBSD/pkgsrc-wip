$NetBSD$

--- opcodes/nds32-asm.h.orig	2017-09-04 13:40:58.000000000 +0000
+++ opcodes/nds32-asm.h
@@ -279,7 +279,7 @@ extern void nds32_asm_init (nds32_asm_de
 #define ALU2(sub)	(OP6 (ALU2) | N32_ALU2_ ## sub)
 #define MISC(sub)	(OP6 (MISC) | N32_MISC_ ## sub)
 #define MEM(sub)	(OP6 (MEM) | N32_MEM_ ## sub)
-#define FPU_RA_IMMBI(sub)	(OP6 (sub) | __BIT (12))
+#define FPU_RA_IMMBI(sub)	(OP6 (sub) | __ONEBIT (12))
 #define FS1(sub)	(OP6 (COP) | N32_FPU_FS1 | (N32_FPU_FS1_ ## sub << 6))
 #define FS1_F2OP(sub)	(OP6 (COP) | N32_FPU_FS1 | (N32_FPU_FS1_F2OP << 6) \
 			| (N32_FPU_FS1_F2OP_ ## sub << 10))
