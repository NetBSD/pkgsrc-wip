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
@@ -2194,6 +2204,71 @@ extern unsigned IOCTL_SNDCTL_DSP_SILENCE
 
 extern const int si_SEGV_MAPERR;
 extern const int si_SEGV_ACCERR;
+
+extern const unsigned SHA1_CTX_sz;
+extern const unsigned SHA1_return_length;
+extern const unsigned MD2_CTX_sz;
+extern const unsigned MD2_return_length;
+extern const unsigned MD4_CTX_sz;
+extern const unsigned MD4_return_length;
+extern const unsigned MD5_CTX_sz;
+extern const unsigned MD5_return_length;
+extern const unsigned RMD160_CTX_sz;
+extern const unsigned RMD160_return_length;
+
+#define SHA2_EXTERN(LEN)\
+  extern const unsigned SHA##LEN##_CTX_sz; \
+  extern const unsigned SHA##LEN##_return_length; \
+  extern const unsigned SHA##LEN##_block_length; \
+  extern const unsigned SHA##LEN##_digest_length
+
+SHA2_EXTERN(224);
+SHA2_EXTERN(256);
+SHA2_EXTERN(384);
+SHA2_EXTERN(512);
+
+#undef SHA2_EXTERN
+
+extern const int unvis_valid;
+extern const int unvis_validpush;
+
+typedef struct __sanitizer_modctl_load {
+  const char *ml_filename;
+  int ml_flags;
+  const char *ml_props;
+  uptr ml_propslen;
+} __sanitizer_modctl_load_t;
+extern const int modctl_load;
+extern const int modctl_unload;
+extern const int modctl_stat;
+extern const int modctl_exists;
+extern const unsigned fpos_t_sz;
+
+struct __sanitizer_cdbr {
+  void (*unmap)(void *, void *, uptr);
+  void *cookie;
+  u8 *mmap_base;
+  uptr mmap_size;
+
+  u8 *hash_base;
+  u8 *offset_base;
+  u8 *data_base;
+
+  u32 data_size;
+  u32 entries;
+  u32 entries_index;
+  u32 seed;
+
+  u8 offset_size;
+  u8 index_size;
+
+  u32 entries_m;
+  u32 entries_index_m;
+  u8 entries_s1, entries_s2;
+  u8 entries_index_s1, entries_index_s2;
+};
+
+extern const int setvbuf_bufsiz;
 }  // namespace __sanitizer
 
 #define CHECK_TYPE_SIZE(TYPE) \
