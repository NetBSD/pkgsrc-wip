$NetBSD$

--- gdb/amd64-nbsd-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/amd64-nbsd-tdep.c
@@ -28,6 +28,8 @@
 #include "gdbsupport/x86-xstate.h"
 #include "nbsd-tdep.h"
 #include "solib-svr4.h"
+#include "trad-frame.h"
+#include "frame-unwind.h"
 
 /* Support for signal handlers.  */
 
@@ -94,6 +96,196 @@ int amd64nbsd_r_reg_offset[] =
   15 * 8			/* %gs */
 };
 
+/* Kernel debugging support */
+static const int amd64nbsd_tf_reg_offset[] =
+{
+  18 * 8,			/* %rax */
+  17 * 8,			/* %rbx */
+  10 * 8,			/* %rcx */
+  2 * 8,			/* %rdx */
+  1 * 8,			/* %rsi */
+  0 * 8,			/* %rdi */
+  16 * 8,			/* %rbp */
+  28 * 8,			/* %rsp */
+  4 * 8,			/* %r8 .. */
+  5 * 8,			
+  3 * 8,			
+  11 * 8,			
+  12 * 8,			
+  13 * 8,			
+  14 * 8,			
+  15 * 8,			/* ... %r15 */
+  25 * 8,			/* %rip */
+  27 * 8,			/* %eflags */
+  26 * 8,			/* %cs */
+  29 * 8,			/* %ss */
+  22 * 8,			/* %ds */
+  21 * 8,			/* %es */
+  20 * 8,			/* %fs */
+  19 * 8,			/* %gs */
+};
+
+static struct trad_frame_cache *
+amd64nbsd_trapframe_cache(struct frame_info *this_frame, void **this_cache)
+{
+  struct trad_frame_cache *cache;
+  CORE_ADDR func, sp, addr;
+  ULONGEST cs = 0, rip = 0;
+  const char *name;
+  int i;
+  struct gdbarch *gdbarch = get_frame_arch (this_frame);
+  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
+
+  if (*this_cache)
+    return (struct trad_frame_cache *)*this_cache;
+
+  cache = trad_frame_cache_zalloc (this_frame);
+  *this_cache = cache;
+
+  func = get_frame_func (this_frame);
+  sp = get_frame_register_unsigned (this_frame, AMD64_RSP_REGNUM);
+
+  find_pc_partial_function (func, &name, NULL, NULL);
+
+  /* There is an extra 'call' in the interrupt sequence - ignore the extra
+   * return address */
+
+  addr = sp;
+  if (name) {
+	if (strncmp (name, "Xintr", 5) == 0
+	 || strncmp (name, "Xhandle", 7) == 0) {
+		addr += 8;		/* It's an interrupt frame.  */
+	}
+  }
+
+#ifdef DEBUG_TRAPFRAME
+  for (i = 0; i < 50; i++) {
+    cs = read_memory_unsigned_integer (addr + i * 8, 8, byte_order);
+    printf("%s i=%d r=%#jx\n", name, i, (intmax_t)cs);
+  }
+#endif
+
+  for (i = 0; i < ARRAY_SIZE (amd64nbsd_tf_reg_offset); i++)
+    if (amd64nbsd_tf_reg_offset[i] != -1)
+      trad_frame_set_reg_addr (cache, i, addr + amd64nbsd_tf_reg_offset[i]);
+
+  /* Read %cs and %rip when we have the addresses to hand */
+  cs = read_memory_unsigned_integer (addr
+    + amd64nbsd_tf_reg_offset[AMD64_CS_REGNUM], 8, byte_order);
+  rip = read_memory_unsigned_integer (addr
+    + amd64nbsd_tf_reg_offset[AMD64_RIP_REGNUM], 8, byte_order);
+
+#ifdef DEBUG_TRAPFRAME
+  printf("%s cs=%#jx rip=%#jx\n", name, (intmax_t)cs, (intmax_t)rip);
+#endif
+
+  /* The trap frame layout was changed lf the %rip value is less than 2^16 it
+   * is almost certainly the %ss of the old format. */
+  if (rip < (1 << 16))
+    {
+
+      for (i = 0; i < ARRAY_SIZE (amd64nbsd_tf_reg_offset); i++)
+        {
+
+          if (amd64nbsd_tf_reg_offset[i] == -1)
+            continue;
+
+          trad_frame_set_reg_addr (cache, i, addr + amd64nbsd_r_reg_offset[i]);
+
+          /* Read %cs when we have the address to hand */
+          if (i == AMD64_CS_REGNUM)
+	    cs = read_memory_unsigned_integer (addr + amd64nbsd_r_reg_offset[i],
+	    8, byte_order);
+        }
+    }
+
+  if ((cs & I386_SEL_RPL) == I386_SEL_UPL ||
+	(name && strncmp(name, "Xsoft", 5) == 0))
+    {
+      /* Trap from user space or soft interrupt; terminate backtrace.  */
+      trad_frame_set_id (cache, outer_frame_id);
+    }
+  else
+    {
+      /* Construct the frame ID using the function start.  */
+      trad_frame_set_id (cache, frame_id_build (sp + 16, func));
+    }
+
+  return cache;
+}
+
+static void
+amd64nbsd_trapframe_this_id (struct frame_info *this_frame,
+			     void **this_cache,
+			     struct frame_id *this_id)
+{
+  struct trad_frame_cache *cache =
+    amd64nbsd_trapframe_cache (this_frame, this_cache);
+  
+  trad_frame_get_id (cache, this_id);
+}
+
+static struct value *
+amd64nbsd_trapframe_prev_register (struct frame_info *this_frame,
+				   void **this_cache, int regnum) 
+{
+  struct trad_frame_cache *cache =
+    amd64nbsd_trapframe_cache (this_frame, this_cache);
+
+  return trad_frame_get_register (cache, this_frame, regnum);
+}
+
+static int
+amd64nbsd_trapframe_sniffer (const struct frame_unwind *self,
+			     struct frame_info *this_frame,
+			     void **this_prologue_cache)
+{
+  ULONGEST cs = 0;
+  const char *name;
+
+  try
+    {
+      cs = get_frame_register_unsigned (this_frame, AMD64_CS_REGNUM);
+    }
+  catch (gdb_exception_error &except)
+    {
+      if (except.reason < 0 && except.error != NOT_AVAILABLE_ERROR)
+	throw_exception (std::move (except));
+    }
+
+  if ((cs & I386_SEL_RPL) == I386_SEL_UPL)
+    return 0;
+
+  find_pc_partial_function (get_frame_pc (this_frame), &name, NULL, NULL);
+  return (name && ((strcmp (name, "alltraps") == 0)
+	        || (strcmp (name, "calltrap") == 0)
+	        || (strcmp (name, "handle_syscall") == 0)
+		|| (strcmp (name, "Xdoreti") == 0)
+		|| (strcmp (name, "Xspllower") == 0)
+		|| (strncmp (name, "Xhandle", 7) == 0)
+		|| (strncmp (name, "Xintr", 5) == 0)
+		|| (strncmp (name, "Xpreempt", 8) == 0)
+		|| (strncmp (name, "Xrecurse", 8) == 0)
+		|| (strncmp (name, "Xresume", 7) == 0)
+		|| (strncmp (name, "Xsoft", 5) == 0)
+		|| (strncmp (name, "Xstray", 6) == 0)
+		|| (strncmp (name, "Xsyscall", 8) == 0)
+		|| (strncmp (name, "Xtrap", 5) == 0)
+	    ));
+}
+
+static const struct frame_unwind amd64nbsd_trapframe_unwind = {
+  /* FIXME: kettenis/20051219: This really is more like an interrupt
+     frame, but SIGTRAMP_FRAME would print <signal handler called>,
+     which really is not what we want here.  */
+  NORMAL_FRAME,
+  default_frame_unwind_stop_reason,
+  amd64nbsd_trapframe_this_id,
+  amd64nbsd_trapframe_prev_register,
+  NULL,
+  amd64nbsd_trapframe_sniffer
+};
+
 static void
 amd64nbsd_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
 {
@@ -118,6 +310,8 @@ amd64nbsd_init_abi (struct gdbarch_info 
   /* NetBSD uses SVR4-style shared libraries.  */
   set_solib_svr4_fetch_link_map_offsets
     (gdbarch, svr4_lp64_fetch_link_map_offsets);
+  /* Unwind kernel trap frames correctly.  */
+  frame_unwind_prepend_unwinder (gdbarch, &amd64nbsd_trapframe_unwind);
 }
 
 void
