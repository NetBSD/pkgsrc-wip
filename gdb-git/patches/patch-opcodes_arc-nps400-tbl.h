$NetBSD$

--- opcodes/arc-nps400-tbl.h.orig	2017-09-11 11:24:05.000000000 +0000
+++ opcodes/arc-nps400-tbl.h
@@ -980,13 +980,13 @@ ASRI_LIKE (0x4, C_NPS_GIC)
 /* Atomic Operations.  */
 
 /* exc<.di><.f> a,a,[xa:b] */
-{ "exc", 0x48060c21, 0xf80fbfff, ARC_OPCODE_ARC700, NONE, NPS400, { NPS_R_DST_3B, NPS_R_SRC1_3B, BRAKET, NPS_XA, COLON, NPS_R_SRC2_3B, BRAKETdup }, { C_DI14, C_NPS_F }},
+{ "exc", 0x48060c21, 0xf80fbfff, ARC_OPCODE_ARC700, (insn_class_t)NONE, NPS400, { NPS_R_DST_3B, NPS_R_SRC1_3B, BRAKET, NPS_XA, COLON, NPS_R_SRC2_3B, BRAKETdup }, { C_DI14, C_NPS_F }},
 
 /* exc<.di><.f> a,a,[sd:b] */
-{ "exc", 0x48060c61, 0xf80fbfff, ARC_OPCODE_ARC700, NONE, NPS400, { NPS_R_DST_3B, NPS_R_SRC1_3B, BRAKET, NPS_SD, COLON, NPS_R_SRC2_3B, BRAKETdup }, { C_DI14, C_NPS_F }},
+{ "exc", 0x48060c61, 0xf80fbfff, ARC_OPCODE_ARC700, (insn_class_t)NONE, NPS400, { NPS_R_DST_3B, NPS_R_SRC1_3B, BRAKET, NPS_SD, COLON, NPS_R_SRC2_3B, BRAKETdup }, { C_DI14, C_NPS_F }},
 
 /* exc<.di><.f> a,a,[xd:b] */
-{ "exc", 0x48060c81, 0xf80fbfff, ARC_OPCODE_ARC700, NONE, NPS400, { NPS_R_DST_3B, NPS_R_SRC1_3B, BRAKET, NPS_XD, COLON, NPS_R_SRC2_3B, BRAKETdup }, { C_DI14, C_NPS_F }},
+{ "exc", 0x48060c81, 0xf80fbfff, ARC_OPCODE_ARC700, (insn_class_t)NONE, NPS400, { NPS_R_DST_3B, NPS_R_SRC1_3B, BRAKET, NPS_XD, COLON, NPS_R_SRC2_3B, BRAKETdup }, { C_DI14, C_NPS_F }},
 
 /* exc<.di><.f> a,a,[b] */
-{ "exc", 0x48060c01, 0xf80fbfff, ARC_OPCODE_ARC700, NONE, NPS400, { NPS_R_DST_3B, NPS_R_SRC1_3B, BRAKET, NPS_R_SRC2_3B, BRAKETdup }, { C_DI14, C_NPS_F }},
+{ "exc", 0x48060c01, 0xf80fbfff, ARC_OPCODE_ARC700, (insn_class_t)NONE, NPS400, { NPS_R_DST_3B, NPS_R_SRC1_3B, BRAKET, NPS_R_SRC2_3B, BRAKETdup }, { C_DI14, C_NPS_F }},
