$NetBSD$

--- gdb/sparc-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/sparc-nat.c
@@ -138,6 +138,7 @@ sparc_fetch_inferior_registers (struct r
 {
   struct gdbarch *gdbarch = regcache->arch ();
   pid_t pid;
+  int lwp = regcache->ptid ().lwp ();
 
   /* NOTE: cagney/2002-12-03: This code assumes that the currently
      selected light weight processes' registers can be written
@@ -166,7 +167,7 @@ sparc_fetch_inferior_registers (struct r
     {
       gregset_t regs;
 
-      if (ptrace (PTRACE_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PTRACE_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
       sparc_supply_gregset (sparc_gregmap, regcache, -1, &regs);
@@ -178,7 +179,7 @@ sparc_fetch_inferior_registers (struct r
     {
       fpregset_t fpregs;
 
-      if (ptrace (PTRACE_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PTRACE_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't get floating point status"));
 
       sparc_supply_fpregset (sparc_fpregmap, regcache, -1, &fpregs);
@@ -190,6 +191,7 @@ sparc_store_inferior_registers (struct r
 {
   struct gdbarch *gdbarch = regcache->arch ();
   pid_t pid;
+  int lwp = regcache->ptid ().lwp ();
 
   /* NOTE: cagney/2002-12-02: See comment in fetch_inferior_registers
      about threaded assumptions.  */
@@ -199,12 +201,12 @@ sparc_store_inferior_registers (struct r
     {
       gregset_t regs;
 
-      if (ptrace (PTRACE_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PTRACE_GETREGS, pid, (PTRACE_TYPE_ARG3) &regs, lwp) == -1)
 	perror_with_name (_("Couldn't get registers"));
 
       sparc_collect_gregset (sparc_gregmap, regcache, regnum, &regs);
 
-      if (ptrace (PTRACE_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, 0) == -1)
+      if (ptrace (PTRACE_SETREGS, pid, (PTRACE_TYPE_ARG3) &regs, inferior_ptid.lwp ()) == -1)
 	perror_with_name (_("Couldn't write registers"));
 
       /* Deal with the stack regs.  */
@@ -225,7 +227,7 @@ sparc_store_inferior_registers (struct r
     {
       fpregset_t fpregs, saved_fpregs;
 
-      if (ptrace (PTRACE_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+      if (ptrace (PTRACE_GETFPREGS, pid, (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	perror_with_name (_("Couldn't get floating-point registers"));
 
       memcpy (&saved_fpregs, &fpregs, sizeof (fpregs));
@@ -238,7 +240,7 @@ sparc_store_inferior_registers (struct r
       if (memcmp (&saved_fpregs, &fpregs, sizeof (fpregs)) != 0)
 	{
 	  if (ptrace (PTRACE_SETFPREGS, pid,
-		      (PTRACE_TYPE_ARG3) &fpregs, 0) == -1)
+		      (PTRACE_TYPE_ARG3) &fpregs, lwp) == -1)
 	    perror_with_name (_("Couldn't write floating-point registers"));
 	}
 
@@ -252,7 +254,7 @@ sparc_store_inferior_registers (struct r
    TARGET_OBJECT_WCOOKIE.  Fetch StackGhost Per-Process XOR cookie.  */
 
 enum target_xfer_status
-sparc_xfer_wcookie (struct target_ops *ops, enum target_object object,
+sparc_xfer_wcookie (enum target_object object,
 		    const char *annex, gdb_byte *readbuf,
 		    const gdb_byte *writebuf, ULONGEST offset, ULONGEST len,
 		    ULONGEST *xfered_len)
