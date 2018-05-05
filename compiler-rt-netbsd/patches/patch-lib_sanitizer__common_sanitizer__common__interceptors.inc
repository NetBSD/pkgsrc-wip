$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2018-04-25 21:13:40.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -77,6 +77,11 @@
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
@@ -7161,6 +7166,625 @@ INTERCEPTOR(struct __sanitizer_netent *,
 #define INIT_NETENT
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
@@ -7402,6 +8026,11 @@ static void InitializeCommonInterceptors
   INIT_TTYENT;
   INIT_PROTOENT;
   INIT_NETENT;
+  INIT_KVM;
+  INIT_SYSCTL;
+  INIT_ATOF;
+  INIT_FTS;
+  INIT_REGEX;
 
 #if SANITIZER_NETBSD
   COMMON_INTERCEPT_FUNCTION(__libc_mutex_lock);
