$NetBSD$

--- gdb/amd64-bsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/amd64-bsd-nat.c
@@ -51,7 +51,7 @@ amd64bsd_fetch_inferior_registers (struc
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs,  inferior_ptid.lwp ()) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
       amd64_supply_native_gregset (regcache, &regs, -1);
@@ -95,7 +95,7 @@ amd64bsd_fetch_inferior_registers (struc
       if (x86bsd_xsave_len != 0)
 	{
 	  xstateregs = alloca (x86bsd_xsave_len);
-	  if (ptrace (PT_GETXSTATE, pid, (PTRACE_TYPE_ARG3) xstateregs, 0)
+	  if (ptrace (PT_GETXSTATE, pid, (PTRACE_TYPE_ARG3) xstateregs,  inferior_ptid.lwp ())
 	      == -1)
 	    perror_with_name (_("Couldn't get extended state status"));
 
@@ -104,7 +104,7 @@ amd64bsd_fetch_inferior_registers (struc
 	}
 #endif
 
-      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs,  inferior_ptid.lwp ()) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       amd64_supply_fxsave (regcache, -1, &fpregs);
@@ -127,12 +127,12 @@ amd64bsd_store_inferior_registers (struc
     {
       struct reg regs;
 
-      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs,  inferior_ptid.lwp ()) == -1)
         perror_with_name (_("Couldn't get registers"));
 
       amd64_collect_native_gregset (regcache, &regs, regnum);
 
-      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PT_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs,  inferior_ptid.lwp ()) == -1)
         perror_with_name (_("Couldn't write registers"));
 
       if (regnum != -1)
@@ -179,11 +179,11 @@ amd64bsd_store_inferior_registers (struc
       if (x86bsd_xsave_len != 0)
 	{
 	  xstateregs = alloca (x86bsd_xsave_len);
-	  if (ptrace (PT_GETXSTATE, pid, (PTRACE_TYPE_ARG3) xstateregs, 0)
+	  if (ptrace (PT_GETXSTATE, pid, (PTRACE_TYPE_ARG3) xstateregs,  inferior_ptid.lwp ())
 	      == -1)
 	    perror_with_name (_("Couldn't get extended state status"));
 
-	  amd64_collect_xsave (regcache, regnum, xstateregs, 0);
+	  amd64_collect_xsave (regcache, regnum, xstateregs,  inferior_ptid.lwp ());
 
 	  if (ptrace (PT_SETXSTATE, pid, (PTRACE_TYPE_ARG3) xstateregs,
 		      x86bsd_xsave_len) == -1)
@@ -192,12 +192,12 @@ amd64bsd_store_inferior_registers (struc
 	}
 #endif
 
-      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs,  inferior_ptid.lwp ()) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       amd64_collect_fxsave (regcache, regnum, &fpregs);
 
-      if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PT_SETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs,  inferior_ptid.lwp ()) == -1)
 	perror_with_name (_("Couldn't write floating point status"));
     }
 }
