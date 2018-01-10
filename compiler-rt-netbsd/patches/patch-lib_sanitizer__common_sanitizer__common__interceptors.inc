$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2018-01-08 15:33:14.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -75,6 +75,7 @@
 #define clock_settime __clock_settime50
 #define ctime __ctime50
 #define ctime_r __ctime_r50
+#define devname __devname50
 #define getitimer __getitimer50
 #define getpwent __getpwent50
 #define getpwnam __getpwnam50
@@ -1703,6 +1704,7 @@ FORMAT_INTERCEPTOR_IMPL(__isoc99_snprint
 
 #if SANITIZER_INTERCEPT_IOCTL
 #include "sanitizer_common_interceptors_ioctl.inc"
+#include "sanitizer_netbsd_interceptors_ioctl.inc"
 INTERCEPTOR(int, ioctl, int d, unsigned long request, ...) {
   // We need a frame pointer, because we call into ioctl_common_[pre|post] which
   // can trigger a report and we need to be able to unwind through this
@@ -6452,6 +6454,304 @@ INTERCEPTOR(wchar_t *, wcsncat, wchar_t 
 #define INIT_WCSCAT
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
+INTERCEPTOR(int, kvm_dump_header, struct __sanitizer_kvm *kd, bool (*write_buf)(void*,void*,uptr), void *cookie, int dumpsize) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_dump_header, kd, write_buf, cookie, dumpsize);
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
+INTERCEPTOR(int, kvm_dump_mkheader, struct __sanitizer_kvm *kd, OFF_T dump_off) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_dump_mkheader, kd, dump_off);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_dump_mkheader)(kd, dump_off);
+}
+
+INTERCEPTOR(int, kvm_dump_wrtheader, struct __sanitizer_kvm *kd, __sanitizer_FILE *fp, int dumpsize) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_dump_wrtheader, kd, fp, dumpsize);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_dump_wrtheader)(kd, fp, dumpsize);
+}
+
+INTERCEPTOR(char **, kvm_getargv, struct __sanitizer_kvm *kd, void *kp, int nchr) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getargv, kd, kp, nchr);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  if (kp)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kp, struct_kinfo_proc_sz);
+  return REAL(kvm_getargv)(kd, kp, nchr);
+}
+
+INTERCEPTOR(char **, kvm_getargv2, struct __sanitizer_kvm *kd, void *kp, int nchr) {
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
+INTERCEPTOR(char **, kvm_getenvv, struct __sanitizer_kvm *kd, void *kp, int nchr) {
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
+INTERCEPTOR(char **, kvm_getenvv2, struct __sanitizer_kvm *kd, void *kp, int nchr) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getenvv2, kd, kp, nchr);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  if (kp)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kp, struct_kinfo_proc2_sz);
+  return REAL(kvm_getenvv2)(kd, kp, nchr);
+}
+
+INTERCEPTOR(char *, kvm_geterr, struct __sanitizer_kvm *kd) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_geterr, kd);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_geterr)(kd);
+}
+
+INTERCEPTOR(int, kvm_getloadavg, struct __sanitizer_kvm *kd, double loadavg[], int nelem) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_getloadavg, kd, loadavg, nelem);
+  if (kd)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return REAL(kvm_getloadavg)(kd, loadavg, nelem);
+}
+
+INTERCEPTOR(char *, kvm_getfiles, struct __sanitizer_kvm *kd, int op, int arg, int *cnt) {
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
+INTERCEPTOR(void *, kvm_getlwps, struct __sanitizer_kvm *kd, int pid, unsigned long paddr, uptr esize, int *cnt) {
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
+INTERCEPTOR(void *, kvm_getproc2, struct __sanitizer_kvm *kd, int op, int arg, uptr esize, int *cnt) {
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
+INTERCEPTOR(void *, kvm_getprocs, struct __sanitizer_kvm *kd, int op, int arg, int *cnt) {
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
+INTERCEPTOR(struct __sanitizer_kvm *, kvm_open, char *uf, char *mf, char *sf, int flag, char *program) {
+  void *ctx;
+  struct __sanitizer_kvm *kd;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_open, uf, mf, sf, flag, program);
+  if (uf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, uf, REAL(strlen)(uf) + 1);
+  if (mf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, mf, REAL(strlen)(mf) + 1);
+  if (sf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sf, REAL(strlen)(sf) + 1);
+  kd = REAL(kvm_open)(uf, mf, sf, flag, program);
+  if (kd)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return kd;
+}
+
+INTERCEPTOR(struct __sanitizer_kvm *, kvm_openfiles, char *uf, char *mf, char *sf, int flag, char *program) {
+  void *ctx;
+  struct __sanitizer_kvm *kd;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_openfiles, uf, mf, sf, flag, program);
+  if (uf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, uf, REAL(strlen)(uf) + 1);
+  if (mf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, mf, REAL(strlen)(mf) + 1);
+  if (sf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, sf, REAL(strlen)(sf) + 1);
+  kd = REAL(kvm_openfiles)(uf, mf, sf, flag, program);
+  if (kd)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, kd, sizeof(struct __sanitizer_kvm));
+  return kd;
+}
+
+INTERCEPTOR(uptr, kvm_read, struct __sanitizer_kvm *kd, unsigned long kva, void *buf, uptr len) {
+  void *ctx;
+  uptr res;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_read, kd, kva, buf, len);
+  res = REAL(kvm_read)(kd, kva, buf, len);
+  if (res)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, res);
+  return res;
+}
+
+INTERCEPTOR(uptr, kvm_uread, struct __sanitizer_kvm *kd, unsigned long uva, void *buf, uptr len) {
+  void *ctx;
+  uptr res;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_uread, kd, uva, buf, len);
+  res = REAL(kvm_uread)(kd, uva, buf, len);
+  if (res)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, res);
+  return res;
+}
+
+INTERCEPTOR(uptr, kvm_write, struct __sanitizer_kvm *kd, unsigned long kva, void *buf, uptr len) {
+  void *ctx;
+  uptr res;
+  COMMON_INTERCEPTOR_ENTER(ctx, kvm_write, kd, kva, buf, len);
+  res = REAL(kvm_uread)(kd, kva, buf, len);
+  if (res)
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
+  COMMON_INTERCEPT_FUNCTION(kvm_write)
+#else
+#define INIT_KVM
+#endif
+
+#if SANITIZER_INTERCEPT_DEVNAME
+INTERCEPTOR(char *, devname, u64 dev, u32 type) {
+  void *ctx;
+  char *name;
+  COMMON_INTERCEPTOR_ENTER(ctx, devname, dev, type);
+  name = REAL(devname)(dev, type);
+  if (name)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, name, REAL(strlen)(name) + 1);
+  return name;
+}
+
+INTERCEPTOR(int, devname_r, u64 dev, u32 type, char *path, uptr len) {
+  void *ctx;
+  int res;
+  COMMON_INTERCEPTOR_ENTER(ctx, devname_r, dev, type, path, len);
+  res = REAL(devname_r)(dev, type, path, len);
+  if (!res)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, path, REAL(strlen)(path) + 1);
+  return res;
+}
+
+#define INIT_DEVNAME \
+  COMMON_INTERCEPT_FUNCTION(devname); \
+  COMMON_INTERCEPT_FUNCTION(devname_r)
+#else
+#define INIT_DEVNAME
+#endif
+
 static void InitializeCommonInterceptors() {
   static u64 metadata_mem[sizeof(MetadataHashMap) / sizeof(u64) + 1];
   interceptor_metadata_map = new((void *)&metadata_mem) MetadataHashMap();
@@ -6663,6 +6963,8 @@ static void InitializeCommonInterceptors
   INIT_GETLOADAVG;
   INIT_WCSLEN;
   INIT_WCSCAT;
+  INIT_KVM;
+  INIT_DEVNAME;
 
 #if SANITIZER_NETBSD
   COMMON_INTERCEPT_FUNCTION(__libc_mutex_lock);
