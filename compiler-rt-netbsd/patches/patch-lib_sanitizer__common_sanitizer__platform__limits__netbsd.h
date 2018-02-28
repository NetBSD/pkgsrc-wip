$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.h.orig	2018-02-27 02:50:00.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.h
@@ -60,6 +60,15 @@ extern unsigned struct_timespec_sz;
 extern unsigned struct_sembuf_sz;
 
 extern unsigned struct_kevent_sz;
+extern unsigned struct_FTS_sz;
+extern unsigned struct_FTSENT_sz;
+extern unsigned struct_regex_sz;
+extern unsigned struct_regmatch_sz;
+
+struct __sanitizer_regmatch {
+  OFF_T rm_so;
+  OFF_T rm_eo;
+};
 
 union __sanitizer_sigval {
   int sival_int;
@@ -377,6 +386,9 @@ extern unsigned path_max;
 
 extern int struct_ttyent_sz;
 
+extern int struct_kinfo_proc_sz;
+extern int struct_kinfo_proc2_sz;
+
 extern int ptrace_pt_io;
 extern int ptrace_pt_lwpinfo;
 extern int ptrace_pt_set_event_mask;
@@ -398,6 +410,7 @@ extern int ptrace_pt_getfpregs;
 extern int ptrace_pt_setdbregs;
 extern int ptrace_pt_getdbregs;
 
+
 struct __sanitizer_ptrace_io_desc {
   int piod_op;
   void *piod_offs;
@@ -462,6 +475,43 @@ struct __sanitizer_ttyent {
   char *ty_class;
 };
 
+
+struct __sanitizer_kvm {
+  const char *program;
+  char *errp;
+  char errbuf[2048]; // _POSIX2_LINE_MAX
+  int pmfd;
+  int vmfd;
+  int swfd;
+  int nlfd;
+  char alive;
+  void *procbase;
+  void *procbase2;
+  void *lwpbase;
+  uptr procbase_len;
+  uptr procbase2_len;
+  uptr lwpbase_len;
+  unsigned long usrstack;
+  unsigned long min_uva, max_uva;
+  int nbpg;
+  char *swapspc;
+  char *argspc, *argbuf;
+  uptr argspc_len;
+  char **argv;
+  int argc;
+  void *kcore_hdr;
+  uptr cpu_dsize;
+  void *cpu_data;
+  u64 dump_off;
+  void *vmst;
+  void *vm_page_buckets;
+  int vm_page_hash_mask;
+  uptr fdalign;
+  void *iobuf;
+  uptr iobufsz;
+  char kernelname[1024];
+};
+
 #define IOC_NRBITS 8
 #define IOC_TYPEBITS 8
 #define IOC_SIZEBITS 14
