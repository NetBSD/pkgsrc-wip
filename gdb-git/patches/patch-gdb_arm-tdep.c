$NetBSD$

--- gdb/arm-tdep.c.orig	2017-09-11 11:24:04.000000000 +0000
+++ gdb/arm-tdep.c
@@ -10057,7 +10057,7 @@ arm_record_extension_space (insn_decode_
       && !INSN_RECORDED(arm_insn_r))
     {
       /* Handle MLA(S) and MUL(S).  */
-      if (0 <= insn_op1 && 3 >= insn_op1)
+      if (3 >= insn_op1)
       {
         record_buf[0] = bits (arm_insn_r->arm_insn, 12, 15);
         record_buf[1] = ARM_PS_REGNUM;
@@ -11766,7 +11766,7 @@ thumb_record_ld_st_reg_offset (insn_deco
           record_buf[0] = reg_src1;
           thumb_insn_r->reg_rec_count = 1;
         }
-      else if (opB >= 0 && opB <= 2)
+      else if (opB <= 2)
         {
           /* STR(2), STRB(2), STRH(2) .  */
           reg_src1 = bits (thumb_insn_r->arm_insn, 3, 5);
