$NetBSD$

--- gdb/sparc-nbsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/sparc-nbsd-nat.c
@@ -21,13 +21,16 @@
 #include "regcache.h"
 #include "target.h"
 
+#include "nbsd-nat.h"
 #include "sparc-tdep.h"
+#include "sparc-nbsd-tdep.h"
 #include "sparc-nat.h"
 
 /* Support for debugging kernel virtual memory images.  */
 
 #include <sys/types.h>
 #include <machine/pcb.h>
+#include <machine/reg.h>
 
 #include "bsd-kvm.h"
 
@@ -55,7 +58,7 @@ sparc32nbsd_supply_pcb (struct regcache 
   return 1;
 }
 
-static sparc_target<inf_ptrace_target> the_sparc_nbsd_nat_target;
+static sparc_target<nbsd_nat_target> the_sparc_nbsd_nat_target;
 
 void
 _initialize_sparcnbsd_nat (void)
@@ -63,7 +66,7 @@ _initialize_sparcnbsd_nat (void)
   sparc_gregmap = &sparc32nbsd_gregmap;
   sparc_fpregmap = &sparc32_bsd_fpregmap;
 
-  add_inf_child_target (&sparc_nbsd_nat_target);
+  add_inf_child_target (&the_sparc_nbsd_nat_target);
 
   /* Support debugging kernel virtual memory images.  */
   bsd_kvm_add_target (sparc32nbsd_supply_pcb);
