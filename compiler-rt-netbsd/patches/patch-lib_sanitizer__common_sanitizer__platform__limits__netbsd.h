$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.h.orig	2018-04-25 21:13:40.000000000 +0000
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
@@ -396,6 +405,7 @@ extern int ptrace_pt_getfpregs;
 extern int ptrace_pt_setdbregs;
 extern int ptrace_pt_getdbregs;
 
+
 struct __sanitizer_ptrace_io_desc {
   int piod_op;
   void *piod_offs;
@@ -2194,6 +2204,28 @@ extern unsigned IOCTL_SNDCTL_DSP_SILENCE
 
 extern const int si_SEGV_MAPERR;
 extern const int si_SEGV_ACCERR;
+
+extern unsigned SHA1_CTX_sz;
+extern unsigned SHA1_return_length;
+extern unsigned MD2_CTX_sz;
+extern unsigned MD2_return_length;
+extern unsigned MD4_CTX_sz;
+extern unsigned MD4_return_length;
+extern unsigned MD5_CTX_sz;
+extern unsigned MD5_return_length;
+extern int unvis_valid;
+extern int unvis_validpush;
+
+typedef struct __sanitizer_modctl_load {
+  const char *ml_filename;
+  int ml_flags;
+  const char *ml_props;
+  uptr ml_propslen;
+} __sanitizer_modctl_load_t;
+extern int modctl_load;
+extern int modctl_unload;
+extern int modctl_stat;
+extern int modctl_exists;
 }  // namespace __sanitizer
 
 #define CHECK_TYPE_SIZE(TYPE) \
