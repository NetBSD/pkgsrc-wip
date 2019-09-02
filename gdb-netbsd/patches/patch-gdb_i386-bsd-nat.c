$NetBSD$

--- gdb/i386-bsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/i386-bsd-nat.c
@@ -131,12 +131,13 @@ void
 i386bsd_fetch_inferior_registers (struct regcache *regcache, int regnum)
 {
   pid_t pid = get_ptrace_pid (regcache->ptid ());
+  int lwp = regcache->ptid ().lwp ();
 
   if (regnum == -1 || GETREGS_SUPPLIES (regnum))
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
       i386bsd_supply_gregset (regcache, &regs);
@@ -185,7 +186,7 @@ i386bsd_fetch_inferior_registers (struct
 
 	  xstateregs = alloca (x86bsd_xsave_len);
 	  if (ptrace (PT_GETXSTATE, pid,
-		      (PTRACE_TYPE_ARG3) xstateregs, 0) == -1)
+		      (PTRACE_TYPE_ARG3) xstateregs, lwp) == -1)
 	    perror_with_name (_("Couldn't get extended state status"));
 
 	  i387_supply_xsave (regcache, -1, xstateregs);
@@ -195,7 +196,7 @@ i386bsd_fetch_inferior_registers (struct
       
 #ifdef HAVE_PT_GETXMMREGS
       if (have_ptrace_xmmregs != 0
-	  && ptrace(PT_GETXMMREGS, pid, (PTRACE_TYPE_ARG3) xmmregs, 0) == 0)
+	  && ptrace(PT_GETXMMREGS, pid, (PTRACE_TYPE_ARG3) xmmregs, lwp) == 0)
 	{
 	  have_ptrace_xmmregs = 1;
 	  i387_supply_fxsave (regcache, -1, xmmregs);
@@ -204,7 +205,7 @@ i386bsd_fetch_inferior_registers (struct
 	{
 	  have_ptrace_xmmregs = 0;
 #endif
-          if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+          if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	    perror_with_name (_("Couldn't get floating point status"));
 
 	  i387_supply_fsave (regcache, -1, &fpregs);
@@ -221,17 +222,18 @@ void
 i386bsd_store_inferior_registers (struct regcache *regcache, int regnum)
 {
   pid_t pid = get_ptrace_pid (regcache->ptid ());
+  int lwp = regcache->ptid ().lwp ();
 
   if (regnum == -1 || GETREGS_SUPPLIES (regnum))
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
         perror_with_name (_("Couldn't get registers"));
 
       i386bsd_collect_gregset (regcache, &regs, regnum);
 
-      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
         perror_with_name (_("Couldn't write registers"));
 
       if (regnum != -1)
@@ -279,10 +281,10 @@ i386bsd_store_inferior_registers (struct
 
 	  xstateregs = alloca (x86bsd_xsave_len);
 	  if (ptrace (PT_GETXSTATE, pid,
-		      (PTRACE_TYPE_ARG3) xstateregs, 0) == -1)
+		      (PTRACE_TYPE_ARG3) xstateregs,  lwp) == -1)
 	    perror_with_name (_("Couldn't get extended state status"));
 
-	  i387_collect_xsave (regcache, -1, xstateregs, 0);
+	  i387_collect_xsave (regcache, -1, xstateregs, lwp);
 
 	  if (ptrace (PT_SETXSTATE, pid,
 		      (PTRACE_TYPE_ARG3) xstateregs, x86bsd_xsave_len) == -1)
@@ -293,25 +295,25 @@ i386bsd_store_inferior_registers (struct
 
 #ifdef HAVE_PT_GETXMMREGS
       if (have_ptrace_xmmregs != 0
-	  && ptrace(PT_GETXMMREGS, pid, (PTRACE_TYPE_ARG3) xmmregs, 0) == 0)
+	  && ptrace(PT_GETXMMREGS, pid, (PTRACE_TYPE_ARG3) xmmregs, lwp) == 0)
 	{
 	  have_ptrace_xmmregs = 1;
 
 	  i387_collect_fxsave (regcache, regnum, xmmregs);
 
-	  if (ptrace (PT_SETXMMREGS, pid, (PTRACE_TYPE_ARG3) xmmregs, 0) == -1)
+	  if (ptrace (PT_SETXMMREGS, pid, (PTRACE_TYPE_ARG3) xmmregs, lwp) == -1)
             perror_with_name (_("Couldn't write XMM registers"));
 	}
       else
 	{
 	  have_ptrace_xmmregs = 0;
 #endif
-          if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+          if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	    perror_with_name (_("Couldn't get floating point status"));
 
           i387_collect_fsave (regcache, regnum, &fpregs);
 
-          if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+          if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	    perror_with_name (_("Couldn't write floating point status"));
 #ifdef HAVE_PT_GETXMMREGS
         }
