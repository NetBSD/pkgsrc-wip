$NetBSD$

--- opcodes/riscv-dis.c.orig	2017-09-11 11:24:05.000000000 +0000
+++ opcodes/riscv-dis.c
@@ -428,7 +428,7 @@ riscv_disassemble_insn (bfd_vma memaddr,
 	  if (no_aliases && (op->pinfo & INSN_ALIAS))
 	    continue;
 	  /* Is this instruction restricted to a certain value of XLEN?  */
-	  if (isdigit (op->subset[0]) && atoi (op->subset) != xlen)
+	  if (isdigit ((unsigned char)op->subset[0]) && atoi (op->subset) != xlen)
 	    continue;
 
 	  /* It's a match.  */
