$NetBSD$

--- gdb/nbsd-tdep.c.orig	2020-03-25 17:24:08.000000000 +0000
+++ gdb/nbsd-tdep.c
@@ -22,6 +22,282 @@
 #include "defs.h"
 #include "solib-svr4.h"
 #include "nbsd-tdep.h"
+#include "gdbarch.h"
+
+enum
+  {
+   NBSD_SIGHUP = 1,
+   NBSD_SIGINT = 2,
+   NBSD_SIGQUIT = 3,
+   NBSD_SIGILL = 4,
+   NBSD_SIGTRAP = 5,
+   NBSD_SIGABRT = 6,
+   NBSD_SIGEMT = 7,
+   NBSD_SIGFPE = 8,
+   NBSD_SIGKILL = 9,
+   NBSD_SIGBUS = 10,
+   NBSD_SIGSEGV = 11,
+   NBSD_SIGSYS = 12,
+   NBSD_SIGPIPE = 13,
+   NBSD_SIGALRM = 14,
+   NBSD_SIGTERM = 15,
+   NBSD_SIGURG = 16,
+   NBSD_SIGSTOP = 17,
+   NBSD_SIGTSTP = 18,
+   NBSD_SIGCONT = 19,
+   NBSD_SIGCHLD = 20,
+   NBSD_SIGTTIN = 21,
+   NBSD_SIGTTOU = 22,
+   NBSD_SIGIO = 23,
+   NBSD_SIGXCPU = 24,
+   NBSD_SIGXFSZ = 25,
+   NBSD_SIGVTALRM = 26,
+   NBSD_SIGPROF = 27,
+   NBSD_SIGWINCH = 28,
+   NBSD_SIGINFO = 29,
+   NBSD_SIGUSR1 = 30,
+   NBSD_SIGUSR2 = 31,
+   NBSD_SIGPWR = 32,
+   NBSD_SIGRTMIN = 32,
+   NBSD_SIGRTMAX = 63,
+  };
+
+/* Implement the "gdb_signal_from_target" gdbarch method.  */
+
+static enum gdb_signal
+nbsd_gdb_signal_from_target (struct gdbarch *gdbarch, int signal)
+{
+  switch (signal)
+    {
+    case 0:
+      return GDB_SIGNAL_0;
+
+    case NBSD_SIGHUP:
+      return GDB_SIGNAL_HUP;
+
+    case NBSD_SIGINT:
+      return GDB_SIGNAL_INT;
+
+    case NBSD_SIGQUIT:
+      return GDB_SIGNAL_QUIT;
+
+    case NBSD_SIGILL:
+      return GDB_SIGNAL_ILL;
+
+    case NBSD_SIGTRAP:
+      return GDB_SIGNAL_TRAP;
+
+    case NBSD_SIGABRT:
+      return GDB_SIGNAL_ABRT;
+
+    case NBSD_SIGEMT:
+      return GDB_SIGNAL_EMT;
+
+    case NBSD_SIGFPE:
+      return GDB_SIGNAL_FPE;
+
+    case NBSD_SIGKILL:
+      return GDB_SIGNAL_KILL;
+
+    case NBSD_SIGBUS:
+      return GDB_SIGNAL_BUS;
+
+    case NBSD_SIGSEGV:
+      return GDB_SIGNAL_SEGV;
+
+    case NBSD_SIGSYS:
+      return GDB_SIGNAL_SYS;
+
+    case NBSD_SIGPIPE:
+      return GDB_SIGNAL_PIPE;
+
+    case NBSD_SIGALRM:
+      return GDB_SIGNAL_ALRM;
+
+    case NBSD_SIGTERM:
+      return GDB_SIGNAL_TERM;
+
+    case NBSD_SIGURG:
+      return GDB_SIGNAL_URG;
+
+    case NBSD_SIGSTOP:
+      return GDB_SIGNAL_STOP;
+
+    case NBSD_SIGTSTP:
+      return GDB_SIGNAL_TSTP;
+
+    case NBSD_SIGCONT:
+      return GDB_SIGNAL_CONT;
+
+    case NBSD_SIGCHLD:
+      return GDB_SIGNAL_CHLD;
+
+    case NBSD_SIGTTIN:
+      return GDB_SIGNAL_TTIN;
+
+    case NBSD_SIGTTOU:
+      return GDB_SIGNAL_TTOU;
+
+    case NBSD_SIGIO:
+      return GDB_SIGNAL_IO;
+
+    case NBSD_SIGXCPU:
+      return GDB_SIGNAL_XCPU;
+
+    case NBSD_SIGXFSZ:
+      return GDB_SIGNAL_XFSZ;
+
+    case NBSD_SIGVTALRM:
+      return GDB_SIGNAL_VTALRM;
+
+    case NBSD_SIGPROF:
+      return GDB_SIGNAL_PROF;
+
+    case NBSD_SIGWINCH:
+      return GDB_SIGNAL_WINCH;
+
+    case NBSD_SIGINFO:
+      return GDB_SIGNAL_INFO;
+
+    case NBSD_SIGUSR1:
+      return GDB_SIGNAL_USR1;
+
+    case NBSD_SIGUSR2:
+      return GDB_SIGNAL_USR2;
+
+    /* SIGTHR is the same as SIGLWP on FreeBSD. */
+    case NBSD_SIGPWR:
+      return GDB_SIGNAL_PWR;
+    }
+
+  if (signal >= NBSD_SIGRTMIN && signal <= NBSD_SIGRTMAX)
+    {
+      int offset = signal - NBSD_SIGRTMIN;
+
+      return (enum gdb_signal) ((int) GDB_SIGNAL_REALTIME_65 + offset);
+    }
+
+  return GDB_SIGNAL_UNKNOWN;
+}
+
+/* Implement the "gdb_signal_to_target" gdbarch method.  */
+
+static int
+nbsd_gdb_signal_to_target (struct gdbarch *gdbarch,
+                enum gdb_signal signal)
+{
+  switch (signal)
+    {
+    case GDB_SIGNAL_0:
+      return 0;
+
+    case GDB_SIGNAL_HUP:
+      return NBSD_SIGHUP;
+
+    case GDB_SIGNAL_INT:
+      return NBSD_SIGINT;
+
+    case GDB_SIGNAL_QUIT:
+      return NBSD_SIGQUIT;
+
+    case GDB_SIGNAL_ILL:
+      return NBSD_SIGILL;
+
+    case GDB_SIGNAL_TRAP:
+      return NBSD_SIGTRAP;
+
+    case GDB_SIGNAL_ABRT:
+      return NBSD_SIGABRT;
+
+    case GDB_SIGNAL_EMT:
+      return NBSD_SIGEMT;
+
+    case GDB_SIGNAL_FPE:
+      return NBSD_SIGFPE;
+
+    case GDB_SIGNAL_KILL:
+      return NBSD_SIGKILL;
+
+    case GDB_SIGNAL_BUS:
+      return NBSD_SIGBUS;
+
+    case GDB_SIGNAL_SEGV:
+      return NBSD_SIGSEGV;
+
+    case GDB_SIGNAL_SYS:
+      return NBSD_SIGSYS;
+
+    case GDB_SIGNAL_PIPE:
+      return NBSD_SIGPIPE;
+
+    case GDB_SIGNAL_ALRM:
+      return NBSD_SIGALRM;
+
+    case GDB_SIGNAL_TERM:
+      return NBSD_SIGTERM;
+
+    case GDB_SIGNAL_URG:
+      return NBSD_SIGURG;
+
+    case GDB_SIGNAL_STOP:
+      return NBSD_SIGSTOP;
+
+    case GDB_SIGNAL_TSTP:
+      return NBSD_SIGTSTP;
+
+    case GDB_SIGNAL_CONT:
+      return NBSD_SIGCONT;
+
+    case GDB_SIGNAL_CHLD:
+      return NBSD_SIGCHLD;
+
+    case GDB_SIGNAL_TTIN:
+      return NBSD_SIGTTIN;
+
+    case GDB_SIGNAL_TTOU:
+      return NBSD_SIGTTOU;
+
+    case GDB_SIGNAL_IO:
+      return NBSD_SIGIO;
+
+    case GDB_SIGNAL_XCPU:
+      return NBSD_SIGXCPU;
+
+    case GDB_SIGNAL_XFSZ:
+      return NBSD_SIGXFSZ;
+
+    case GDB_SIGNAL_VTALRM:
+      return NBSD_SIGVTALRM;
+
+    case GDB_SIGNAL_PROF:
+      return NBSD_SIGPROF;
+
+    case GDB_SIGNAL_WINCH:
+      return NBSD_SIGWINCH;
+
+    case GDB_SIGNAL_INFO:
+      return NBSD_SIGINFO;
+
+    case GDB_SIGNAL_USR1:
+      return NBSD_SIGUSR1;
+
+    case GDB_SIGNAL_USR2:
+      return NBSD_SIGUSR2;
+
+    case GDB_SIGNAL_PWR:
+      return NBSD_SIGPWR;
+    }
+
+  if (signal >= GDB_SIGNAL_REALTIME_65
+      && signal <= GDB_SIGNAL_REALTIME_126)
+    {
+      int offset = signal - GDB_SIGNAL_REALTIME_65;
+
+      return NBSD_SIGRTMIN + offset;
+    }
+
+  return -1;
+}
 
 /* FIXME: kettenis/20060115: We should really eliminate the next two
    functions completely.  */
@@ -47,3 +323,42 @@ nbsd_pc_in_sigtramp (CORE_ADDR pc, const
   return (func_name != NULL
 	  && startswith (func_name, "__sigtramp"));
 }
+
+/* NetBSD-specific parser for AUXV data with. NetBSD follows the ELF
+   specification, contrary to some other ELF Operating Systems.  */
+
+static int
+nbsd_auxv_parse (struct gdbarch *gdbarch, gdb_byte **readptr,
+		 gdb_byte *endptr, CORE_ADDR *typep, CORE_ADDR *valp)
+{
+  struct type *int_type = builtin_type (gdbarch)->builtin_int;
+  struct type *ptr_type = builtin_type (gdbarch)->builtin_data_ptr;
+  const int sizeof_auxv_type = TYPE_LENGTH (int_type);
+  const int sizeof_auxv_val = TYPE_LENGTH (ptr_type);
+  enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
+  gdb_byte *ptr = *readptr;
+
+  if (endptr == ptr)
+    return 0;
+
+  if (endptr - ptr < 2 * sizeof_auxv_val)
+    return -1;
+
+  *typep = extract_unsigned_integer (ptr, sizeof_auxv_type, byte_order);
+  ptr += sizeof_auxv_val;	/* Alignment.  */
+  *valp = extract_unsigned_integer (ptr, sizeof_auxv_val, byte_order);
+  ptr += sizeof_auxv_val;
+
+  *readptr = ptr;
+  return 1;
+}
+
+/* See nbsd-tdep.h.  */
+
+void
+nbsd_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
+{
+  set_gdbarch_auxv_parse (gdbarch, nbsd_auxv_parse);
+  set_gdbarch_gdb_signal_from_target (gdbarch, nbsd_gdb_signal_from_target);
+  set_gdbarch_gdb_signal_to_target (gdbarch, nbsd_gdb_signal_to_target);
+}
