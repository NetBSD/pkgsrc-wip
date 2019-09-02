$NetBSD$

--- gdb/alpha-bsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/alpha-bsd-nat.c
@@ -33,17 +33,12 @@
 #include <sys/procfs.h>
 #endif
 
-#ifndef HAVE_GREGSET_T
-typedef struct reg gregset_t;
-#endif
-
-#ifndef HAVE_FPREGSET_T 
-typedef struct fpreg fpregset_t; 
-#endif 
-
-#include "gregset.h"
-
+#ifdef __NetBSD__
+#include "nbsd-nat.h"
+struct alpha_bsd_nat_target final : public nbsd_nat_target
+#else
 struct alpha_bsd_nat_target final : public inf_ptrace_target
+#endif
 {
   void fetch_registers (struct regcache *, int) override;
   void store_registers (struct regcache *, int) override;
@@ -51,33 +46,6 @@ struct alpha_bsd_nat_target final : publ
 
 static alpha_bsd_nat_target the_alpha_bsd_nat_target;
 
-/* Provide *regset() wrappers around the generic Alpha BSD register
-   supply/fill routines.  */
-
-void
-supply_gregset (struct regcache *regcache, const gregset_t *gregsetp)
-{
-  alphabsd_supply_reg (regcache, (const char *) gregsetp, -1);
-}
-
-void
-fill_gregset (const struct regcache *regcache, gregset_t *gregsetp, int regno)
-{
-  alphabsd_fill_reg (regcache, (char *) gregsetp, regno);
-}
-
-void
-supply_fpregset (struct regcache *regcache, const fpregset_t *fpregsetp)
-{
-  alphabsd_supply_fpreg (regcache, (const char *) fpregsetp, -1);
-}
-
-void
-fill_fpregset (const struct regcache *regcache,
-	       fpregset_t *fpregsetp, int regno)
-{
-  alphabsd_fill_fpreg (regcache, (char *) fpregsetp, regno);
-}
 
 /* Determine if PT_GETREGS fetches this register.  */
 
@@ -94,12 +62,15 @@ getregs_supplies (int regno)
 void
 alpha_bsd_nat_target::fetch_registers (struct regcache *regcache, int regno)
 {
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
+
   if (regno == -1 || getregs_supplies (regno))
     {
       struct reg gregs;
 
-      if (ptrace (PT_GETREGS, regcache->ptid ().pid (),
-		  (PTRACE_TYPE_ARG3) &gregs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &gregs, lwp) == -1) 
 	perror_with_name (_("Couldn't get registers"));
 
       alphabsd_supply_reg (regcache, (char *) &gregs, regno);
@@ -112,8 +83,7 @@ alpha_bsd_nat_target::fetch_registers (s
     {
       struct fpreg fpregs;
 
-      if (ptrace (PT_GETFPREGS, regcache->ptid ().pid (),
-		  (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       alphabsd_supply_fpreg (regcache, (char *) &fpregs, regno);
@@ -126,17 +96,20 @@ alpha_bsd_nat_target::fetch_registers (s
 void
 alpha_bsd_nat_target::store_registers (struct regcache *regcache, int regno)
 {
+  ptid_t ptid = regcache->ptid ();
+  pid_t pid = ptid.pid ();
+  int lwp = ptid.lwp ();
+
   if (regno == -1 || getregs_supplies (regno))
     {
       struct reg gregs;
-      if (ptrace (PT_GETREGS, regcache->ptid ().pid (),
-                  (PTRACE_TYPE_ARG3) &gregs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid,
+                  (PTRACE_TYPE_ARG3) &gregs, lwp) == -1)
         perror_with_name (_("Couldn't get registers"));
 
       alphabsd_fill_reg (regcache, (char *) &gregs, regno);
 
-      if (ptrace (PT_SETREGS, regcache->ptid ().pid (),
-                  (PTRACE_TYPE_ARG3) &gregs, 0) == -1)
+      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &gregs, lwp) == -1) 
         perror_with_name (_("Couldn't write registers"));
 
       if (regno != -1)
@@ -148,14 +121,13 @@ alpha_bsd_nat_target::store_registers (s
     {
       struct fpreg fpregs;
 
-      if (ptrace (PT_GETFPREGS, regcache->ptid ().pid (),
-		  (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       alphabsd_fill_fpreg (regcache, (char *) &fpregs, regno);
 
-      if (ptrace (PT_SETFPREGS, regcache->ptid ().pid (),
-		  (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_SETFPREGS, pid,
+		  (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1) 
 	perror_with_name (_("Couldn't write floating point status"));
     }
 }
