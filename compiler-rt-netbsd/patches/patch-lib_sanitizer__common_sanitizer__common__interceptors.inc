$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2018-02-06 15:16:27.867133351 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -36,6 +36,7 @@
 //   COMMON_INTERCEPTOR_MEMCPY_IMPL
 //   COMMON_INTERCEPTOR_COPY_STRING
 //   COMMON_INTERCEPTOR_STRNDUP_IMPL
+//   COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE
 //===----------------------------------------------------------------------===//
 
 #include "interception/interception.h"
@@ -76,6 +77,11 @@
 #define ctime __ctime50
 #define ctime_r __ctime_r50
 #define devname __devname50
+#define fts_children __fts_children60
+#define fts_close __fts_close60
+#define fts_open __fts_open60
+#define fts_read __fts_read60
+#define fts_set __fts_set60
 #define getitimer __getitimer50
 #define getpwent __getpwent50
 #define getpwnam __getpwnam50
@@ -91,6 +97,7 @@
 #define gmtime_r __gmtime_r50
 #define localtime __locatime50
 #define localtime_r __localtime_r50
+#define lstat __lstat50
 #define mktime __mktime50
 #define opendir __opendir30
 #define readdir __readdir30
@@ -109,6 +116,9 @@
 #define times __times13
 #define wait3 __wait350
 #define wait4 __wait450
+extern const unsigned short *_ctype_tab_;
+extern const short *_toupper_tab_;
+extern const short *_tolower_tab_;
 #endif
 
 // Platform-specific options.
@@ -281,6 +291,10 @@ bool PlatformHasDifferentMemcpyAndMemmov
   return new_mem;
 #endif
 
+#ifndef COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE
+#define COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE
+#endif
+
 struct FileMetadata {
   // For open_memstream().
   char **addr;
@@ -1231,6 +1245,7 @@ static void unpoison_tm(void *ctx, __san
 INTERCEPTOR(__sanitizer_tm *, localtime, unsigned long *timep) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, localtime, timep);
+  COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE;
   __sanitizer_tm *res = REAL(localtime)(timep);
   if (res) {
     COMMON_INTERCEPTOR_READ_RANGE(ctx, timep, sizeof(*timep));
@@ -1241,6 +1256,7 @@ INTERCEPTOR(__sanitizer_tm *, localtime,
 INTERCEPTOR(__sanitizer_tm *, localtime_r, unsigned long *timep, void *result) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, localtime_r, timep, result);
+  COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE;
   __sanitizer_tm *res = REAL(localtime_r)(timep, result);
   if (res) {
     COMMON_INTERCEPTOR_READ_RANGE(ctx, timep, sizeof(*timep));
@@ -1251,6 +1267,7 @@ INTERCEPTOR(__sanitizer_tm *, localtime_
 INTERCEPTOR(__sanitizer_tm *, gmtime, unsigned long *timep) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, gmtime, timep);
+  COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE;
   __sanitizer_tm *res = REAL(gmtime)(timep);
   if (res) {
     COMMON_INTERCEPTOR_READ_RANGE(ctx, timep, sizeof(*timep));
@@ -1261,6 +1278,7 @@ INTERCEPTOR(__sanitizer_tm *, gmtime, un
 INTERCEPTOR(__sanitizer_tm *, gmtime_r, unsigned long *timep, void *result) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, gmtime_r, timep, result);
+  COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE;
   __sanitizer_tm *res = REAL(gmtime_r)(timep, result);
   if (res) {
     COMMON_INTERCEPTOR_READ_RANGE(ctx, timep, sizeof(*timep));
@@ -1271,6 +1289,7 @@ INTERCEPTOR(__sanitizer_tm *, gmtime_r, 
 INTERCEPTOR(char *, ctime, unsigned long *timep) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, ctime, timep);
+  COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE;
   // FIXME: under ASan the call below may write to freed memory and corrupt
   // its metadata. See
   // https://github.com/google/sanitizers/issues/321.
@@ -1284,6 +1303,7 @@ INTERCEPTOR(char *, ctime, unsigned long
 INTERCEPTOR(char *, ctime_r, unsigned long *timep, char *result) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, ctime_r, timep, result);
+  COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE;
   // FIXME: under ASan the call below may write to freed memory and corrupt
   // its metadata. See
   // https://github.com/google/sanitizers/issues/321.
@@ -1297,6 +1317,7 @@ INTERCEPTOR(char *, ctime_r, unsigned lo
 INTERCEPTOR(char *, asctime, __sanitizer_tm *tm) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, asctime, tm);
+  COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE;
   // FIXME: under ASan the call below may write to freed memory and corrupt
   // its metadata. See
   // https://github.com/google/sanitizers/issues/321.
@@ -1310,6 +1331,7 @@ INTERCEPTOR(char *, asctime, __sanitizer
 INTERCEPTOR(char *, asctime_r, __sanitizer_tm *tm, char *result) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, asctime_r, tm, result);
+  COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE;
   // FIXME: under ASan the call below may write to freed memory and corrupt
   // its metadata. See
   // https://github.com/google/sanitizers/issues/321.
@@ -1323,6 +1345,7 @@ INTERCEPTOR(char *, asctime_r, __sanitiz
 INTERCEPTOR(long, mktime, __sanitizer_tm *tm) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, mktime, tm);
+  COMMON_INTERCEPTOR_LOCALTIME_AND_FRIEND_SCOPE;
   COMMON_INTERCEPTOR_READ_RANGE(ctx, &tm->tm_sec, sizeof(tm->tm_sec));
   COMMON_INTERCEPTOR_READ_RANGE(ctx, &tm->tm_min, sizeof(tm->tm_min));
   COMMON_INTERCEPTOR_READ_RANGE(ctx, &tm->tm_hour, sizeof(tm->tm_hour));
@@ -1705,6 +1728,7 @@ FORMAT_INTERCEPTOR_IMPL(__isoc99_snprint
 
 #if SANITIZER_INTERCEPT_IOCTL
 #include "sanitizer_common_interceptors_ioctl.inc"
+#include "sanitizer_netbsd_interceptors_ioctl.inc"
 INTERCEPTOR(int, ioctl, int d, unsigned long request, ...) {
   // We need a frame pointer, because we call into ioctl_common_[pre|post] which
   // can trigger a report and we need to be able to unwind through this
@@ -3190,7 +3214,14 @@ INTERCEPTOR(char *, setlocale, int categ
   if (locale)
     COMMON_INTERCEPTOR_READ_RANGE(ctx, locale, REAL(strlen)(locale) + 1);
   char *res = REAL(setlocale)(category, locale);
-  if (res) COMMON_INTERCEPTOR_WRITE_RANGE(ctx, res, REAL(strlen)(res) + 1);
+  if (res) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, res, REAL(strlen)(res) + 1);
+#if SANITIZER_NETBSD
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, _ctype_tab_, 257 * sizeof(short));
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, _toupper_tab_, 257 * sizeof(short));
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, _tolower_tab_, 257 * sizeof(short));
+#endif
+  }
   return res;
 }
 
@@ -6277,6 +6308,22 @@ INTERCEPTOR(int, stat, const char *path,
 #define INIT_STAT
 #endif
 
+#if SANITIZER_INTERCEPT_LSTAT
+INTERCEPTOR(int, lstat, const char *path, void *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, lstat, path, buf);
+  if (common_flags()->intercept_stat)
+    COMMON_INTERCEPTOR_READ_STRING(ctx, path, 0);
+  int res = REAL(lstat)(path, buf);
+  if (!res)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, __sanitizer::struct_stat_sz);
+  return res;
+}
+#define INIT_LSTAT COMMON_INTERCEPT_FUNCTION(lstat)
+#else
+#define INIT_LSTAT
+#endif
+
 #if SANITIZER_INTERCEPT___XSTAT
 INTERCEPTOR(int, __xstat, int version, const char *path, void *buf) {
   void *ctx;
@@ -6789,6 +6836,869 @@ INTERCEPTOR(int, devname_r, u64 dev, u32
 #define INIT_DEVNAME_R
 #endif
 
+#if SANITIZER_INTERCEPT_KVM
+INTERCEPTOR(int, kvm_close, struct __sanitizer_kvm *kd) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_close, kd);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_close)(kd);
+}
+
+INTERCEPTOR(int, kvm_dump_header, struct __sanitizer_kvm *kd,
+            bool (*write_buf)(void*, void*, uptr), void *cookie, int dumpsize) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_dump_header, kd, write_buf, cookie,
+                           dumpsize);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_dump_header)(kd, write_buf, cookie, dumpsize);
+}
+
+INTERCEPTOR(int, kvm_dump_inval, struct __sanitizer_kvm *kd) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_dump_inval, kd);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_dump_inval)(kd);
+}
+
+INTERCEPTOR(int, kvm_dump_mkheader, struct __sanitizer_kvm *kd,
+            OFF_T dump_off) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_dump_mkheader, kd, dump_off);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_dump_mkheader)(kd, dump_off);
+}
+
+INTERCEPTOR(int, kvm_dump_wrtheader, struct __sanitizer_kvm *kd,
+            __sanitizer_FILE *fp, int dumpsize) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_dump_wrtheader, kd, fp, dumpsize);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_dump_wrtheader)(kd, fp, dumpsize);
+}
+
+INTERCEPTOR(char **, kvm_getargv, struct __sanitizer_kvm *kd, void *kp,
+            int nchr) {
+  void *ctx;
+  char **argv;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getargv, kd, kp, nchr);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  if (kp)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kp, struct_kinfo_proc_sz);
+  argv = REAL(kvm_getargv)(kd, kp, nchr);
+  if (argv) {
+    char **p = argv;
+    while (*p) {
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(char **));
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *p, REAL(strlen)(*p) + 1);
+      p++;
+    }
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(char **));
+  }
+  return argv;
+}
+
+INTERCEPTOR(char **, kvm_getargv2, struct __sanitizer_kvm *kd, void *kp,
+            int nchr) {
+  void *ctx;
+  char **argv;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getargv2, kd, kp, nchr);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  if (kp)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kp, struct_kinfo_proc2_sz);
+  argv = REAL(kvm_getargv2)(kd, kp, nchr);
+  if (argv) {
+    char **p = argv;
+    while (*p) {
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(char **));
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *p, REAL(strlen)(*p) + 1);
+      p++;
+    }
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(char **));
+  }
+  return argv;
+}
+
+INTERCEPTOR(char **, kvm_getenvv, struct __sanitizer_kvm *kd, void *kp,
+            int nchr) {
+  void *ctx;
+  char **argv;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getenvv, kd, kp, nchr);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  if (kp)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kp, struct_kinfo_proc_sz);
+  argv = REAL(kvm_getenvv)(kd, kp, nchr);
+  if (argv) {
+    char **p = argv;
+    while (*p) {
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(char **));
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *p, REAL(strlen)(*p) + 1);
+      p++;
+    }
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(char **));
+  }
+  return argv;
+}
+
+INTERCEPTOR(char **, kvm_getenvv2, struct __sanitizer_kvm *kd, void *kp,
+            int nchr) {
+  void *ctx;
+  char **argv;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getenvv2, kd, kp, nchr);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  if (kp)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kp, struct_kinfo_proc2_sz);
+  argv = REAL(kvm_getenvv2)(kd, kp, nchr);
+  if (argv) {
+    char **p = argv;
+    while (*p) {
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(char **));
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *p, REAL(strlen)(*p) + 1);
+      p++;
+    }
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(char **));
+  }
+  return argv;
+}
+
+INTERCEPTOR(char *, kvm_geterr, struct __sanitizer_kvm *kd) {
+  void *ctx;
+  char *res;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_geterr, kd);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  res = REAL(kvm_geterr)(kd);
+  if (res)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, res, REAL(strlen)(res) + 1);
+  return res;
+}
+
+INTERCEPTOR(int, kvm_getloadavg, struct __sanitizer_kvm *kd, double loadavg[],
+            int nelem) {
+  void *ctx;
+  int res;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getloadavg, kd, loadavg, nelem);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  res = REAL(kvm_getloadavg)(kd, loadavg, nelem);
+  if (res > 0)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, loadavg, res * sizeof(*loadavg));
+  return res;
+}
+
+INTERCEPTOR(char *, kvm_getfiles, struct __sanitizer_kvm *kd, int op, int arg,
+            int *cnt) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getfiles, kd, op, arg, cnt);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_getfiles)(kd, op, arg, cnt);
+}
+
+INTERCEPTOR(char *, kvm_getkernelname, struct __sanitizer_kvm *kd) {
+  void *ctx;
+  char *name;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getkernelname, kd);
+  name = REAL(kvm_getkernelname)(kd);
+  if (name)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, name, REAL(strlen)(name) + 1);
+  return name;
+}
+
+INTERCEPTOR(void *, kvm_getlwps, struct __sanitizer_kvm *kd, int pid,
+            unsigned long paddr, uptr esize, int *cnt) {
+  void *ctx;
+  void *res;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getlwps, kd, pid, paddr, esize, cnt);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  res = REAL(kvm_getlwps)(kd, pid, paddr, esize, cnt);
+  if (res) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, cnt, sizeof(int));
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, res, esize * (*cnt));
+  }
+  return res;
+}
+
+INTERCEPTOR(void *, kvm_getproc2, struct __sanitizer_kvm *kd, int op, int arg,
+            uptr esize, int *cnt) {
+  void *ctx;
+  void *res;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getproc2, kd, op, arg, esize, cnt);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  res = REAL(kvm_getproc2)(kd, op, arg, esize, cnt);
+  if (res) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, cnt, sizeof(int));
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, res, esize * (*cnt));
+  }
+  return res;
+}
+
+INTERCEPTOR(void *, kvm_getprocs, struct __sanitizer_kvm *kd, int op, int arg,
+            int *cnt) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getprocs, kd, op, arg, cnt);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_getprocs)(kd, op, arg, cnt);
+}
+
+INTERCEPTOR(int, kvm_nlist, struct __sanitizer_kvm *kd, void *nl) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_nlist, kd, nl);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_nlist)(kd, nl);
+}
+
+INTERCEPTOR(struct __sanitizer_kvm *, kvm_open, char *uf, char *mf, char *sf,
+            int flag, char *program) {
+  void *ctx;
+  struct __sanitizer_kvm *kd;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_open, uf, mf, sf, flag, program);
+  if (uf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, uf, REAL(strlen)(uf) + 1);
+  if (mf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, mf, REAL(strlen)(mf) + 1);
+  if (sf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sf, REAL(strlen)(sf) + 1);
+  if (program)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, program, REAL(strlen)(program) + 1);
+  kd = REAL(kvm_open)(uf, mf, sf, flag, program);
+  if (kd)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return kd;
+}
+
+INTERCEPTOR(struct __sanitizer_kvm *, kvm_openfiles, char *uf, char *mf,
+            char *sf, int flag, char *errout) {
+  void *ctx;
+  struct __sanitizer_kvm *kd;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_openfiles, uf, mf, sf, flag, errout);
+  if (uf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, uf, REAL(strlen)(uf) + 1);
+  if (mf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, mf, REAL(strlen)(mf) + 1);
+  if (sf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sf, REAL(strlen)(sf) + 1);
+  kd = REAL(kvm_openfiles)(uf, mf, sf, flag, errout);
+  if (kd)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  if (!kd && errout)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, errout, REAL(strlen)(errout) + 1);
+  return kd;
+}
+
+INTERCEPTOR(uptr, kvm_read, struct __sanitizer_kvm *kd, unsigned long kva,
+            void *buf, uptr len) {
+  void *ctx;
+  uptr res;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_read, kd, kva, buf, len);
+  res = REAL(kvm_read)(kd, kva, buf, len);
+  if (res)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, res);
+  return res;
+}
+
+INTERCEPTOR(uptr, kvm_uread, struct __sanitizer_kvm *kd, unsigned long uva,
+            void *buf, uptr len) {
+  void *ctx;
+  uptr res;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_uread, kd, uva, buf, len);
+  res = REAL(kvm_uread)(kd, uva, buf, len);
+  if (res)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, res);
+  return res;
+}
+
+INTERCEPTOR(uptr, kvm_write, struct __sanitizer_kvm *kd, unsigned long kva,
+            void *buf, uptr len) {
+  void *ctx;
+  uptr res;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_write, kd, kva, buf, len);
+  res = REAL(kvm_uread)(kd, kva, buf, len);
+  if (buf && res > 0)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, buf, res);
+  return res;
+}
+
+#define INIT_KVM \
+  COMMON_INTERCEPT_FUNCTION(kvm_close); \
+  COMMON_INTERCEPT_FUNCTION(kvm_dump_header); \
+  COMMON_INTERCEPT_FUNCTION(kvm_dump_inval); \
+  COMMON_INTERCEPT_FUNCTION(kvm_dump_mkheader); \
+  COMMON_INTERCEPT_FUNCTION(kvm_dump_wrtheader); \
+  COMMON_INTERCEPT_FUNCTION(kvm_getargv); \
+  COMMON_INTERCEPT_FUNCTION(kvm_getargv2); \
+  COMMON_INTERCEPT_FUNCTION(kvm_getenvv); \
+  COMMON_INTERCEPT_FUNCTION(kvm_getenvv2); \
+  COMMON_INTERCEPT_FUNCTION(kvm_geterr); \
+  COMMON_INTERCEPT_FUNCTION(kvm_getfiles); \
+  COMMON_INTERCEPT_FUNCTION(kvm_getkernelname); \
+  COMMON_INTERCEPT_FUNCTION(kvm_getloadavg); \
+  COMMON_INTERCEPT_FUNCTION(kvm_getlwps); \
+  COMMON_INTERCEPT_FUNCTION(kvm_getproc2); \
+  COMMON_INTERCEPT_FUNCTION(kvm_getprocs); \
+  COMMON_INTERCEPT_FUNCTION(kvm_nlist); \
+  COMMON_INTERCEPT_FUNCTION(kvm_open); \
+  COMMON_INTERCEPT_FUNCTION(kvm_openfiles); \
+  COMMON_INTERCEPT_FUNCTION(kvm_read); \
+  COMMON_INTERCEPT_FUNCTION(kvm_uread); \
+  COMMON_INTERCEPT_FUNCTION(kvm_write);
+#else
+#define INIT_KVM
+#endif
+
+#if SANITIZER_INTERCEPT_SYSCTL
+INTERCEPTOR(int, sysctl, int *name, unsigned int namelen, void *oldp,
+            SIZE_T *oldlenp, void *newp, SIZE_T newlen) {
+  void *ctx;
+  int res;
+  COMMON_INTERCEPTOR_ENTER(ctx, sysctl, name, namelen, oldp, oldlenp, newp,
+                           newlen);
+  if (name)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, name, namelen * sizeof(*name));
+  if (newp)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, newp, newlen);
+  res = REAL(sysctl)(name, namelen, oldp, oldlenp, newp, newlen);
+  if (!res) {
+    if (oldlenp)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, oldlenp, sizeof(*oldlenp));
+    if (oldp && oldlenp)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, oldp, *oldlenp);
+  }
+  return res;
+}
+
+INTERCEPTOR(int, sysctlbyname, char *sname, void *oldp, SIZE_T *oldlenp,
+            void *newp, SIZE_T newlen) {
+  void *ctx;
+  int res;
+  COMMON_INTERCEPTOR_ENTER(ctx, sysctlbyname, sname, oldp, oldlenp, newp,
+                           newlen);
+  if (sname)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sname, REAL(strlen)(sname) + 1);
+  res = REAL(sysctlbyname)(sname, oldp, oldlenp, newp, newlen);
+  if (!res) {
+    if (oldlenp)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, oldlenp, sizeof(*oldlenp));
+    if (oldp && oldlenp)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, oldp, *oldlenp);
+  }
+  return res;
+}
+
+INTERCEPTOR(int, sysctlgetmibinfo, char *sname, int *name,
+            unsigned int *namelenp,
+            char *cname, SIZE_T *csz, void **rnode, int v) {
+  void *ctx;
+  int res;
+  COMMON_INTERCEPTOR_ENTER(ctx, sysctlgetmibinfo, sname, name, namelenp, cname,
+                           csz, rnode, v);
+  if (sname)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sname, REAL(strlen)(sname) + 1);
+  // Skip rnode, it's rarely used and not trivial to sanitize
+  // It's also used mostly internally
+  res = REAL(sysctlgetmibinfo)(sname, name, namelenp, cname, csz, rnode, v);
+  if (!res) {
+    if (namelenp)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, namelenp, sizeof(*namelenp));
+    if (name && namelenp)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, name, *namelenp);
+  }
+  if (cname && csz) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, csz, sizeof(*csz));
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, cname, *csz);
+  }
+  return res;
+}
+
+INTERCEPTOR(int, sysctlnametomib, const char *sname, int *name,
+            SIZE_T *namelenp) {
+  void *ctx;
+  int res;
+  COMMON_INTERCEPTOR_ENTER(ctx, sysctlnametomib, sname, name, namelenp);
+  if (sname)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sname, REAL(strlen)(sname) + 1);
+  res = REAL(sysctlnametomib)(sname, name, namelenp);
+  if (!res) {
+    if (namelenp)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, namelenp, sizeof(*namelenp));
+    if (name && namelenp)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, name, *namelenp);
+  }
+  return res;
+}
+
+INTERCEPTOR(void *, asysctl, const int *name, SIZE_T namelen, SIZE_T *len) {
+  void *ctx;
+  void *res;
+  COMMON_INTERCEPTOR_ENTER(ctx, asysctl, name, namelen, len);
+  if (name)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, name, sizeof(*name) * namelen);
+  res = REAL(asysctl)(name, namelen, len);
+  if (len)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, len, sizeof(*len));
+  if (res && len)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, res, *len);
+  return res;
+}
+
+INTERCEPTOR(void *, asysctlbyname, const char *sname, SIZE_T *len) {
+  void *ctx;
+  void *res;
+  COMMON_INTERCEPTOR_ENTER(ctx, asysctlbyname, sname, len);
+  if (sname)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sname, REAL(strlen)(sname) + 1);
+  res = REAL(asysctlbyname)(sname, len);
+  if (len)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, len, sizeof(*len));
+  if (res && len)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, res, *len);
+  return res;
+}
+#define INIT_SYSCTL \
+  COMMON_INTERCEPT_FUNCTION(sysctl); \
+  COMMON_INTERCEPT_FUNCTION(sysctlbyname); \
+  COMMON_INTERCEPT_FUNCTION(sysctlgetmibinfo); \
+  COMMON_INTERCEPT_FUNCTION(sysctlnametomib); \
+  COMMON_INTERCEPT_FUNCTION(asysctl); \
+  COMMON_INTERCEPT_FUNCTION(asysctlbyname);
+#else
+#define INIT_SYSCTL
+#endif
+
+#if SANITIZER_INTERCEPT_ATOF
+INTERCEPTOR(double, atof, char *nptr) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, atof, nptr);
+  if (nptr) {
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, nptr, REAL(strlen)(nptr) + 1);
+  }
+  return REAL(atof)(nptr); // strtof // todo atoi atol
+}
+#define INIT_ATOF COMMON_INTERCEPT_FUNCTION(atof)
+#else
+#define INIT_ATOF
+#endif
+
+#if SANITIZER_INTERCEPT_GETTTYENT
+INTERCEPTOR(struct __sanitizer_ttyent *, getttyent, void) {
+  void *ctx;
+  struct __sanitizer_ttyent *ttyent;
+  COMMON_INTERCEPTOR_ENTER(ctx, getttyent);
+  ttyent = REAL(getttyent)();
+  if (ttyent) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ttyent, struct_ttyent_sz);
+  }
+  return ttyent;
+}
+INTERCEPTOR(struct __sanitizer_ttyent *, getttynam, char *name) {
+  void *ctx;
+  struct __sanitizer_ttyent *ttyent;
+  COMMON_INTERCEPTOR_ENTER(ctx, getttynam, name);
+  if (name)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, name, REAL(strlen)(name) + 1);
+  ttyent = REAL(getttynam)(name);
+  if (ttyent) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ttyent, struct_ttyent_sz);
+  }
+  return ttyent;
+}
+INTERCEPTOR(int, setttyent) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, setttyent);
+  return REAL(setttyent)();
+}
+INTERCEPTOR(int, setttyentpath, char *path) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, setttyentpath, path);
+  if (path)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, path, REAL(strlen)(path) + 1);
+  return REAL(setttyentpath)(path);
+}
+INTERCEPTOR(int, endttyent) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, endttyent);
+  return REAL(endttyent)();
+}
+#define INIT_GETTTYENT \
+  COMMON_INTERCEPT_FUNCTION(getttyent); \
+  COMMON_INTERCEPT_FUNCTION(getttynam); \
+  COMMON_INTERCEPT_FUNCTION(setttyent); \
+  COMMON_INTERCEPT_FUNCTION(setttyentpath); \
+  COMMON_INTERCEPT_FUNCTION(endttyent)
+#else
+#define INIT_GETTTYENT
+#endif
+
+#if SANITIZER_INTERCEPT_FGETLN
+INTERCEPTOR(char *, fgetln, __sanitizer_FILE *stream, SIZE_T *len) {
+  void *ctx;
+  char *str;
+  COMMON_INTERCEPTOR_ENTER(ctx, fgetln, stream, len);
+  str = REAL(fgetln)(stream, len);
+  if (str && len) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, len, sizeof(*len));
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, str, *len);
+  }
+  return str;
+}
+#define INIT_FGETLN COMMON_INTERCEPT_FUNCTION(fgetln)
+#else
+#define INIT_FGETLN
+#endif
+
+#if SANITIZER_INTERCEPT_GETPROTOENT
+INTERCEPTOR(struct __sanitizer_protoent *, getprotoent) {
+  void *ctx;
+  struct __sanitizer_protoent *p;
+  COMMON_INTERCEPTOR_ENTER(ctx, getprotoent);
+  p = REAL(getprotoent)();
+  if (p) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(*p));
+
+    char **pp = p->p_aliases;
+
+    while (*pp) {
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, pp, sizeof(char **));
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *pp, REAL(strlen)(*pp) + 1);
+       pp++;
+    }
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, pp, sizeof(char **));
+  }
+  return p;
+}
+
+INTERCEPTOR(struct __sanitizer_protoent *, getprotobyname, const char *name) {
+  void *ctx;
+  struct __sanitizer_protoent *p;
+  COMMON_INTERCEPTOR_ENTER(ctx, getprotobyname, name);
+  p = REAL(getprotobyname)(name);
+  if (p) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(*p));
+
+    char **pp = p->p_aliases;
+
+    while (*pp) {
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, pp, sizeof(char **));
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *pp, REAL(strlen)(*pp) + 1);
+       pp++;
+    }
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, pp, sizeof(char **));
+  }
+  return p;
+}
+
+INTERCEPTOR(struct __sanitizer_protoent *, getprotobynumber, int proto) {
+  void *ctx;
+  struct __sanitizer_protoent *p;
+  COMMON_INTERCEPTOR_ENTER(ctx, getprotobynumber, proto);
+  p = REAL(getprotobynumber)(proto);
+  if (p) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, p, sizeof(*p));
+
+    char **pp = p->p_aliases;
+
+    while (*pp) {
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, pp, sizeof(char **));
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *pp, REAL(strlen)(*pp) + 1);
+       pp++;
+    }
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, pp, sizeof(char **));
+  }
+  return p;
+}
+
+INTERCEPTOR(void, setprotoent, int stayopen) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, setprotoent, stayopen);
+  return REAL(setprotoent)(stayopen);
+}
+
+INTERCEPTOR(void, endprotoent) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, endprotoent);
+  return REAL(endprotoent)();
+}
+#define INIT_GETPROTOENT \
+  COMMON_INTERCEPT_FUNCTION(getprotoent); \
+  COMMON_INTERCEPT_FUNCTION(getprotobyname); \
+  COMMON_INTERCEPT_FUNCTION(getprotobynumber); \
+  COMMON_INTERCEPT_FUNCTION(setprotoent); \
+  COMMON_INTERCEPT_FUNCTION(endprotoent);
+#else
+#define INIT_GETPROTOENT
+#endif
+
+#if SANITIZER_INTERCEPT_GETNETENT
+INTERCEPTOR(struct __sanitizer_netent *, getnetent) {
+  void *ctx;
+  struct __sanitizer_netent *n;
+  COMMON_INTERCEPTOR_ENTER(ctx, getnetent);
+  n = REAL(getnetent)();
+  if (n) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, n, sizeof(*n));
+
+    char **nn = n->n_aliases;
+
+    while (*nn) {
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, nn, sizeof(char **));
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *nn, REAL(strlen)(*nn) + 1);
+       nn++;
+    }
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, nn, sizeof(char **));
+  }
+  return n;
+}
+
+INTERCEPTOR(struct __sanitizer_netent *, getnetbyname, const char *name) {
+  void *ctx;
+  struct __sanitizer_netent *n;
+  COMMON_INTERCEPTOR_ENTER(ctx, getnetbyname, name);
+  n = REAL(getnetbyname)(name);
+  if (n) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, n, sizeof(*n));
+
+    char **nn = n->n_aliases;
+
+    while (*nn) {
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, nn, sizeof(char **));
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *nn, REAL(strlen)(*nn) + 1);
+       nn++;
+    }
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, nn, sizeof(char **));
+  }
+  return n;
+}
+
+INTERCEPTOR(struct __sanitizer_netent *, getnetbyaddr, u32 net, int type) {
+  void *ctx;
+  struct __sanitizer_netent *n;
+  COMMON_INTERCEPTOR_ENTER(ctx, getnetbyaddr, net, type);
+  n = REAL(getnetbyaddr)(net, type);
+  if (n) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, n, sizeof(*n));
+
+    char **nn = n->n_aliases;
+
+    while (*nn) {
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, nn, sizeof(char **));
+       COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *nn, REAL(strlen)(*nn) + 1);
+       nn++;
+    }
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, nn, sizeof(char **));
+  }
+  return n;
+}
+
+INTERCEPTOR(void, setnetent, int stayopen) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, setnetent, stayopen);
+  return REAL(setnetent)(stayopen);
+}
+
+INTERCEPTOR(void, endnetent) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, endnetent);
+  return REAL(endnetent)();
+}
+#define INIT_GETNETENT \
+  COMMON_INTERCEPT_FUNCTION(getnetent); \
+  COMMON_INTERCEPT_FUNCTION(getnetbyname); \
+  COMMON_INTERCEPT_FUNCTION(getnetbyaddr); \
+  COMMON_INTERCEPT_FUNCTION(setnetent); \
+  COMMON_INTERCEPT_FUNCTION(endnetent);
+#else
+#define INIT_GETNETENT
+#endif
+
+#if SANITIZER_INTERCEPT_FTS
+INTERCEPTOR(void *, fts_open, char * const *path_argv, int options,
+            int (*compar)(void **, void **)) {
+  void *ctx;
+  void *fts;
+  COMMON_INTERCEPTOR_ENTER(ctx, fts_open, path_argv, options, compar);
+  if (path_argv) {
+    char * const *pa = path_argv;
+    while (*pa) {
+       COMMON_INTERCEPTOR_READ_RANGE(ctx, pa, sizeof(char **));
+       COMMON_INTERCEPTOR_READ_RANGE(ctx, *pa, REAL(strlen)(*pa) + 1);
+       pa++;
+    }
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, pa, sizeof(char **));
+  }
+  fts = REAL(fts_open)(path_argv, options, compar);
+  if (fts)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, fts, struct_FTS_sz);
+  return fts;
+}
+
+INTERCEPTOR(void *, fts_read, void *ftsp) {
+  void *ctx;
+  void *ftsent;
+  COMMON_INTERCEPTOR_ENTER(ctx, fts_read, ftsp);
+  COMMON_INTERCEPTOR_READ_RANGE(ctx, ftsp, struct_FTS_sz);
+  ftsent = REAL(fts_read)(ftsp);
+  if (ftsent)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ftsent, struct_FTSENT_sz);
+  return ftsent;
+}
+
+INTERCEPTOR(void *, fts_children, void *ftsp, int options) {
+  void *ctx;
+  void *ftsent;
+  COMMON_INTERCEPTOR_ENTER(ctx, fts_children, ftsp, options);
+  COMMON_INTERCEPTOR_READ_RANGE(ctx, ftsp, struct_FTS_sz);
+  ftsent = REAL(fts_children)(ftsp, options);
+  if (ftsent)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ftsent, struct_FTSENT_sz);
+  return ftsent;
+}
+
+INTERCEPTOR(int, fts_set, void *ftsp, void *f, int options) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, fts_set, ftsp, f, options);
+  COMMON_INTERCEPTOR_READ_RANGE(ctx, ftsp, struct_FTS_sz);
+  COMMON_INTERCEPTOR_READ_RANGE(ctx, f, struct_FTSENT_sz);
+  return REAL(fts_set)(ftsp, f, options);
+}
+
+INTERCEPTOR(int, fts_close, void *ftsp) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, fts_close, ftsp);
+  COMMON_INTERCEPTOR_READ_RANGE(ctx, ftsp, struct_FTS_sz);
+  return REAL(fts_close)(ftsp);
+}
+#define INIT_FTS \
+  COMMON_INTERCEPT_FUNCTION(fts_open); \
+  COMMON_INTERCEPT_FUNCTION(fts_read); \
+  COMMON_INTERCEPT_FUNCTION(fts_children); \
+  COMMON_INTERCEPT_FUNCTION(fts_set); \
+  COMMON_INTERCEPT_FUNCTION(fts_close);
+#else
+#define INIT_FTS
+#endif
+
+#if SANITIZER_INTERCEPT_STRMODE
+INTERCEPTOR(void, strmode, u32 mode, char *bp) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strmode, mode, bp);
+  REAL(strmode)(mode, bp);
+  if (bp)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, bp, REAL(strlen)(bp) + 1);
+}
+#define INIT_STRMODE COMMON_INTERCEPT_FUNCTION(strmode)
+#else
+#define INIT_STRMODE
+#endif
+
+#if SANITIZER_INTERCEPT_REGEX
+INTERCEPTOR(int, regcomp, void *preg, const char *pattern, int cflags) {
+  void *ctx;
+  int res;
+  COMMON_INTERCEPTOR_ENTER(ctx, regcomp, preg, pattern, cflags);
+  if (pattern)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, pattern, REAL(strlen)(pattern) + 1);
+  res = REAL(regcomp)(preg, pattern, cflags);
+  if (!res)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, preg, struct_regex_sz);
+  return res;
+}
+
+INTERCEPTOR(int, regexec, const void *preg, const char *string, SIZE_T nmatch,
+            struct __sanitizer_regmatch *pmatch[], int eflags) {
+  void *ctx;
+  int res;
+  COMMON_INTERCEPTOR_ENTER(ctx, regexec, preg, string, nmatch, pmatch, eflags);
+  if (preg)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, preg, struct_regex_sz);
+  if (string)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, string, REAL(strlen)(string) + 1);
+  res = REAL(regexec)(preg, string, nmatch, pmatch, eflags);
+  if (!res && pmatch)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, pmatch, nmatch * struct_regmatch_sz);
+  return res;
+}
+
+INTERCEPTOR(SIZE_T, regerror, int errcode, const void *preg, char *errbuf,
+            SIZE_T errbuf_size) {
+  void *ctx;
+  SIZE_T res;
+  COMMON_INTERCEPTOR_ENTER(ctx, regerror, errcode, preg, errbuf, errbuf_size);
+  if (preg)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, preg, struct_regex_sz);
+  res = REAL(regerror)(errcode, preg, errbuf, errbuf_size);
+  if (errbuf)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, errbuf, REAL(strlen)(errbuf) + 1);
+  return res;
+}
+
+INTERCEPTOR(void, regfree, const void *preg) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, regfree, preg);
+  if (preg)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, preg, struct_regex_sz);
+  REAL(regfree)(preg);
+}
+
+INTERCEPTOR(SSIZE_T, regnsub, char *buf, SIZE_T bufsiz, const char *sub,
+            const struct __sanitizer_regmatch *rm, const char *str) {
+  void *ctx;
+  SSIZE_T res;
+  COMMON_INTERCEPTOR_ENTER(ctx, regnsub, buf, bufsiz, sub, rm, str);
+  if (sub)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sub, REAL(strlen)(sub) + 1);
+  // Hardcode 10 elements as requested by the documentation as minimum
+  if (rm)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, rm, 10 * struct_regmatch_sz);
+  if (str)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, str, REAL(strlen)(str) + 1);
+  res = REAL(regnsub)(buf, bufsiz, sub, rm, str);
+  if (res > 0 && buf)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, REAL(strlen)(buf) + 1);
+  return res;
+}
+
+INTERCEPTOR(SSIZE_T, regasub, char **buf, const char *sub,
+            const struct __sanitizer_regmatch *rm, const char *sstr) {
+  void *ctx;
+  SSIZE_T res;
+  COMMON_INTERCEPTOR_ENTER(ctx, regasub, buf, sub, rm, sstr);
+  if (sub)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sub, REAL(strlen)(sub) + 1);
+  // Hardcode 10 elements as requested by the documentation as minimum
+  if (rm)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, rm, 10 * struct_regmatch_sz);
+  if (sstr)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sstr, REAL(strlen)(sstr) + 1);
+  res = REAL(regasub)(buf, sub, rm, sstr);
+  if (res > 0 && buf) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, sizeof(char *));
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *buf, REAL(strlen)(*buf) + 1);
+  }
+  return res;
+}
+#define INIT_REGEX \
+  COMMON_INTERCEPT_FUNCTION(regcomp); \
+  COMMON_INTERCEPT_FUNCTION(regexec); \
+  COMMON_INTERCEPT_FUNCTION(regerror); \
+  COMMON_INTERCEPT_FUNCTION(regfree); \
+  COMMON_INTERCEPT_FUNCTION(regnsub); \
+  COMMON_INTERCEPT_FUNCTION(regasub);
+#else
+#define INIT_REGEX
+#endif
+
 static void InitializeCommonInterceptors() {
   static u64 metadata_mem[sizeof(MetadataHashMap) / sizeof(u64) + 1];
   interceptor_metadata_map = new((void *)&metadata_mem) MetadataHashMap();
@@ -6991,6 +7901,7 @@ static void InitializeCommonInterceptors
   INIT_SEND_SENDTO;
   INIT_STAT;
   INIT_EVENTFD_READ_WRITE;
+  INIT_LSTAT;
   INIT___XSTAT;
   INIT___XSTAT64;
   INIT___LXSTAT;
@@ -7016,6 +7927,16 @@ static void InitializeCommonInterceptors
   INIT_STRLCPY;
   INIT_DEVNAME;
   INIT_DEVNAME_R;
+  INIT_KVM;
+  INIT_SYSCTL;
+  INIT_ATOF;
+  INIT_GETTTYENT;
+  INIT_FGETLN;
+  INIT_GETPROTOENT;
+  INIT_GETNETENT;
+  INIT_FTS;
+  INIT_STRMODE;
+  INIT_REGEX;
 
 #if SANITIZER_NETBSD
   COMMON_INTERCEPT_FUNCTION(__libc_mutex_lock);
