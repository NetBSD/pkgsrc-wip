$NetBSD$

--- gdb/m68k-bsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/m68k-bsd-nat.c
@@ -29,7 +29,12 @@
 #include "m68k-tdep.h"
 #include "inf-ptrace.h"
 
+#ifdef __NetBSD__
+#include "nbsd-nat.h"
+struct m68k_bsd_nat_target final : public nbsd_nat_target
+#else
 struct m68k_bsd_nat_target final : public inf_ptrace_target
+#endif
 {
   void fetch_registers (struct regcache *, int) override;
   void store_registers (struct regcache *, int) override;
@@ -54,7 +59,7 @@ m68kbsd_fpregset_supplies_p (int regnum)
 static void
 m68kbsd_supply_gregset (struct regcache *regcache, const void *gregs)
 {
-  const char *regs = gregs;
+  const gdb_byte *regs = (const gdb_byte *)gregs;
   int regnum;
 
   for (regnum = M68K_D0_REGNUM; regnum <= M68K_PC_REGNUM; regnum++)
@@ -67,7 +72,7 @@ static void
 m68kbsd_supply_fpregset (struct regcache *regcache, const void *fpregs)
 {
   struct gdbarch *gdbarch = regcache->arch ();
-  const char *regs = fpregs;
+  const gdb_byte *regs = (const gdb_byte *)fpregs;
   int regnum;
 
   for (regnum = M68K_FP0_REGNUM; regnum <= M68K_FPI_REGNUM; regnum++)
@@ -82,7 +87,7 @@ static void
 m68kbsd_collect_gregset (const struct regcache *regcache,
 			 void *gregs, int regnum)
 {
-  char *regs = gregs;
+  gdb_byte *regs = (gdb_byte *)gregs;
   int i;
 
   for (i = M68K_D0_REGNUM; i <= M68K_PC_REGNUM; i++)
@@ -100,7 +105,7 @@ m68kbsd_collect_fpregset (struct regcach
 			  void *fpregs, int regnum)
 {
   struct gdbarch *gdbarch = regcache->arch ();
-  char *regs = fpregs;
+  gdb_byte *regs = (gdb_byte *)fpregs;
   int i;
 
   for (i = M68K_FP0_REGNUM; i <= M68K_FPI_REGNUM; i++)
@@ -123,7 +128,7 @@ m68k_bsd_nat_target::fetch_registers (st
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs,  inferior_ptid.lwp ()) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
       m68kbsd_supply_gregset (regcache, &regs);
@@ -133,7 +138,7 @@ m68k_bsd_nat_target::fetch_registers (st
     {
       struct fpreg fpregs;
 
-      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs,  inferior_ptid.lwp ()) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       m68kbsd_supply_fpregset (regcache, &fpregs);
@@ -152,12 +157,12 @@ m68k_bsd_nat_target::store_registers (st
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs,  inferior_ptid.lwp ()) == -1)
         perror_with_name (_("Couldn't get registers"));
 
       m68kbsd_collect_gregset (regcache, &regs, regnum);
 
-      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs,  inferior_ptid.lwp ()) == -1)
         perror_with_name (_("Couldn't write registers"));
     }
 
@@ -165,12 +170,12 @@ m68k_bsd_nat_target::store_registers (st
     {
       struct fpreg fpregs;
 
-      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs,  inferior_ptid.lwp ()) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       m68kbsd_collect_fpregset (regcache, &fpregs, regnum);
 
-      if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs,  inferior_ptid.lwp ()) == -1)
 	perror_with_name (_("Couldn't write floating point status"));
     }
 }
@@ -215,7 +220,7 @@ m68kbsd_supply_pcb (struct regcache *reg
   tmp = pcb->pcb_ps & 0xffff;
   regcache->raw_supply (M68K_PS_REGNUM, &tmp);
 
-  read_memory (pcb->pcb_regs[PCB_REGS_FP] + 4, (char *) &tmp, sizeof tmp);
+  read_memory (pcb->pcb_regs[PCB_REGS_FP] + 4, (gdb_byte *) &tmp, sizeof tmp);
   regcache->raw_supply (M68K_PC_REGNUM, &tmp);
 
   return 1;
