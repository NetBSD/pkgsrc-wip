$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.h.orig	2018-02-15 04:24:49.763467018 +0000
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
@@ -113,6 +122,19 @@ struct __sanitizer_shmid_ds {
   void *_shm_internal;
 };
 
+struct __sanitizer_protoent {
+  char *p_name;
+  char **p_aliases;
+  int p_proto;
+};
+
+struct __sanitizer_netent {
+  char *n_name;
+  char **n_aliases;
+  int n_addrtype;
+  u32 n_net;
+};
+
 extern unsigned struct_msqid_ds_sz;
 extern unsigned struct_mq_attr_sz;
 extern unsigned struct_timex_sz;
@@ -362,6 +384,11 @@ extern int glob_altdirfunc;
 
 extern unsigned path_max;
 
+extern int struct_kinfo_proc_sz;
+extern int struct_kinfo_proc2_sz;
+
+extern int struct_ttyent_sz;
+
 extern int ptrace_pt_io;
 extern int ptrace_pt_lwpinfo;
 extern int ptrace_pt_set_event_mask;
@@ -383,6 +410,7 @@ extern int ptrace_pt_getfpregs;
 extern int ptrace_pt_setdbregs;
 extern int ptrace_pt_getdbregs;
 
+
 struct __sanitizer_ptrace_io_desc {
   int piod_op;
   void *piod_offs;
@@ -437,6 +465,53 @@ struct __sanitizer_ifconf {
   } ifc_ifcu;
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
+struct __sanitizer_ttyent {
+  char *ty_name;
+  char *ty_getty;
+  char *ty_type;
+  int ty_status;
+  char *ty_window;
+  char *ty_comment;
+  char *ty_class;
+};
+
 #define IOC_NRBITS 8
 #define IOC_TYPEBITS 8
 #define IOC_SIZEBITS 14
