$NetBSD$

--- opcodes/nds32-dis.c.orig	2017-09-04 13:40:58.000000000 +0000
+++ opcodes/nds32-dis.c
@@ -759,10 +759,10 @@ nds32_mask_opcode (uint32_t insn)
       return MASK_OP (insn, 0);
     case N32_OP6_ALU2:
       /* FFBI */
-      if (__GF (insn, 0, 7) == (N32_ALU2_FFBI | __BIT (6)))
+      if (__GF (insn, 0, 7) == (N32_ALU2_FFBI | N32_BIT (6)))
 	return MASK_OP (insn, 0x7f);
-      else if (__GF (insn, 0, 7) == (N32_ALU2_MFUSR | __BIT (6))
-	       || __GF (insn, 0, 7) == (N32_ALU2_MTUSR | __BIT (6)))
+      else if (__GF (insn, 0, 7) == (N32_ALU2_MFUSR | N32_BIT (6))
+	       || __GF (insn, 0, 7) == (N32_ALU2_MTUSR | N32_BIT (6)))
 	/* RDOV CLROV */
 	return MASK_OP (insn, 0xf81ff);
       return MASK_OP (insn, 0x1ff);
