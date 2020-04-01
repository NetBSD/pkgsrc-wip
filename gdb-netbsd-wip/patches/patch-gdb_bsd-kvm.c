$NetBSD$

--- gdb/bsd-kvm.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/bsd-kvm.c
@@ -29,6 +29,7 @@
 #include "gdbcore.h"
 #include "inferior.h"          /* for get_exec_file */
 #include "gdbthread.h"
+#include "arch-utils.h"
 
 #include <fcntl.h>
 #include <kvm.h>
@@ -108,6 +109,7 @@ bsd_kvm_target_open (const char *arg, in
   char errbuf[_POSIX2_LINE_MAX];
   char *execfile = NULL;
   kvm_t *temp_kd;
+  struct inferior *inf;
   char *filename = NULL;
 
   target_preopen (from_tty);
@@ -136,6 +138,12 @@ bsd_kvm_target_open (const char *arg, in
   core_kd = temp_kd;
   push_target (&bsd_kvm_ops);
 
+  inf = add_inferior_silent (bsd_kvm_ptid.pid ());
+  inf->aspace = maybe_new_address_space ();
+  inf->pspace = new program_space (inf->aspace);
+
+  inf->gdbarch = get_current_arch ();
+
   add_thread_silent (bsd_kvm_ptid);
   inferior_ptid = bsd_kvm_ptid;
 
@@ -273,6 +281,27 @@ bsd_kvm_target::fetch_registers (struct 
       return;
     }
 
+#if 1 /* TODO: HAVE_STRUCT_LWP_L_ADDR */
+  memset (nl, 0, sizeof nl);
+  nl[0].n_name = "_lwp0";
+
+  if (kvm_nlist (core_kd, nl) == -1)
+    error (("%s"), kvm_geterr (core_kd));
+
+  if (nl[0].n_value != 0)
+    {
+      struct pcb *paddr;
+
+      /* Found lwp0.  */
+      nl[0].n_value += offsetof (struct lwp, l_addr);
+      if (kvm_read (core_kd, nl[0].n_value, &paddr, sizeof paddr) == -1)
+	error (("%s"), kvm_geterr (core_kd));
+
+      bsd_kvm_fetch_pcb (regcache, paddr);
+      return;
+    }
+#endif
+
 #ifdef HAVE_STRUCT_THREAD_TD_PCB
   /* In FreeBSD kernels for 5.0-RELEASE and later, the PCB no longer
      lives in `struct proc' but in `struct thread'.  The `struct
