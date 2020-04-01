$NetBSD$

--- gdb/alpha-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/alpha-tdep.c
@@ -754,6 +754,31 @@ alpha_skip_prologue (struct gdbarch *gdb
   return pc + offset;
 }
 
+/* GNU ld for alpha is so clever that the redundant GP load in function
+   entrypoint is skipped.  We must therefore skip initial GP loads; otherwise
+   breakpoints in function entrypoints can also be skipped.  */
+
+static CORE_ADDR
+alpha_skip_entrypoint (struct gdbarch *gdbarch, CORE_ADDR pc)
+{
+  unsigned long inst;
+  gdb_byte buf[ALPHA_INSN_SIZE];
+
+  /* Refer to the comment in alpha_skip_prologue above.  */
+  if (target_read_memory (pc, buf, sizeof (buf)))
+    return pc;
+
+  /* Skip a GP load in the first two words in the function entrypoint.  */
+  inst = alpha_read_insn (gdbarch, pc);
+  if ((inst & 0xffff0000) != 0x27bb0000)	/* ldah $gp,n($t12) */
+    return pc;
+  inst = alpha_read_insn (gdbarch, pc + ALPHA_INSN_SIZE);
+  if ((inst & 0xffff0000) != 0x23bd0000)	/* lda $gp,n($gp) */
+    return pc;
+
+  return pc + 2 * ALPHA_INSN_SIZE;
+}
+
 
 static const int ldl_l_opcode = 0x2a;
 static const int ldq_l_opcode = 0x2b;
