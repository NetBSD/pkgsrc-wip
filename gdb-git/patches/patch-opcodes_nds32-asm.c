$NetBSD$

--- opcodes/nds32-asm.c.orig	2017-09-04 13:40:58.000000000 +0000
+++ opcodes/nds32-asm.c
@@ -212,8 +212,8 @@ const field_t operand_fields[] =
   {NULL, 0, 0, 0, 0, NULL}
 };
 
-#define DEF_REG(r)		(__BIT (r))
-#define USE_REG(r)		(__BIT (r))
+#define DEF_REG(r)		(__ONEBIT (r))
+#define USE_REG(r)		(__ONEBIT (r))
 #define RT(r)			(r << 20)
 #define RA(r)			(r << 15)
 #define RB(r)			(r << 10)
@@ -252,29 +252,29 @@ struct nds32_opcode nds32_opcodes[] =
 
   /* seg-DPREFI.  */
   {"dprefi.w", "%dpref_st,[%ra{+%i15s2}]",	OP6 (DPREFI), 4, ATTR_V3MEX_V1, 0, NULL, 0, NULL},
-  {"dprefi.d", "%dpref_st,[%ra{+%i15s3}]",	OP6 (DPREFI) | __BIT (24), 4, ATTR_V3MEX_V1, 0, NULL, 0, NULL},
+  {"dprefi.d", "%dpref_st,[%ra{+%i15s3}]",	OP6 (DPREFI) | __ONEBIT (24), 4, ATTR_V3MEX_V1, 0, NULL, 0, NULL},
   /* seg-LBGP.  */
   {"lbi.gp", "=rt,[+%i19s]",	OP6 (LBGP), 4, ATTR (GPREL) | ATTR_V2UP, USE_REG (29), NULL, 0, NULL},
-  {"lbsi.gp", "=rt,[+%i19s]",	OP6 (LBGP) | __BIT (19), 4, ATTR (GPREL) | ATTR_V2UP, USE_REG (29), NULL, 0, NULL},
+  {"lbsi.gp", "=rt,[+%i19s]",	OP6 (LBGP) | __ONEBIT (19), 4, ATTR (GPREL) | ATTR_V2UP, USE_REG (29), NULL, 0, NULL},
   /* seg-LWC/0.  */
   {"cplwi", "%cp,=cprt,[%ra{+%i12s2}]",		OP6 (LWC), 4, 0, 0, NULL, 0, NULL},
-  {"cplwi.bi", "%cp,=cprt,[%ra],%i12s2",	OP6 (LWC) | __BIT (12), 4, 0, 0, NULL, 0, NULL},
+  {"cplwi.bi", "%cp,=cprt,[%ra],%i12s2",	OP6 (LWC) | __ONEBIT (12), 4, 0, 0, NULL, 0, NULL},
   /* seg-SWC/0.  */
   {"cpswi", "%cp,=cprt,[%ra{+%i12s2}]",		OP6 (SWC), 4, 0, 0, NULL, 0, NULL},
-  {"cpswi.bi", "%cp,=cprt,[%ra],%i12s2",	OP6 (SWC) | __BIT (12), 4, 0, 0, NULL, 0, NULL},
+  {"cpswi.bi", "%cp,=cprt,[%ra],%i12s2",	OP6 (SWC) | __ONEBIT (12), 4, 0, 0, NULL, 0, NULL},
   /* seg-LDC/0.  */
   {"cpldi", "%cp,%cprt,[%ra{+%i12s2}]",		OP6 (LDC), 4, 0, 0, NULL, 0, NULL},
-  {"cpldi.bi", "%cp,%cprt,[%ra],%i12s2",	OP6 (LDC) | __BIT (12), 4, 0, 0, NULL, 0, NULL},
+  {"cpldi.bi", "%cp,%cprt,[%ra],%i12s2",	OP6 (LDC) | __ONEBIT (12), 4, 0, 0, NULL, 0, NULL},
   /* seg-SDC/0.  */
   {"cpsdi", "%cp,%cprt,[%ra{+%i12s2}]",		OP6 (SDC), 4, 0, 0, NULL, 0, NULL},
-  {"cpsdi.bi", "%cp,%cprt,[%ra],%i12s2",	OP6 (SDC) | __BIT (12), 4, 0, 0, NULL, 0, NULL},
+  {"cpsdi.bi", "%cp,%cprt,[%ra],%i12s2",	OP6 (SDC) | __ONEBIT (12), 4, 0, 0, NULL, 0, NULL},
   /* seg-LSMW.  */
   {"lmw", "%abdim %rt,[%ra],%re{,%enb4}",	LSMW (LSMW), 4, ATTR_ALL, 0, NULL, 0, NULL},
   {"lmwa", "%abdim %rt,[%ra],%re{,%enb4}",	LSMW (LSMWA), 4, ATTR_V3MEX_V2, 0, NULL, 0, NULL},
   {"lmwzb", "%abm %rt,[%ra],%re{,%enb4}",	LSMW (LSMWZB), 4, ATTR (STR_EXT), 0, NULL, 0, NULL},
-  {"smw", "%abdim %rt,[%ra],%re{,%enb4}",	LSMW (LSMW) | __BIT (5), 4, ATTR_ALL, 0, NULL, 0, NULL},
-  {"smwa", "%abdim %rt,[%ra],%re{,%enb4}",	LSMW (LSMWA) | __BIT (5), 4, ATTR_V3MEX_V2, 0, NULL, 0, NULL},
-  {"smwzb", "%abm %rt,[%ra],%re{,%enb4}",	LSMW (LSMWZB) | __BIT (5), 4, ATTR (STR_EXT), 0, NULL, 0, NULL},
+  {"smw", "%abdim %rt,[%ra],%re{,%enb4}",	LSMW (LSMW) | __ONEBIT (5), 4, ATTR_ALL, 0, NULL, 0, NULL},
+  {"smwa", "%abdim %rt,[%ra],%re{,%enb4}",	LSMW (LSMWA) | __ONEBIT (5), 4, ATTR_V3MEX_V2, 0, NULL, 0, NULL},
+  {"smwzb", "%abm %rt,[%ra],%re{,%enb4}",	LSMW (LSMWZB) | __ONEBIT (5), 4, ATTR (STR_EXT), 0, NULL, 0, NULL},
   /* seg-HWGP.  */
   {"lhi.gp", "=rt,[+%i18s1]",	OP6 (HWGP), 4, ATTR (GPREL) | ATTR_V2UP, USE_REG (29), NULL, 0, NULL},
   {"lhsi.gp", "=rt,[+%i18s1]",	OP6 (HWGP) | (2 << 17), 4, ATTR (GPREL) | ATTR_V2UP, USE_REG (29), NULL, 0, NULL},
@@ -284,10 +284,10 @@ struct nds32_opcode nds32_opcodes[] =
 
   /* seg-SBGP.  */
   {"sbi.gp", "%rt,[+%i19s]",	OP6 (SBGP), 4, ATTR (GPREL) | ATTR_V2UP, USE_REG (29), NULL, 0, NULL},
-  {"addi.gp", "=rt,%i19s",	OP6 (SBGP) | __BIT (19), 4, ATTR (GPREL) | ATTR_V2UP, USE_REG (29), NULL, 0, NULL},
+  {"addi.gp", "=rt,%i19s",	OP6 (SBGP) | __ONEBIT (19), 4, ATTR (GPREL) | ATTR_V2UP, USE_REG (29), NULL, 0, NULL},
   /* seg-JI.  */
   {"j", "%i24s1",	OP6 (JI), 4, ATTR_PCREL | ATTR_ALL, 0, NULL, 0, NULL},
-  {"jal", "%i24s1",	OP6 (JI) | __BIT (24), 4, ATTR_PCREL | ATTR_ALL, 0, NULL, 0, NULL},
+  {"jal", "%i24s1",	OP6 (JI) | __ONEBIT (24), 4, ATTR_PCREL | ATTR_ALL, 0, NULL, 0, NULL},
   /* seg-JREG.  */
   {"jr", "%rb",			JREG (JR), 4, ATTR (BRANCH) | ATTR_ALL, 0, NULL, 0, NULL},
   {"jral", "%rt,%rb",		JREG (JRAL), 4, ATTR (BRANCH) | ATTR_ALL, 0, NULL, 0, NULL},
@@ -304,7 +304,7 @@ struct nds32_opcode nds32_opcodes[] =
   {"jral", "%dtiton %rb",	JREG (JRAL) | RT (30), 4, ATTR (BRANCH) | ATTR_ALL, 0, NULL, 0, NULL},
   /* seg-BR1.  */
   {"beq", "%rt,%ra,%i14s1",	OP6 (BR1), 4, ATTR_PCREL | ATTR_ALL, 0, NULL, 0, NULL},
-  {"bne", "%rt,%ra,%i14s1",	OP6 (BR1) | __BIT (14), 4, ATTR_PCREL | ATTR_ALL, 0, NULL, 0, NULL},
+  {"bne", "%rt,%ra,%i14s1",	OP6 (BR1) | __ONEBIT (14), 4, ATTR_PCREL | ATTR_ALL, 0, NULL, 0, NULL},
   /* seg-BR2.  */
 #define BR2(sub)	(OP6 (BR2) | (N32_BR2_ ## sub << 16))
   {"ifcall", "%i16s1",		BR2 (IFCALL), 4, ATTR (IFC_EXT), 0, NULL, 0, NULL},
@@ -318,7 +318,7 @@ struct nds32_opcode nds32_opcodes[] =
   {"bltzal", "%rt,%i16s1",	BR2 (BLTZAL), 4, ATTR_PCREL | ATTR_ALL, 0, NULL, 0, NULL},
   /* seg-BR3.  */
   {"beqc", "%rt,%i11br3,%i8s1",	OP6 (BR3), 4, ATTR_PCREL | ATTR_V3MUP, 0, NULL, 0, NULL},
-  {"bnec", "%rt,%i11br3,%i8s1",	OP6 (BR3) | __BIT (19), 4, ATTR_PCREL | ATTR_V3MUP, 0, NULL, 0, NULL},
+  {"bnec", "%rt,%i11br3,%i8s1",	OP6 (BR3) | __ONEBIT (19), 4, ATTR_PCREL | ATTR_V3MUP, 0, NULL, 0, NULL},
   /* seg-SIMD.  */
   {"pbsad", "%rt,%ra,%rb", SIMD (PBSAD), 4, ATTR (PERF2_EXT), 0, NULL, 0, NULL},
   {"pbsada", "%rt,%ra,%rb", SIMD (PBSADA), 4, ATTR (PERF2_EXT), 0, NULL, 0, NULL},
@@ -392,22 +392,22 @@ struct nds32_opcode nds32_opcodes[] =
 
   /* seg-ALU2_FFBI.  */
   {"ffb", "=rt,%ra,%rb",	ALU2 (FFB), 4, ATTR (STR_EXT), 0, NULL, 0, NULL},
-  {"ffbi", "=rt,%ra,%ib8u",	ALU2 (FFBI) | __BIT (6), 4, ATTR (STR_EXT), 0, NULL, 0, NULL},
+  {"ffbi", "=rt,%ra,%ib8u",	ALU2 (FFBI) | __ONEBIT (6), 4, ATTR (STR_EXT), 0, NULL, 0, NULL},
   /* seg-ALU2_FLMISM.  */
   {"ffmism", "=rt,%ra,%rb",	ALU2 (FFMISM), 4, ATTR (STR_EXT), 0, NULL, 0, NULL},
-  {"flmism", "=rt,%ra,%rb",	ALU2 (FLMISM) | __BIT (6), 4, ATTR (STR_EXT), 0, NULL, 0, NULL},
+  {"flmism", "=rt,%ra,%rb",	ALU2 (FLMISM) | __ONEBIT (6), 4, ATTR (STR_EXT), 0, NULL, 0, NULL},
   /* seg-ALU2_MULSR64.  */
   {"mults64", "=dt,%ra,%rb",	ALU2 (MULTS64), 4, ATTR_ALL, 0, NULL, 0, NULL},
-  {"mulsr64", "=rt,%ra,%rb",	ALU2 (MULSR64)| __BIT (6), 4, ATTR_V3MEX_V2, 0, NULL, 0, NULL},
+  {"mulsr64", "=rt,%ra,%rb",	ALU2 (MULSR64)| __ONEBIT (6), 4, ATTR_V3MEX_V2, 0, NULL, 0, NULL},
   /* seg-ALU2_MULR64.  */
   {"mult64", "=dt,%ra,%rb",	ALU2 (MULT64), 4, ATTR_ALL, 0, NULL, 0, NULL},
-  {"mulr64", "=rt,%ra,%rb",	ALU2 (MULR64) | __BIT (6), 4, ATTR_V3MEX_V2, 0, NULL, 0, NULL},
+  {"mulr64", "=rt,%ra,%rb",	ALU2 (MULR64) | __ONEBIT (6), 4, ATTR_V3MEX_V2, 0, NULL, 0, NULL},
   /* seg-ALU2_MADDR32.  */
   {"madd32", "=dt,%ra,%rb",	ALU2 (MADD32), 4, ATTR (MAC) | ATTR (DXREG) | ATTR_ALL, 0, NULL, 0, NULL},
-  {"maddr32", "=rt,%ra,%rb",	ALU2 (MADDR32) | __BIT (6), 4, ATTR (MAC) | ATTR_V2UP, 0, NULL, 0, NULL},
+  {"maddr32", "=rt,%ra,%rb",	ALU2 (MADDR32) | __ONEBIT (6), 4, ATTR (MAC) | ATTR_V2UP, 0, NULL, 0, NULL},
   /* seg-ALU2_MSUBR32.  */
   {"msub32", "=dt,%ra,%rb",	ALU2 (MSUB32), 4, ATTR (MAC) | ATTR (DXREG) | ATTR_ALL, 0, NULL, 0, NULL},
-  {"msubr32", "=rt,%ra,%rb",	ALU2 (MSUBR32) | __BIT (6), 4, ATTR (MAC) | ATTR_V2UP, 0, NULL, 0, NULL},
+  {"msubr32", "=rt,%ra,%rb",	ALU2 (MSUBR32) | __ONEBIT (6), 4, ATTR (MAC) | ATTR_V2UP, 0, NULL, 0, NULL},
 
   /* seg-MISC.  */
   {"standby", "%stdby_st",	MISC (STANDBY), 4, ATTR_ALL, 0, NULL, 0, NULL},
@@ -425,11 +425,11 @@ struct nds32_opcode nds32_opcodes[] =
   /* seg-MISC_MTSR.  */
   {"mtsr", "%rt,%sr",		MISC (MTSR), 4, ATTR_ALL, 0, NULL, 0, NULL},
   /* seg-MISC_SETEND.  */
-  {"setend.l", "",	MISC (MTSR) | (SRIDX (1, 0, 0) << 10) | __BIT (5), 4, ATTR_ALL, 0, NULL, 0, NULL},
-  {"setend.b", "",	MISC (MTSR) | (SRIDX (1, 0, 0) << 10) | __BIT (5) | __BIT (20), 4, ATTR_ALL, 0, NULL, 0, NULL},
+  {"setend.l", "",	MISC (MTSR) | (SRIDX (1, 0, 0) << 10) | __ONEBIT (5), 4, ATTR_ALL, 0, NULL, 0, NULL},
+  {"setend.b", "",	MISC (MTSR) | (SRIDX (1, 0, 0) << 10) | __ONEBIT (5) | __ONEBIT (20), 4, ATTR_ALL, 0, NULL, 0, NULL},
   /* seg-MISC_SETGIE.  */
-  {"setgie.d", "",	MISC (MTSR) | (SRIDX (1, 0, 0) << 10) | __BIT (6), 4, ATTR_ALL, 0, NULL, 0, NULL},
-  {"setgie.e", "",	MISC (MTSR) | (SRIDX (1, 0, 0) << 10) | __BIT (6) | __BIT (20), 4, ATTR_ALL, 0, NULL, 0, NULL},
+  {"setgie.d", "",	MISC (MTSR) | (SRIDX (1, 0, 0) << 10) | __ONEBIT (6), 4, ATTR_ALL, 0, NULL, 0, NULL},
+  {"setgie.e", "",	MISC (MTSR) | (SRIDX (1, 0, 0) << 10) | __ONEBIT (6) | __ONEBIT (20), 4, ATTR_ALL, 0, NULL, 0, NULL},
   {"mfsr", "=rt,%ridx",		MISC (MFSR), 4, ATTR_ALL, 0, NULL, 0, NULL},
   {"mtsr", "%rt,%ridx",		MISC (MTSR), 4, ATTR_ALL, 0, NULL, 0, NULL},
   {"trap", "",			MISC (TRAP), 4, ATTR_V3MEX_V1, 0, NULL, 0, NULL},
@@ -764,19 +764,19 @@ struct nds32_opcode nds32_opcodes[] =
   /* Saturation ext ISA.  */
   {"kaddw", "=rt,%ra,%rb",	ALU2 (KADD), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
   {"ksubw", "=rt,%ra,%rb",	ALU2 (KSUB), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"kaddh", "=rt,%ra,%rb",	ALU2 (KADD) | __BIT (6), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"ksubh", "=rt,%ra,%rb",	ALU2 (KSUB) | __BIT (6), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"kaddh", "=rt,%ra,%rb",	ALU2 (KADD) | __ONEBIT (6), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"ksubh", "=rt,%ra,%rb",	ALU2 (KSUB) | __ONEBIT (6), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
   {"kdmbb", "=rt,%ra,%rb",	ALU2 (KMxy), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"kdmbt", "=rt,%ra,%rb",	ALU2 (KMxy) | __BIT (6), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"kdmtb", "=rt,%ra,%rb",	ALU2 (KMxy) | __BIT (7), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"kdmtt", "=rt,%ra,%rb",	ALU2 (KMxy) | __BIT (6) | __BIT (7), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"khmbb", "=rt,%ra,%rb",	ALU2 (KMxy) | __BIT (8), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"khmbt", "=rt,%ra,%rb",	ALU2 (KMxy) | __BIT (8) | __BIT (6), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"khmtb", "=rt,%ra,%rb",	ALU2 (KMxy) | __BIT (8) | __BIT (7), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"khmtt", "=rt,%ra,%rb",	ALU2 (KMxy) | __BIT (8) | __BIT (6) | __BIT (7), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"kdmbt", "=rt,%ra,%rb",	ALU2 (KMxy) | __ONEBIT (6), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"kdmtb", "=rt,%ra,%rb",	ALU2 (KMxy) | __ONEBIT (7), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"kdmtt", "=rt,%ra,%rb",	ALU2 (KMxy) | __ONEBIT (6) | __ONEBIT (7), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"khmbb", "=rt,%ra,%rb",	ALU2 (KMxy) | __ONEBIT (8), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"khmbt", "=rt,%ra,%rb",	ALU2 (KMxy) | __ONEBIT (8) | __ONEBIT (6), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"khmtb", "=rt,%ra,%rb",	ALU2 (KMxy) | __ONEBIT (8) | __ONEBIT (7), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"khmtt", "=rt,%ra,%rb",	ALU2 (KMxy) | __ONEBIT (8) | __ONEBIT (6) | __ONEBIT (7), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
   {"kslraw", "=rt,%ra,%rb",	ALU2 (KSLRA), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"rdov", "=rt",		ALU2 (MFUSR) | __BIT (6) | ( 0x1e << 15), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
-  {"clrov", "",			ALU2 (MTUSR) | __BIT (6) | ( 0x1e << 15), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"rdov", "=rt",		ALU2 (MFUSR) | __ONEBIT (6) | ( 0x1e << 15), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
+  {"clrov", "",			ALU2 (MTUSR) | __ONEBIT (6) | ( 0x1e << 15), 4, ATTR (SATURATION_EXT), 0, NULL, 0, NULL},
 
   /* Audio ext. instructions.  */
 
