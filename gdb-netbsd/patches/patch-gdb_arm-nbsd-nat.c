$NetBSD$

--- gdb/arm-nbsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/arm-nbsd-nat.c
@@ -1,5 +1,4 @@
-/* Native-dependent code for BSD Unix running on ARM's, for GDB.
-
+/*
    Copyright (C) 1988-2019 Free Software Foundation, Inc.
 
    This file is part of GDB.
@@ -17,20 +16,30 @@
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
+#ifndef _KERNTYPES
+#define _KERNTYPES
+#endif
 #include "defs.h"
 #include "gdbcore.h"
 #include "inferior.h"
 #include "regcache.h"
 #include "target.h"
+
+#include "nbsd-nat.h"
 #include <sys/types.h>
 #include <sys/ptrace.h>
 #include <machine/reg.h>
 #include <machine/frame.h>
+#include <arm/arm32/frame.h>
+
+/* Support for debugging kernel virtual memory images.  */
+#include <machine/pcb.h>
 
 #include "arm-tdep.h"
 #include "inf-ptrace.h"
+#include "bsd-kvm.h"
 
-class arm_netbsd_nat_target final : public inf_ptrace_target
+class arm_nbsd_nat_target final : public nbsd_nat_target
 {
 public:
   /* Add our register access methods.  */
@@ -38,10 +47,60 @@ public:
   void store_registers (struct regcache *, int) override;
 };
 
-static arm_netbsd_nat_target the_arm_netbsd_nat_target;
+static arm_nbsd_nat_target the_arm_nbsd_nat_target;
 
 extern int arm_apcs_32;
 
+#define FPSCR(r) ((char *) &(r)->fpr_vfp.vfp_fpscr)
+#define FPREG(r, regno) \
+    ((char *) (r)->fpr_vfp.vfp_regs + 8 * ((regno) - ARM_D0_REGNUM))
+
+static int
+armnbsd_supply_pcb (struct regcache *regcache, struct pcb *pcb)
+{
+  struct switchframe sf;
+
+  /* The following is true for NetBSD/arm32 in 5.0 and after:
+
+     The pcb contains r8-r13 (sp) at the point of context switch in
+     cpu_switchto() or call of dumpsys(). At that point we have a
+     stack frame as described by `struct switchframe', which for
+     NetBSD/arm32 has the following layout:
+
+	r4   ascending.
+	r5        |
+	r6        |
+	r7       \|/
+	old sp
+	pc
+
+     we reconstruct the register state as it would look when we just
+     returned from cpu_switchto() or dumpsys().  */
+
+  if (!arm_apcs_32)
+    return 0;
+
+  /* The stack pointer shouldn't be zero.  */
+  if (pcb->pcb_sp == 0)
+    return 0;
+
+  read_memory (pcb->pcb_sp, (gdb_byte *) &sf, sizeof sf);
+
+  regcache->raw_supply (ARM_PC_REGNUM, &sf.sf_pc);
+  regcache->raw_supply (ARM_SP_REGNUM, &pcb->pcb_sp);
+  regcache->raw_supply (12, &pcb->pcb_r12);
+  regcache->raw_supply (11, &pcb->pcb_r11);
+  regcache->raw_supply (10, &pcb->pcb_r10);
+  regcache->raw_supply (9, &pcb->pcb_r9);
+  regcache->raw_supply (8, &pcb->pcb_r8);
+  regcache->raw_supply (7, &sf.sf_r7);
+  regcache->raw_supply (6, &sf.sf_r6);
+  regcache->raw_supply (5, &sf.sf_r5);
+  regcache->raw_supply (4, &sf.sf_r4);
+
+  return 1;
+}
+
 static void
 arm_supply_gregset (struct regcache *regcache, struct reg *gregset)
 {
@@ -65,25 +124,26 @@ arm_supply_gregset (struct regcache *reg
 }
 
 static void
-arm_supply_fparegset (struct regcache *regcache, struct fpreg *fparegset)
+arm_supply_vfpregset (struct regcache *regcache, struct fpreg *vfpregset)
 {
   int regno;
 
-  for (regno = ARM_F0_REGNUM; regno <= ARM_F7_REGNUM; regno++)
-    regcache->raw_supply (regno,
-			  (char *) &fparegset->fpr[regno - ARM_F0_REGNUM]);
+  for (regno = ARM_D0_REGNUM; regno < 16 + ARM_D0_REGNUM; regno++)
+    regcache->raw_supply (regno, FPREG(vfpregset, regno));
 
-  regcache->raw_supply (ARM_FPS_REGNUM, (char *) &fparegset->fpr_fpsr);
+  regcache->raw_supply (ARM_FPSCR_REGNUM, FPSCR(vfpregset));
 }
 
 static void
 fetch_register (struct regcache *regcache, int regno)
 {
-  struct reg inferior_registers;
+  struct reg regs;
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
   int ret;
 
-  ret = ptrace (PT_GETREGS, regcache->ptid ().pid (),
-		(PTRACE_TYPE_ARG3) &inferior_registers, 0);
+  ret = ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp);
 
   if (ret < 0)
     {
@@ -94,32 +154,28 @@ fetch_register (struct regcache *regcach
   switch (regno)
     {
     case ARM_SP_REGNUM:
-      regcache->raw_supply (ARM_SP_REGNUM, (char *) &inferior_registers.r_sp);
+      regcache->raw_supply (ARM_SP_REGNUM, (char *) &regs.r_sp);
       break;
 
     case ARM_LR_REGNUM:
-      regcache->raw_supply (ARM_LR_REGNUM, (char *) &inferior_registers.r_lr);
+      regcache->raw_supply (ARM_LR_REGNUM, (char *) &regs.r_lr);
       break;
 
     case ARM_PC_REGNUM:
       /* This is ok: we're running native...  */
-      inferior_registers.r_pc = gdbarch_addr_bits_remove
-				  (regcache->arch (),
-				   inferior_registers.r_pc);
-      regcache->raw_supply (ARM_PC_REGNUM, (char *) &inferior_registers.r_pc);
+      regs.r_pc = gdbarch_addr_bits_remove (regcache->arch (), regs.r_pc);
+      regcache->raw_supply (ARM_PC_REGNUM, (char *) &regs.r_pc);
       break;
 
     case ARM_PS_REGNUM:
       if (arm_apcs_32)
-	regcache->raw_supply (ARM_PS_REGNUM,
-			      (char *) &inferior_registers.r_cpsr);
+	regcache->raw_supply (ARM_PS_REGNUM, (char *) &regs.r_cpsr);
       else
-	regcache->raw_supply (ARM_PS_REGNUM,
-			      (char *) &inferior_registers.r_pc);
+	regcache->raw_supply (ARM_PS_REGNUM, (char *) &regs.r_pc);
       break;
 
     default:
-      regcache->raw_supply (regno, (char *) &inferior_registers.r[regno]);
+      regcache->raw_supply (regno, (char *) &regs.r[regno]);
       break;
     }
 }
@@ -127,12 +183,14 @@ fetch_register (struct regcache *regcach
 static void
 fetch_regs (struct regcache *regcache)
 {
-  struct reg inferior_registers;
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
+  struct reg regs;
   int ret;
   int regno;
 
-  ret = ptrace (PT_GETREGS, regcache->ptid ().pid (),
-		(PTRACE_TYPE_ARG3) &inferior_registers, 0);
+  ret = ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp);
 
   if (ret < 0)
     {
@@ -140,17 +198,19 @@ fetch_regs (struct regcache *regcache)
       return;
     }
 
-  arm_supply_gregset (regcache, &inferior_registers);
+  arm_supply_gregset (regcache, &regs);
 }
 
 static void
 fetch_fp_register (struct regcache *regcache, int regno)
 {
-  struct fpreg inferior_fp_registers;
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
+  struct fpreg fpregs;
   int ret;
 
-  ret = ptrace (PT_GETFPREGS, regcache->ptid ().pid (),
-		(PTRACE_TYPE_ARG3) &inferior_fp_registers, 0);
+  ret = ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp); 
 
   if (ret < 0)
     {
@@ -160,14 +220,13 @@ fetch_fp_register (struct regcache *regc
 
   switch (regno)
     {
-    case ARM_FPS_REGNUM:
-      regcache->raw_supply (ARM_FPS_REGNUM,
-			    (char *) &inferior_fp_registers.fpr_fpsr);
+    case ARM_FPSCR_REGNUM:
+      regcache->raw_supply (ARM_FPSCR_REGNUM, FPSCR(&fpregs));
       break;
 
     default:
-      regcache->raw_supply
-	(regno, (char *) &inferior_fp_registers.fpr[regno - ARM_F0_REGNUM]);
+      regno += ARM_D0_REGNUM;
+      regcache->raw_supply (regno, FPREG(&fpregs, regno));
       break;
     }
 }
@@ -175,20 +234,21 @@ fetch_fp_register (struct regcache *regc
 static void
 fetch_fp_regs (struct regcache *regcache)
 {
-  struct fpreg inferior_fp_registers;
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
+  struct fpreg fpregs;
   int ret;
-  int regno;
 
-  ret = ptrace (PT_GETFPREGS, regcache->ptid ().pid (),
-		(PTRACE_TYPE_ARG3) &inferior_fp_registers, 0);
+  ret = ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp);
 
   if (ret < 0)
     {
-      warning (_("unable to fetch general registers"));
+      warning (_("unable to fetch floating-point registers"));
       return;
     }
 
-  arm_supply_fparegset (regcache, &inferior_fp_registers);
+  arm_supply_vfpregset (regcache, &fpregs);
 }
 
 void
@@ -196,10 +256,10 @@ arm_nbsd_nat_target::fetch_registers (st
 {
   if (regno >= 0)
     {
-      if (regno < ARM_F0_REGNUM || regno > ARM_FPS_REGNUM)
-	fetch_register (regcache, regno);
-      else
+      if (regno >= ARM_D0_REGNUM && regno <= ARM_FPSCR_REGNUM)
 	fetch_fp_register (regcache, regno);
+      else
+	fetch_register (regcache, regno);
     }
   else
     {
@@ -213,11 +273,13 @@ static void
 store_register (const struct regcache *regcache, int regno)
 {
   struct gdbarch *gdbarch = regcache->arch ();
-  struct reg inferior_registers;
+  struct reg regs;
   int ret;
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
-  ret = ptrace (PT_GETREGS, regcache->ptid ().pid (),
-		(PTRACE_TYPE_ARG3) &inferior_registers, 0);
+  ret = ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp); 
 
   if (ret < 0)
     {
@@ -228,17 +290,16 @@ store_register (const struct regcache *r
   switch (regno)
     {
     case ARM_SP_REGNUM:
-      regcache->raw_collect (ARM_SP_REGNUM, (char *) &inferior_registers.r_sp);
+      regcache->raw_collect (ARM_SP_REGNUM, (char *) &regs.r_sp);
       break;
 
     case ARM_LR_REGNUM:
-      regcache->raw_collect (ARM_LR_REGNUM, (char *) &inferior_registers.r_lr);
+      regcache->raw_collect (ARM_LR_REGNUM, (char *) &regs.r_lr);
       break;
 
     case ARM_PC_REGNUM:
       if (arm_apcs_32)
-	regcache->raw_collect (ARM_PC_REGNUM,
-			       (char *) &inferior_registers.r_pc);
+	regcache->raw_collect (ARM_PC_REGNUM, (char *) &regs.r_pc);
       else
 	{
 	  unsigned pc_val;
@@ -246,16 +307,14 @@ store_register (const struct regcache *r
 	  regcache->raw_collect (ARM_PC_REGNUM, (char *) &pc_val);
 	  
 	  pc_val = gdbarch_addr_bits_remove (gdbarch, pc_val);
-	  inferior_registers.r_pc ^= gdbarch_addr_bits_remove
-				       (gdbarch, inferior_registers.r_pc);
-	  inferior_registers.r_pc |= pc_val;
+	  regs.r_pc ^= gdbarch_addr_bits_remove (gdbarch, regs.r_pc);
+	  regs.r_pc |= pc_val;
 	}
       break;
 
     case ARM_PS_REGNUM:
       if (arm_apcs_32)
-	regcache->raw_collect (ARM_PS_REGNUM,
-			       (char *) &inferior_registers.r_cpsr);
+	regcache->raw_collect (ARM_PS_REGNUM, (char *) &regs.r_cpsr);
       else
 	{
 	  unsigned psr_val;
@@ -263,19 +322,17 @@ store_register (const struct regcache *r
 	  regcache->raw_collect (ARM_PS_REGNUM, (char *) &psr_val);
 
 	  psr_val ^= gdbarch_addr_bits_remove (gdbarch, psr_val);
-	  inferior_registers.r_pc = gdbarch_addr_bits_remove
-				      (gdbarch, inferior_registers.r_pc);
-	  inferior_registers.r_pc |= psr_val;
+	  regs.r_pc = gdbarch_addr_bits_remove (gdbarch, regs.r_pc);
+	  regs.r_pc |= psr_val;
 	}
       break;
 
     default:
-      regcache->raw_collect (regno, (char *) &inferior_registers.r[regno]);
+      regcache->raw_collect (regno, (char *) &regs.r[regno]);
       break;
     }
 
-  ret = ptrace (PT_SETREGS, regcache->ptid ().pid (),
-		(PTRACE_TYPE_ARG3) &inferior_registers, 0);
+  ret = ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp);
 
   if (ret < 0)
     warning (_("unable to write register %d to inferior"), regno);
@@ -285,22 +342,24 @@ static void
 store_regs (const struct regcache *regcache)
 {
   struct gdbarch *gdbarch = regcache->arch ();
-  struct reg inferior_registers;
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
+  struct reg regs;
   int ret;
   int regno;
 
 
   for (regno = ARM_A1_REGNUM; regno < ARM_SP_REGNUM; regno++)
-    regcache->raw_collect (regno, (char *) &inferior_registers.r[regno]);
+    regcache->raw_collect (regno, (char *) &regs.r[regno]);
 
-  regcache->raw_collect (ARM_SP_REGNUM, (char *) &inferior_registers.r_sp);
-  regcache->raw_collect (ARM_LR_REGNUM, (char *) &inferior_registers.r_lr);
+  regcache->raw_collect (ARM_SP_REGNUM, (char *) &regs.r_sp);
+  regcache->raw_collect (ARM_LR_REGNUM, (char *) &regs.r_lr);
 
   if (arm_apcs_32)
     {
-      regcache->raw_collect (ARM_PC_REGNUM, (char *) &inferior_registers.r_pc);
-      regcache->raw_collect (ARM_PS_REGNUM,
-			     (char *) &inferior_registers.r_cpsr);
+      regcache->raw_collect (ARM_PC_REGNUM, (char *) &regs.r_pc);
+      regcache->raw_collect (ARM_PS_REGNUM, (char *) &regs.r_cpsr);
     }
   else
     {
@@ -313,11 +372,10 @@ store_regs (const struct regcache *regca
       pc_val = gdbarch_addr_bits_remove (gdbarch, pc_val);
       psr_val ^= gdbarch_addr_bits_remove (gdbarch, psr_val);
 
-      inferior_registers.r_pc = pc_val | psr_val;
+      regs.r_pc = pc_val | psr_val;
     }
 
-  ret = ptrace (PT_SETREGS, regcache->ptid ().pid (),
-		(PTRACE_TYPE_ARG3) &inferior_registers, 0);
+  ret = ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp); 
 
   if (ret < 0)
     warning (_("unable to store general registers"));
@@ -326,11 +384,13 @@ store_regs (const struct regcache *regca
 static void
 store_fp_register (const struct regcache *regcache, int regno)
 {
-  struct fpreg inferior_fp_registers;
+  struct fpreg fpregs;
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
   int ret;
 
-  ret = ptrace (PT_GETFPREGS, regcache->ptid ().pid (),
-		(PTRACE_TYPE_ARG3) &inferior_fp_registers, 0);
+  ret = ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp); 
 
   if (ret < 0)
     {
@@ -341,18 +401,15 @@ store_fp_register (const struct regcache
   switch (regno)
     {
     case ARM_FPS_REGNUM:
-      regcache->raw_collect (ARM_FPS_REGNUM,
-			     (char *) &inferior_fp_registers.fpr_fpsr);
+      regcache->raw_collect (ARM_FPS_REGNUM, FPSCR(&fpregs));
       break;
 
     default:
-      regcache->raw_collect
-	(regno, (char *) &inferior_fp_registers.fpr[regno - ARM_F0_REGNUM]);
+      regcache->raw_collect (regno, FPREG(&fpregs, regno));
       break;
     }
 
-  ret = ptrace (PT_SETFPREGS, regcache->ptid ().pid (),
-		(PTRACE_TYPE_ARG3) &inferior_fp_registers, 0);
+  ret = ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp); 
 
   if (ret < 0)
     warning (_("unable to write register %d to inferior"), regno);
@@ -361,20 +418,20 @@ store_fp_register (const struct regcache
 static void
 store_fp_regs (const struct regcache *regcache)
 {
-  struct fpreg inferior_fp_registers;
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
+  struct fpreg fpregs;
   int ret;
   int regno;
 
 
-  for (regno = ARM_F0_REGNUM; regno <= ARM_F7_REGNUM; regno++)
-    regcache->raw_collect
-      (regno, (char *) &inferior_fp_registers.fpr[regno - ARM_F0_REGNUM]);
+  for (regno = ARM_D0_REGNUM; regno < 16 + ARM_D0_REGNUM; regno++)
+    regcache->raw_collect (regno, FPREG(&fpregs, regno));
 
-  regcache->raw_collect (ARM_FPS_REGNUM,
-			 (char *) &inferior_fp_registers.fpr_fpsr);
+  regcache->raw_collect (ARM_FPSCR_REGNUM, FPSCR(&fpregs));
 
-  ret = ptrace (PT_SETFPREGS, regcache->ptid ().pid (),
-		(PTRACE_TYPE_ARG3) &inferior_fp_registers, 0);
+  ret = ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp);
 
   if (ret < 0)
     warning (_("unable to store floating-point registers"));
@@ -385,10 +442,10 @@ arm_nbsd_nat_target::store_registers (st
 {
   if (regno >= 0)
     {
-      if (regno < ARM_F0_REGNUM || regno > ARM_FPS_REGNUM)
-	store_register (regcache, regno);
-      else
+      if (regno >= ARM_D0_REGNUM && regno <= ARM_FPSCR_REGNUM)
 	store_fp_register (regcache, regno);
+      else
+	store_register (regcache, regno);
     }
   else
     {
@@ -397,13 +454,32 @@ arm_nbsd_nat_target::store_registers (st
     }
 }
 
+struct md_core
+{
+  struct reg intreg;
+  struct fpreg freg;
+};
+
+static void
+fetch_core_registers (struct regcache *regcache,
+		      char *core_reg_sect, unsigned core_reg_size,
+		      int which, CORE_ADDR ignore)
+{
+  struct md_core *core_reg = (struct md_core *) core_reg_sect;
+  int regno;
+  CORE_ADDR r_pc;
+
+  arm_supply_gregset (regcache, &core_reg->intreg);
+  arm_supply_vfpregset (regcache, &core_reg->freg);
+}
+
 static void
 fetch_elfcore_registers (struct regcache *regcache,
 			 char *core_reg_sect, unsigned core_reg_size,
 			 int which, CORE_ADDR ignore)
 {
   struct reg gregset;
-  struct fpreg fparegset;
+  struct fpreg vfpregset;
 
   switch (which)
     {
@@ -426,8 +502,8 @@ fetch_elfcore_registers (struct regcache
 	{
 	  /* The memcpy may be unnecessary, but we can't really be sure
 	     of the alignment of the data in the core file.  */
-	  memcpy (&fparegset, core_reg_sect, sizeof (fparegset));
-	  arm_supply_fparegset (regcache, &fparegset);
+	  memcpy (&vfpregset, core_reg_sect, sizeof (vfpregset));
+	  arm_supply_vfpregset (regcache, &vfpregset);
 	}
       break;
 
@@ -437,9 +513,18 @@ fetch_elfcore_registers (struct regcache
     }
 }
 
+static struct core_fns arm_netbsd_core_fns =
+{
+  bfd_target_unknown_flavour,		/* core_flavour.  */
+  default_check_format,			/* check_format.  */
+  default_core_sniffer,			/* core_sniffer.  */
+  fetch_core_registers,			/* core_read_registers.  */
+  NULL
+};
+
 static struct core_fns arm_netbsd_elfcore_fns =
 {
-  bfd_target_elf_flavour,		/* core_flovour.  */
+  bfd_target_elf_flavour,		/* core_flavour.  */
   default_check_format,			/* check_format.  */
   default_core_sniffer,			/* core_sniffer.  */
   fetch_elfcore_registers,		/* core_read_registers.  */
@@ -449,7 +534,8 @@ static struct core_fns arm_netbsd_elfcor
 void
 _initialize_arm_netbsd_nat (void)
 {
-  add_inf_child_target (&the_arm_netbsd_nat_target);
+  add_inf_child_target (&the_arm_nbsd_nat_target);
 
+  deprecated_add_core_fns (&arm_netbsd_core_fns);
   deprecated_add_core_fns (&arm_netbsd_elfcore_fns);
 }
