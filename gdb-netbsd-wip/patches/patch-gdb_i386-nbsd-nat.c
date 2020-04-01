$NetBSD$

--- gdb/i386-nbsd-nat.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/i386-nbsd-nat.c
@@ -23,11 +23,13 @@
 #include "target.h"
 
 #include "i386-tdep.h"
+#include "i387-tdep.h"
 #include "i386-bsd-nat.h"
 
 /* Support for debugging kernel virtual memory images.  */
 
 #include <sys/types.h>
+#include <machine/reg.h>
 #include <machine/frame.h>
 #include <machine/pcb.h>
 
@@ -39,21 +41,25 @@ i386nbsd_supply_pcb (struct regcache *re
 {
   struct switchframe sf;
 
-  /* The following is true for NetBSD 1.6.2:
+  /* The following is true for NetBSD 1.6.2 and after:
 
      The pcb contains %esp and %ebp at the point of the context switch
-     in cpu_switch().  At that point we have a stack frame as
-     described by `struct switchframe', which for NetBSD 1.6.2 has the
-     following layout:
+     in cpu_switch()/cpu_switchto().  At that point we have a stack frame as
+     described by `struct switchframe', which for NetBSD (2.0 and later) has
+     the following layout:
 
-     interrupt level
      %edi
      %esi
      %ebx
-     %eip
+     return address
 
      we reconstruct the register state as it would look when we just
-     returned from cpu_switch().  */
+     returned from cpu_switch()/cpu_switchto().
+
+     For core dumps the pcb is saved by savectx()/dumpsys() and contains the
+     stack pointer and frame pointer.  A new dumpsys() fakes a switchframe
+     whereas older code isn't reliable so use an iffy heuristic to detect this
+     and use the frame pointer to recover enough state.  */
 
   /* The stack pointer shouldn't be zero.  */
   if (pcb->pcb_esp == 0)
