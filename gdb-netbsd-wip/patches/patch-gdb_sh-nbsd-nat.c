$NetBSD$

--- gdb/sh-nbsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/sh-nbsd-nat.c
@@ -29,8 +29,10 @@
 #include "sh-tdep.h"
 #include "inf-ptrace.h"
 #include "regcache.h"
+#include "inf-ptrace.h"
+#include "nbsd-nat.h"
 
-struct sh_nbsd_nat_target final : public inf_ptrace_target
+struct sh_nbsd_nat_target final : public nbsd_nat_target
 {
   void fetch_registers (struct regcache *, int) override;
   void store_registers (struct regcache *, int) override;
@@ -43,26 +45,27 @@ static sh_nbsd_nat_target the_sh_nbsd_na
   (((regno) >= R0_REGNUM && (regno) <= (R0_REGNUM + 15)) \
 || (regno) == gdbarch_pc_regnum (gdbarch) || (regno) == PR_REGNUM \
 || (regno) == MACH_REGNUM || (regno) == MACL_REGNUM \
-|| (regno) == SR_REGNUM)
+|| (regno) == SR_REGNUM || (regno) == GBR_REGNUM)
 
 /* Sizeof `struct reg' in <machine/reg.h>.  */
-#define SHNBSD_SIZEOF_GREGS	(21 * 4)
+#define SHNBSD_SIZEOF_GREGS	(22 * 4)
 
 void
 sh_nbsd_nat_target::fetch_registers (struct regcache *regcache, int regno)
 {
-  pid_t pid = regcache->ptid ().pid ();
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
   if (regno == -1 || GETREGS_SUPPLIES (regcache->arch (), regno))
     {
-      struct reg inferior_registers;
+      struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid,
-		  (PTRACE_TYPE_ARG3) &inferior_registers, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
       sh_corefile_supply_regset (&sh_corefile_gregset, regcache, regno,
-				 (char *) &inferior_registers,
+				 (char *) &regs,
 				 SHNBSD_SIZEOF_GREGS);
 
       if (regno != -1)
@@ -73,22 +76,22 @@ sh_nbsd_nat_target::fetch_registers (str
 void
 sh_nbsd_nat_target::store_registers (struct regcache *regcache, int regno)
 {
-  pid_t pid = regcache->ptid ().pid ();
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
   if (regno == -1 || GETREGS_SUPPLIES (regcache->arch (), regno))
     {
-      struct reg inferior_registers;
+      struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid,
-		  (PTRACE_TYPE_ARG3) &inferior_registers, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
       sh_corefile_collect_regset (&sh_corefile_gregset, regcache, regno,
-				  (char *) &inferior_registers,
+				  (char *) &regs,
 				  SHNBSD_SIZEOF_GREGS);
 
-      if (ptrace (PT_SETREGS, pid,
-		  (PTRACE_TYPE_ARG3) &inferior_registers, 0) == -1)
+      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't set registers"));
 
       if (regno != -1)
