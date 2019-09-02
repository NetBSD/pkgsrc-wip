$NetBSD$

--- gdb/i386-nbsd-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/i386-nbsd-tdep.c
@@ -33,6 +33,11 @@
 #include "nbsd-tdep.h"
 #include "solib-svr4.h"
 
+#include "elf-bfd.h"		/* for header hack */
+#include "trad-frame.h"		/* signal trampoline/kernel frame support */
+#include "frame-unwind.h"	/* kernel frame support */
+#include "tramp-frame.h"	/* signal trampoline/kernel frame support */
+
 /* From <machine/reg.h>.  */
 static int i386nbsd_r_reg_offset[] =
 {
@@ -369,6 +374,156 @@ i386nbsd_sigtramp_cache_init (const stru
 }
 
 
+/* From <machine/frame.h>.  Note that %esp and %ess are only saved in
+   a trap frame when entering the kernel from user space.  */
+static int i386nbsd_tf_reg_offset[] =
+{
+  10 * 4,			/* %eax */
+   9 * 4,			/* %ecx */
+   8 * 4,			/* %edx */
+   7 * 4,			/* %ebx */
+  -1,				/* %esp */
+   6 * 4,			/* %ebp */
+   5 * 4,			/* %esi */
+   4 * 4,			/* %edi */
+  13 * 4,			/* %eip */
+  15 * 4,			/* %eflags */
+  14 * 4,			/* %cs */
+  -1,				/* %ss */
+   3 * 4,			/* %ds */
+   2 * 4,			/* %es */
+   1 * 4,			/* %fs */
+   0 * 4			/* %gs */
+};
+ 
+static struct trad_frame_cache *
+i386nbsd_trapframe_cache(struct frame_info *this_frame, void **this_cache)
+{
+  struct trad_frame_cache *cache;
+  CORE_ADDR func, sp, addr, tmp;
+  ULONGEST cs;
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
+  sp = get_frame_register_unsigned (this_frame, I386_ESP_REGNUM);
+
+  find_pc_partial_function (func, &name, NULL, NULL);
+  if (name && (strncmp (name, "Xintr", 5) == 0 ||
+               strncmp (name, "Xhandle", 7) == 0))
+    {
+      /* It's an interrupt frame. */
+      tmp = read_memory_unsigned_integer (sp + 4, 4, byte_order);
+      if (tmp < 15)
+        {
+          /* Reasonable value for 'ppl': already on interrupt stack. */
+          addr = sp + 8;
+        }
+      else
+        {
+          /* Switch to previous stack. */
+          addr = tmp + 4;
+        }
+    }
+  else
+    {
+      /* It's a trap frame. */
+      addr = sp + 4;
+    }
+
+  for (i = 0; i < ARRAY_SIZE (i386nbsd_tf_reg_offset); i++)
+    if (i386nbsd_tf_reg_offset[i] != -1)
+      trad_frame_set_reg_addr (cache, i, addr + i386nbsd_tf_reg_offset[i]);
+
+  /* Read %cs from trap frame.  */
+  addr += i386nbsd_tf_reg_offset[I386_CS_REGNUM];
+  cs = read_memory_unsigned_integer (addr, 4, byte_order); 
+  if ((cs & I386_SEL_RPL) == I386_SEL_UPL)
+    {
+      /* Trap from user space; terminate backtrace.  */
+      trad_frame_set_id (cache, outer_frame_id);
+    }
+  else
+    {
+      /* Construct the frame ID using the function start.  */
+      trad_frame_set_id (cache, frame_id_build (sp + 8, func));
+    }
+
+  return cache;
+}
+
+static void
+i386nbsd_trapframe_this_id (struct frame_info *this_frame,
+			    void **this_cache, struct frame_id *this_id)
+{
+  struct trad_frame_cache *cache =
+    i386nbsd_trapframe_cache (this_frame, this_cache);
+  
+  trad_frame_get_id (cache, this_id);
+}
+
+static struct value *
+i386nbsd_trapframe_prev_register (struct frame_info *this_frame,
+				  void **this_cache, int regnum)
+{
+  struct trad_frame_cache *cache =
+    i386nbsd_trapframe_cache (this_frame, this_cache);
+
+  return trad_frame_get_register (cache, this_frame, regnum);
+}
+
+static int
+i386nbsd_trapframe_sniffer (const struct frame_unwind *self,
+			    struct frame_info *this_frame,
+			    void **this_prologue_cache)
+{
+  ULONGEST cs;
+  const char *name;
+
+  /* Check Current Privilege Level and bail out if we're not executing
+     in kernel space.  */
+  cs = get_frame_register_unsigned (this_frame, I386_CS_REGNUM);
+  if ((cs & I386_SEL_RPL) == I386_SEL_UPL)
+    return 0;
+
+
+  find_pc_partial_function (get_frame_pc (this_frame), &name, NULL, NULL);
+  return (name && ((strcmp (name, "alltraps") == 0)
+	        || (strcmp (name, "calltrap") == 0)
+		|| (strcmp (name, "syscall1") == 0)
+		|| (strcmp (name, "Xdoreti") == 0)
+		|| (strncmp (name, "Xintr", 5) == 0)
+		|| (strncmp (name, "Xhandle", 7) == 0)
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
+const struct frame_unwind i386nbsd_trapframe_unwind = {
+  /* FIXME: kettenis/20051219: This really is more like an interrupt
+     frame, but SIGTRAMP_FRAME would print <signal handler called>,
+     which really is not what we want here.  */
+  NORMAL_FRAME,
+  default_frame_unwind_stop_reason,
+  i386nbsd_trapframe_this_id,
+  i386nbsd_trapframe_prev_register,
+  NULL,
+  i386nbsd_trapframe_sniffer
+};
+
 static void 
 i386nbsd_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
 {
@@ -398,6 +553,9 @@ i386nbsd_init_abi (struct gdbarch_info i
   tramp_frame_prepend_unwinder (gdbarch, &i386nbsd_sigtramp_si2);
   tramp_frame_prepend_unwinder (gdbarch, &i386nbsd_sigtramp_si31);
   tramp_frame_prepend_unwinder (gdbarch, &i386nbsd_sigtramp_si4);
+
+  /* Unwind kernel trap frames correctly.  */
+  frame_unwind_prepend_unwinder (gdbarch, &i386nbsd_trapframe_unwind);
 }
 
 /* NetBSD ELF.  */
