$NetBSD$

--- gdb/mips-tdep.h.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/mips-tdep.h
@@ -126,10 +126,19 @@ enum
   MIPS_AT_REGNUM = 1,
   MIPS_V0_REGNUM = 2,		/* Function integer return value.  */
   MIPS_A0_REGNUM = 4,		/* Loc of first arg during a subr call.  */
+  MIPS_S0_REGNUM = 16,
+  MIPS_S1_REGNUM = 17,
   MIPS_S2_REGNUM = 18,		/* Contains return address in MIPS16 thunks. */
+  MIPS_S3_REGNUM = 19,
+  MIPS_S4_REGNUM = 20,
+  MIPS_S5_REGNUM = 21,
+  MIPS_S6_REGNUM = 22,
+  MIPS_S7_REGNUM = 23,
+  MIPS_T8_REGNUM = 24,
   MIPS_T9_REGNUM = 25,		/* Contains address of callee in PIC.  */
   MIPS_GP_REGNUM = 28,
   MIPS_SP_REGNUM = 29,
+  MIPS_S8_REGNUM = 30,
   MIPS_RA_REGNUM = 31,
   MIPS_PS_REGNUM = 32,		/* Contains processor status.  */
   MIPS_EMBED_LO_REGNUM = 33,
