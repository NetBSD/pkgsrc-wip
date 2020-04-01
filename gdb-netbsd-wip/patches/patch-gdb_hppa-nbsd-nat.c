$NetBSD$

--- gdb/hppa-nbsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/hppa-nbsd-nat.c
@@ -58,8 +58,7 @@ hppanbsd_fpregset_supplies_p (int regnum
 static void
 hppanbsd_supply_gregset (struct regcache *regcache, const void *gregs)
 {
-  const char *regs = gregs;
-  const int *r = gregs;
+  const char *regs = (const char *) gregs;
   int regnum;
 
   for (regnum = HPPA_R1_REGNUM; regnum <= HPPA_R31_REGNUM; regnum++)
@@ -83,7 +82,7 @@ hppanbsd_supply_gregset (struct regcache
 static void
 hppanbsd_supply_fpregset (struct regcache *regcache, const void *fpregs)
 {
-  const char *regs = fpregs;
+  const char *regs = (const char *) fpregs;
   int regnum;
 
   for (regnum = HPPA_FP0_REGNUM; regnum <= HPPA_FP31R_REGNUM;
@@ -101,8 +100,7 @@ static void
 hppanbsd_collect_gregset (const struct regcache *regcache,
 			  void *gregs, int regnum)
 {
-  char *regs = gregs;
-  int *r = gregs;
+  char *regs = (char *) gregs;
   int i;
 
   for (i = HPPA_R1_REGNUM; i <= HPPA_R31_REGNUM; i++)
@@ -146,10 +144,10 @@ hppanbsd_collect_gregset (const struct r
    in FPREGS.  */
 
 static void
-hppanbsd_collect_fpregset (struct regcache *regcache,
+hppanbsd_collect_fpregset (const struct regcache *regcache,
 			  void *fpregs, int regnum)
 {
-  char *regs = fpregs;
+  char *regs = (char *) fpregs;
   int i;
 
   for (i = HPPA_FP0_REGNUM; i <= HPPA_FP31R_REGNUM; i += 2, regs += 8)
@@ -170,13 +168,15 @@ void
 hppa_nbsd_nat_target::fetch_registers (struct regcache *regcache, int regnum)
 
 {
-  pid_t pid = regcache->ptid ().pid ();
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
   if (regnum == -1 || hppanbsd_gregset_supplies_p (regnum))
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
       hppanbsd_supply_gregset (regcache, &regs);
@@ -186,7 +186,7 @@ hppa_nbsd_nat_target::fetch_registers (s
     {
       struct fpreg fpregs;
 
-      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       hppanbsd_supply_fpregset (regcache, &fpregs);
@@ -199,18 +199,20 @@ hppa_nbsd_nat_target::fetch_registers (s
 void
 hppa_nbsd_nat_target::store_registers (struct regcache *regcache, int regnum)
 {
-  pid_t pid = regcache->ptid ().pid ();
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
 
   if (regnum == -1 || hppanbsd_gregset_supplies_p (regnum))
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
         perror_with_name (_("Couldn't get registers"));
 
       hppanbsd_collect_gregset (regcache, &regs, regnum);
 
-      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
         perror_with_name (_("Couldn't write registers"));
     }
 
@@ -218,12 +220,12 @@ hppa_nbsd_nat_target::store_registers (s
     {
       struct fpreg fpregs;
 
-      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       hppanbsd_collect_fpregset (regcache, &fpregs, regnum);
 
-      if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't write floating point status"));
     }
 }
