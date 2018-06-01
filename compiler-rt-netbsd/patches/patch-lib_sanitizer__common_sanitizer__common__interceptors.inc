$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2018-06-01 09:36:54.000000000 +0000
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
@@ -7190,6 +7195,303 @@ INTERCEPTOR(struct __sanitizer_netent *,
 #define INIT_NETENT
 #endif
 
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
@@ -7436,6 +7738,10 @@ static void InitializeCommonInterceptors
   INIT_TTYENT;
   INIT_PROTOENT;
   INIT_NETENT;
+  INIT_SYSCTL;
+  INIT_ATOF;
+  INIT_FTS;
+  INIT_REGEX;
 
   INIT___PRINTF_CHK;
 }
