$NetBSD$

--- gdb/alpha-nbsd-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/alpha-nbsd-tdep.c
@@ -28,13 +28,18 @@
 #include "value.h"
 
 #include "alpha-tdep.h"
-#include "alpha-bsd-tdep.h"
 #include "nbsd-tdep.h"
 #include "solib-svr4.h"
+#include "trad-frame.h"
+#include "frame-unwind.h"
+#include "tramp-frame.h"
 #include "target.h"
 
 /* Core file support.  */
 
+/* Even though NetBSD/alpha used ELF since day one, it used the
+   traditional a.out-style core dump format before NetBSD 1.6.  */
+
 /* Sizeof `struct reg' in <machine/reg.h>.  */
 #define ALPHANBSD_SIZEOF_GREGS	(32 * 8)
 
@@ -170,31 +175,95 @@ alphanbsd_iterate_over_regset_sections (
 
 /* Signal trampolines.  */
 
+static void
+alphanbsd_sigtramp_cache_init (const struct tramp_frame *,
+			       struct frame_info *,
+			       struct trad_frame_cache *,
+			       CORE_ADDR);
 /* Under NetBSD/alpha, signal handler invocations can be identified by the
    designated code sequence that is used to return from a signal handler.
    In particular, the return address of a signal handler points to the
-   following code sequence:
+   following code sequences: */
+static const struct tramp_frame alphanbsd_sigtramp_sc1 = {
+  SIGTRAMP_FRAME,
+  4,
+  {
+    { 0xa61e0000, 0xffffffff },		/* ldq a0, 0(sp) */
+    { 0x23de0010, 0xffffffff },		/* lda sp, 16(sp) */
+    { 0x201f0127, 0xffffffff },		/* lda v0, 295 */
+    { 0x00000083, 0xffffffff },		/* call_pal callsys */
+    { TRAMP_SENTINEL_INSN, ULONGEST_MAX }
+  },
+  alphanbsd_sigtramp_cache_init
+};
 
-	ldq	a0, 0(sp)
-	lda	sp, 16(sp)
-	lda	v0, 295(zero)	# __sigreturn14
-	call_pal callsys
-
-   Each instruction has a unique encoding, so we simply attempt to match
-   the instruction the PC is pointing to with any of the above instructions.
-   If there is a hit, we know the offset to the start of the designated
-   sequence and can then check whether we really are executing in the
-   signal trampoline.  If not, -1 is returned, otherwise the offset from the
-   start of the return sequence is returned.  */
-static const gdb_byte sigtramp_retcode[] =
-{
-  0x00, 0x00, 0x1e, 0xa6,	/* ldq a0, 0(sp) */
-  0x10, 0x00, 0xde, 0x23,	/* lda sp, 16(sp) */
-  0x27, 0x01, 0x1f, 0x20,	/* lda v0, 295(zero) */
-  0x83, 0x00, 0x00, 0x00,	/* call_pal callsys */
+/* The siginfo signal trampoline for NetBSD/alpha introduced in 2.0 */
+static const struct tramp_frame alphanbsd_sigtramp_si2 =
+{
+  SIGTRAMP_FRAME,
+  4,
+  {
+    { 0x221e0080, ULONGEST_MAX },		/* lda	a0,128(sp) */
+    { 0x201f0134, ULONGEST_MAX },		/* lda	v0,308 */
+    { 0x00000083, ULONGEST_MAX },		/* callsys */
+    { 0x47e00410, ULONGEST_MAX },		/* mov	v0,a0 */
+    { 0x201f0001, ULONGEST_MAX },		/* lda	v0,1 */
+    { 0x00000083, ULONGEST_MAX },		/* callsys */
+    { TRAMP_SENTINEL_INSN, ULONGEST_MAX }
+  },
+  alphanbsd_sigtramp_cache_init
+};
+/* The siginfo signal trampoline for NetBSD/alpha introduced in 4.0 */
+static const struct tramp_frame alphanbsd_sigtramp_si4 =
+{
+  SIGTRAMP_FRAME,
+  4,
+  {
+    { 0x27ba0000, 0xffff0000 },
+    { 0x23bd0000, 0xffff0000 },			/* ldgp	gp,0(ra) */
+    { 0x221e0080, ULONGEST_MAX },		/* lda	a0,128(sp) */
+    { 0x201f0134, ULONGEST_MAX },		/* lda	v0,308 */
+    { 0x00000083, ULONGEST_MAX },		/* callsys */
+    { 0x221fffff, ULONGEST_MAX },		/* lda	a0,-1 */
+    { 0x201f0001, ULONGEST_MAX },		/* lda	v0,1 */
+    { 0x00000083, ULONGEST_MAX },		/* callsys */
+    { TRAMP_SENTINEL_INSN, ULONGEST_MAX }
+  },
+  alphanbsd_sigtramp_cache_init
 };
-#define RETCODE_NWORDS		4
-#define RETCODE_SIZE		(RETCODE_NWORDS * 4)
+
+static void
+alphanbsd_sigtramp_cache_init (const struct tramp_frame *self,
+			       struct frame_info *this_frame,
+			       struct trad_frame_cache *this_cache,
+			       CORE_ADDR func)
+{
+  struct gdbarch *gdbarch = get_frame_arch (this_frame);
+  struct gdbarch_tdep *tdep = gdbarch_tdep (gdbarch);
+  CORE_ADDR addr, sp;
+  int i;
+
+  sp = get_frame_register_unsigned (this_frame, ALPHA_SP_REGNUM);
+
+  if (self == &alphanbsd_sigtramp_sc1) {
+    addr = sp;
+  } else {
+    addr = sp + 128 + 56;
+  }
+ 
+  for (i = 0; i < 32; i++, addr += ALPHA_REGISTER_SIZE)
+    {
+      trad_frame_set_reg_addr (this_cache, i, addr);
+    }
+  trad_frame_set_reg_addr (this_cache, ALPHA_PC_REGNUM, addr);
+
+  /* Construct the frame ID using the function start.  */
+  trad_frame_set_id (this_cache, frame_id_build (sp, func));
+}
+
+#ifdef notyet
+#define RETCODE_NWORDS          4
+#define RETCODE_SIZE            (RETCODE_NWORDS * 4)
 
 static LONGEST
 alphanbsd_sigtramp_offset (struct gdbarch *gdbarch, CORE_ADDR pc)
@@ -244,6 +313,7 @@ alphanbsd_sigcontext_addr (struct frame_
     return 0;
   return get_frame_base (get_next_frame (frame));
 }
+#endif
 
 
 static void
@@ -261,18 +331,24 @@ alphanbsd_init_abi (struct gdbarch_info 
   /* NetBSD/alpha does not provide single step support via ptrace(2); we
      must use software single-stepping.  */
   set_gdbarch_software_single_step (gdbarch, alpha_software_single_step);
-
   /* NetBSD/alpha has SVR4-style shared libraries.  */
   set_solib_svr4_fetch_link_map_offsets
     (gdbarch, svr4_lp64_fetch_link_map_offsets);
+  set_gdbarch_skip_solib_resolver (gdbarch, nbsd_skip_solib_resolver);
 
+#ifdef notyet
   tdep->dynamic_sigtramp_offset = alphanbsd_sigtramp_offset;
   tdep->pc_in_sigtramp = alphanbsd_pc_in_sigtramp;
   tdep->sigcontext_addr = alphanbsd_sigcontext_addr;
+#endif
 
   tdep->jb_pc = 2;
   tdep->jb_elt_size = 8;
 
+  tramp_frame_prepend_unwinder (gdbarch, &alphanbsd_sigtramp_sc1);
+  tramp_frame_prepend_unwinder (gdbarch, &alphanbsd_sigtramp_si2);
+  tramp_frame_prepend_unwinder (gdbarch, &alphanbsd_sigtramp_si4);
+
   set_gdbarch_iterate_over_regset_sections
     (gdbarch, alphanbsd_iterate_over_regset_sections);
 }
@@ -281,9 +357,6 @@ alphanbsd_init_abi (struct gdbarch_info 
 void
 _initialize_alphanbsd_tdep (void)
 {
-  /* Even though NetBSD/alpha used ELF since day one, it used the
-     traditional a.out-style core dump format before NetBSD 1.6, but
-     we don't support those.  */
   gdbarch_register_osabi (bfd_arch_alpha, 0, GDB_OSABI_NETBSD,
                           alphanbsd_init_abi);
 }
