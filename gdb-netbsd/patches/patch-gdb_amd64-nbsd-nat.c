$NetBSD$

--- gdb/amd64-nbsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/amd64-nbsd-nat.c
@@ -24,6 +24,13 @@
 #include "amd64-tdep.h"
 #include "amd64-bsd-nat.h"
 #include "amd64-nat.h"
+#include "regcache.h"
+#include "gdbcore.h"
+#include "bsd-kvm.h"
+
+#include <machine/frame.h>
+#include <machine/pcb.h>
+#include <machine/reg.h>
 
 /* Mapping between the general-purpose registers in NetBSD/amd64
    `struct reg' format and GDB's register cache layout for
@@ -54,6 +61,55 @@ static int amd64nbsd32_r_reg_offset[] =
   15 * 8			/* %gs */
 };
 
+static int
+amd64nbsd_supply_pcb (struct regcache *regcache, struct pcb *pcb)
+{
+  struct switchframe sf;
+
+  /* The following is true for NetBSD/amd64:
+
+     The pcb contains the stack pointer at the point of the context
+     switch in cpu_switchto().  At that point we have a stack frame as
+     described by `struct switchframe', which for NetBSD/amd64 has the
+     following layout:
+
+     interrupt level
+     %r15
+     %r14
+     %r13
+     %r12
+     %rbx
+     return address
+
+     Together with %rsp in the pcb, this accounts for all callee-saved
+     registers specified by the psABI.  From this information we
+     reconstruct the register state as it would look when we just
+     returned from cpu_switchto().
+
+     For kernel core dumps, dumpsys() builds a fake switchframe for us. */
+
+  /* The stack pointer shouldn't be zero.  */
+  if (pcb->pcb_rsp == 0)
+    return 0;
+
+  /* Read the stack frame, and check its validity.  */
+  read_memory (pcb->pcb_rsp, (gdb_byte *) &sf, sizeof sf);
+  pcb->pcb_rsp += sizeof (struct switchframe);
+  regcache->raw_supply (12, &sf.sf_r12);
+  regcache->raw_supply (13, &sf.sf_r13);
+  regcache->raw_supply (14, &sf.sf_r14);
+  regcache->raw_supply (15, &sf.sf_r15);
+  regcache->raw_supply (AMD64_RBX_REGNUM, &sf.sf_rbx);
+  regcache->raw_supply (AMD64_RIP_REGNUM, &sf.sf_rip);
+
+  regcache->raw_supply (AMD64_RSP_REGNUM, &pcb->pcb_rsp);
+  regcache->raw_supply (AMD64_RBP_REGNUM, &pcb->pcb_rbp);
+  regcache->raw_supply (AMD64_FS_REGNUM, &pcb->pcb_fs);
+  regcache->raw_supply (AMD64_GS_REGNUM, &pcb->pcb_gs);
+
+  return 1;
+}
+
 static amd64_bsd_nat_target<nbsd_nat_target> the_amd64_nbsd_nat_target;
 
 void
@@ -64,4 +120,6 @@ _initialize_amd64nbsd_nat (void)
   amd64_native_gregset64_reg_offset = amd64nbsd_r_reg_offset;
 
   add_inf_child_target (&the_amd64_nbsd_nat_target);
+
+  bsd_kvm_add_target (amd64nbsd_supply_pcb);
 }
