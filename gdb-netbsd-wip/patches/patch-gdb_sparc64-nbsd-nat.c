$NetBSD$

--- gdb/sparc64-nbsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/sparc64-nbsd-nat.c
@@ -20,9 +20,13 @@
 #include "defs.h"
 #include "gdbcore.h"
 #include "regcache.h"
+#include "inferior.h"
+#include "inf-ptrace.h"
 #include "target.h"
 
+#include "nbsd-nat.h"
 #include "sparc64-tdep.h"
+#include "sparc-nbsd-tdep.h"
 #include "sparc-nat.h"
 
 /* NetBSD is different from the other OSes that support both SPARC and
@@ -106,8 +110,6 @@ sparc64nbsd_gregset_supplies_p (struct g
   return 0;
 }
 
-/* Determine whether `fpregset_t' contains register REGNUM.  */
-
 static int
 sparc64nbsd_fpregset_supplies_p (struct gdbarch *gdbarch, int regnum)
 {
@@ -168,7 +170,7 @@ sparc64nbsd_supply_pcb (struct regcache 
 }
 
 /* We've got nothing to add to the generic SPARC target.  */
-static sparc_target<inf_ptrace_target> the_sparc64_nbsd_nat_target;
+static sparc_target<nbsd_nat_target> the_sparc64_nbsd_nat_target;
 
 void
 _initialize_sparc64nbsd_nat (void)
