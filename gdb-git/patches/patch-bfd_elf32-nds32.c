$NetBSD$

--- bfd/elf32-nds32.c.orig	2017-09-04 13:40:57.000000000 +0000
+++ bfd/elf32-nds32.c
@@ -7343,7 +7343,7 @@ nds32_convert_32_to_16 (bfd *abfd, uint3
       if (!IS_WITHIN_S (N32_IMM14S (insn), 8))
 	goto done;
 
-      if ((insn & __BIT (14)) == 0)
+      if ((insn & N32_BIT (14)) == 0)
 	{
 	  /* N32_BR1_BEQ */
 	  if (N32_IS_RT3 (insn) && N32_RA5 (insn) == REG_R5
@@ -7411,7 +7411,7 @@ nds32_convert_32_to_16 (bfd *abfd, uint3
       break;
 
     case N32_OP6_JI:
-      if ((insn & __BIT (24)) == 0)
+      if ((insn & N32_BIT (24)) == 0)
 	{
 	  /* N32_JI_J */
 	  if (IS_WITHIN_S (N32_IMM24S (insn), 8))
@@ -7647,7 +7647,7 @@ nds32_convert_16_to_32 (bfd *abfd, uint1
       insn = N32_TYPE2 (SLTI, REG_TA, N16_RT4 (insn16), N16_IMM5U (insn16));
       goto done;
     case 0x34:			/* beqzs8, bnezs8 */
-      if (insn16 & __BIT (8))
+      if (insn16 & N32_BIT (8))
 	insn = N32_BR2 (BNEZ, REG_TA, N16_IMM8S (insn16));
       else
 	insn = N32_BR2 (BEQZ, REG_TA, N16_IMM8S (insn16));
@@ -7747,7 +7747,7 @@ nds32_convert_16_to_32 (bfd *abfd, uint1
   switch (__GF (insn16, 11, 4))
     {
     case 0x7:			/* lwi37.fp/swi37.fp */
-      if (insn16 & __BIT (7))	/* swi37.fp */
+      if (insn16 & N32_BIT (7))	/* swi37.fp */
 	insn = N32_TYPE2 (SWI, N16_RT38 (insn16), REG_FP, N16_IMM7U (insn16));
       else			/* lwi37.fp */
 	insn = N32_TYPE2 (LWI, N16_RT38 (insn16), REG_FP, N16_IMM7U (insn16));
@@ -7850,7 +7850,7 @@ turn_insn_to_sda_access (uint32_t insn, 
 	  break;
 	case N32_OP6_LBSI:
 	  /* lbsi.gp */
-	  oinsn = N32_TYPE1 (LBGP, N32_RT5 (insn), __BIT (19));
+	  oinsn = N32_TYPE1 (LBGP, N32_RT5 (insn), N32_BIT (19));
 	  break;
 	case N32_OP6_SBI:
 	  /* sbi.gp */
@@ -7858,7 +7858,7 @@ turn_insn_to_sda_access (uint32_t insn, 
 	  break;
 	case N32_OP6_ORI:
 	  /* addi.gp */
-	  oinsn = N32_TYPE1 (SBGP, N32_RT5 (insn), __BIT (19));
+	  oinsn = N32_TYPE1 (SBGP, N32_RT5 (insn), N32_BIT (19));
 	  break;
 	}
       break;
@@ -7872,11 +7872,11 @@ turn_insn_to_sda_access (uint32_t insn, 
 	  break;
 	case N32_OP6_LHSI:
 	  /* lhsi.gp */
-	  oinsn = N32_TYPE1 (HWGP, N32_RT5 (insn), __BIT (18));
+	  oinsn = N32_TYPE1 (HWGP, N32_RT5 (insn), N32_BIT (18));
 	  break;
 	case N32_OP6_SHI:
 	  /* shi.gp */
-	  oinsn = N32_TYPE1 (HWGP, N32_RT5 (insn), __BIT (19));
+	  oinsn = N32_TYPE1 (HWGP, N32_RT5 (insn), N32_BIT (19));
 	  break;
 	}
       break;
@@ -11319,7 +11319,7 @@ nds32_elf_relax_pltgot_suff (struct bfd_
       irel->r_info = ELF32_R_INFO (ELF32_R_SYM (irel->r_info),
 				   R_NDS32_PLT_GOTREL_LO19);
       /* addi.gp */
-      insn = N32_TYPE1 (SBGP, N32_RT5 (insn), __BIT (19));
+      insn = N32_TYPE1 (SBGP, N32_RT5 (insn), N32_BIT (19));
     }
   else if (N32_OP6 (insn) == N32_OP6_JREG
 	   && N32_SUB5 (insn) == N32_JREG_JRAL)
@@ -11452,12 +11452,12 @@ nds32_elf_relax_gotoff_suff (struct bfd_
 	ELF32_R_INFO (ELF32_R_SYM (irel->r_info), R_NDS32_SDA18S1_RELA);
       break;
     case (N32_OP6_MEM << 8) | N32_MEM_LHS:
-      insn = N32_TYPE1 (HWGP, N32_RT5 (insn), __BIT (18));
+      insn = N32_TYPE1 (HWGP, N32_RT5 (insn), N32_BIT (18));
       irel->r_info =
 	ELF32_R_INFO (ELF32_R_SYM (irel->r_info), R_NDS32_SDA18S1_RELA);
       break;
     case (N32_OP6_MEM << 8) | N32_MEM_SH:
-      insn = N32_TYPE1 (HWGP, N32_RT5 (insn), __BIT (19));
+      insn = N32_TYPE1 (HWGP, N32_RT5 (insn), N32_BIT (19));
       irel->r_info =
 	ELF32_R_INFO (ELF32_R_SYM (irel->r_info), R_NDS32_SDA18S1_RELA);
       break;
@@ -11468,7 +11468,7 @@ nds32_elf_relax_gotoff_suff (struct bfd_
 	ELF32_R_INFO (ELF32_R_SYM (irel->r_info), R_NDS32_SDA19S0_RELA);
       break;
     case (N32_OP6_MEM << 8) | N32_MEM_LBS:
-      insn = N32_TYPE1 (LBGP, N32_RT5 (insn), __BIT (19));
+      insn = N32_TYPE1 (LBGP, N32_RT5 (insn), N32_BIT (19));
       irel->r_info =
 	ELF32_R_INFO (ELF32_R_SYM (irel->r_info), R_NDS32_SDA19S0_RELA);
       break;
@@ -11478,7 +11478,7 @@ nds32_elf_relax_gotoff_suff (struct bfd_
 	ELF32_R_INFO (ELF32_R_SYM (irel->r_info), R_NDS32_SDA19S0_RELA);
       break;
     case (N32_OP6_ALU1 << 8) | N32_ALU1_ADD:
-      insn = N32_TYPE1 (SBGP, N32_RT5 (insn), __BIT (19));
+      insn = N32_TYPE1 (SBGP, N32_RT5 (insn), N32_BIT (19));
       irel->r_info =
 	ELF32_R_INFO (ELF32_R_SYM (irel->r_info), R_NDS32_SDA19S0_RELA);
       break;
