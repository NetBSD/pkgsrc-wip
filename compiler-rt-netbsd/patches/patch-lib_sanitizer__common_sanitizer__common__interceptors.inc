$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2018-08-31 08:13:42.000000000 +0000
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
@@ -111,6 +116,8 @@
 #define times __times13
 #define wait3 __wait350
 #define wait4 __wait450
+#define getmntinfo __getmntinfo13
+#define mount __mount50
 extern const unsigned short *_ctype_tab_;
 extern const short *_toupper_tab_;
 extern const short *_tolower_tab_;
@@ -3060,17 +3067,28 @@ INTERCEPTOR(int, sendmmsg, int fd, struc
 #endif
 
 #if SANITIZER_INTERCEPT_GETPEERNAME
-INTERCEPTOR(int, getpeername, int sockfd, void *addr, unsigned *addrlen) {
+INTERCEPTOR(int, getpeername, int sockfd, void *addr,
+  __sanitizer_socklen_t *addrlen) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, getpeername, sockfd, addr, addrlen);
-  unsigned addr_sz;
-  if (addrlen) addr_sz = *addrlen;
-  // FIXME: under ASan the call below may write to freed memory and corrupt
-  // its metadata. See
-  // https://github.com/google/sanitizers/issues/321.
-  int res = REAL(getpeername)(sockfd, addr, addrlen);
-  if (!res && addr && addrlen)
-    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, addr, Min(addr_sz, *addrlen));
+  __sanitizer_socklen_t taddrlen;
+  if (addrlen)
+    taddrlen = *addrlen;
+  else
+    taddrlen = 0;
+  __sanitizer_sockaddr_storage taddr;
+  int res = REAL(getpeername)(sockfd, addr ? &taddr : 0,
+                              addrlen ? &taddrlen : 0);
+  if (!res) {
+    if (addr && addrlen)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, addr, taddrlen);
+    if (addrlen)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, addrlen, sizeof(*addrlen));
+  }
+  if (addr && addrlen)
+    memcpy(addr, &taddr, taddrlen);
+  if (addrlen)
+    *addrlen = taddrlen;
   return res;
 }
 #define INIT_GETPEERNAME COMMON_INTERCEPT_FUNCTION(getpeername);
@@ -4240,7 +4258,7 @@ INTERCEPTOR(int, fstatfs64, int fd, void
 #endif
 
 #if SANITIZER_INTERCEPT_STATVFS
-INTERCEPTOR(int, statvfs, char *path, void *buf) {
+INTERCEPTOR(int, statvfs, const char *path, void *buf) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, statvfs, path, buf);
   if (path) COMMON_INTERCEPTOR_READ_RANGE(ctx, path, REAL(strlen)(path) + 1);
@@ -7235,6 +7253,1606 @@ INTERCEPTOR(struct __sanitizer_netent *,
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
+            unsigned int *namelenp, char *cname, SIZE_T *csz, void **rnode,
+            int v) {
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
+#define INIT_SYSCTL                                                            \
+  COMMON_INTERCEPT_FUNCTION(sysctl);                                           \
+  COMMON_INTERCEPT_FUNCTION(sysctlbyname);                                     \
+  COMMON_INTERCEPT_FUNCTION(sysctlgetmibinfo);                                 \
+  COMMON_INTERCEPT_FUNCTION(sysctlnametomib);                                  \
+  COMMON_INTERCEPT_FUNCTION(asysctl);                                          \
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
+INTERCEPTOR(void *, fts_open, char *const *path_argv, int options,
+            int (*compar)(void **, void **)) {
+  void *ctx;
+  void *fts;
+  COMMON_INTERCEPTOR_ENTER(ctx, fts_open, path_argv, options, compar);
+  if (path_argv) {
+    char *const *pa = path_argv;
+    while (*pa) {
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, pa, sizeof(char **));
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, *pa, REAL(strlen)(*pa) + 1);
+      pa++;
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
+#define INIT_FTS                                                               \
+  COMMON_INTERCEPT_FUNCTION(fts_open);                                         \
+  COMMON_INTERCEPT_FUNCTION(fts_read);                                         \
+  COMMON_INTERCEPT_FUNCTION(fts_children);                                     \
+  COMMON_INTERCEPT_FUNCTION(fts_set);                                          \
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
+#define INIT_REGEX                                                             \
+  COMMON_INTERCEPT_FUNCTION(regcomp);                                          \
+  COMMON_INTERCEPT_FUNCTION(regexec);                                          \
+  COMMON_INTERCEPT_FUNCTION(regerror);                                         \
+  COMMON_INTERCEPT_FUNCTION(regfree);                                          \
+  COMMON_INTERCEPT_FUNCTION(regnsub);                                          \
+  COMMON_INTERCEPT_FUNCTION(regasub);
+#else
+#define INIT_REGEX
+#endif
+
+#if SANITIZER_INTERCEPT_STRTONUM
+INTERCEPTOR(long long, strtonum, const char *nptr, long long minval,
+            long long maxval, const char **errstr) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strtonum, nptr, minval, maxval, errstr);
+
+  if (nptr)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, nptr, REAL(strlen)(nptr) + 1);
+  long long ret = REAL(strtonum)(nptr, minval, maxval, errstr);
+  if (errstr) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, errstr, sizeof(const char *));
+    if (*errstr)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *errstr, REAL(strlen)(*errstr) + 1);
+  }
+  return ret;
+}
+
+INTERCEPTOR(INTMAX_T, strtoi, const char *nptr, char **endptr, int base,
+            INTMAX_T low, INTMAX_T high, int *rstatus) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strtoi, nptr, endptr, base, low, high, rstatus);
+
+  if (nptr)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, nptr, REAL(strlen)(nptr) + 1);
+  INTMAX_T ret = REAL(strtoi)(nptr, endptr, base, low, high, rstatus);
+  if (endptr) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, endptr, sizeof(char *));
+    if (*endptr)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *endptr, REAL(strlen)(*endptr) + 1);
+  }
+  if (rstatus)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, rstatus, sizeof(int));
+  return ret;
+}
+
+INTERCEPTOR(UINTMAX_T, strtou, const char *nptr, char **endptr, int base,
+            UINTMAX_T low, UINTMAX_T high, int *rstatus) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strtou, nptr, endptr, base, low, high, rstatus);
+
+  if (nptr)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, nptr, REAL(strlen)(nptr) + 1);
+  UINTMAX_T ret = REAL(strtou)(nptr, endptr, base, low, high, rstatus);
+  if (endptr) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, endptr, sizeof(char *));
+    if (*endptr)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *endptr, REAL(strlen)(*endptr) + 1);
+  }
+  if (rstatus)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, rstatus, sizeof(int));
+  return ret;
+}
+
+#define INIT_STRTONUM                                                          \
+  COMMON_INTERCEPT_FUNCTION(strtonum);                                         \
+  COMMON_INTERCEPT_FUNCTION(strtoi);                                           \
+  COMMON_INTERCEPT_FUNCTION(strtou)
+
+#else
+#define INIT_STRTONUM
+#endif
+
+#if SANITIZER_INTERCEPT_VIS
+INTERCEPTOR(char *, vis, char *dst, int c, int flag, int nextc) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, vis, dst, c, flag, nextc);
+
+  char *end = REAL(vis)(dst, c, flag, nextc);
+  // dst is NULL terminated and end points to the NULL char
+  if (dst && end)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst, end - dst + 1);
+  return end;
+}
+
+INTERCEPTOR(char *, nvis, char *dst, SIZE_T dlen, int c, int flag, int nextc) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, nvis, dst, dlen, c, flag, nextc);
+
+  char *end = REAL(nvis)(dst, dlen, c, flag, nextc);
+  // nvis cannot make sure the dst is NULL terminated
+  if (dst && end)
+    COMMON_INTERCEPTOR_WRITE_RANGE(
+        ctx, dst, (SIZE_T)(end - dst + 1) < dlen ? end - dst + 1 : dlen);
+  return end;
+}
+
+INTERCEPTOR(int, strvis, char *dst, const char *src, int flag) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strvis, dst, src, flag);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, REAL(strlen)(src) + 1);
+  int len = REAL(strvis)(dst, src, flag);
+  if (dst)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst, len + 1);
+  return len;
+}
+
+INTERCEPTOR(int, stravis, char **dst, const char *src, int flag) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, stravis, dst, src, flag);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, REAL(strlen)(src) + 1);
+  int len = REAL(stravis)(dst, src, flag);
+  if (dst) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst, sizeof(char *));
+    if (*dst)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *dst, len + 1);
+  }
+  return len;
+}
+
+INTERCEPTOR(int, strnvis, char *dst, SIZE_T dlen, const char *src, int flag) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strnvis, dst, dlen, src, flag);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, REAL(strlen)(src) + 1);
+  int len = REAL(strnvis)(dst, dlen, src, flag);
+  // The interface will be valid even if there is no space for NULL char
+  if (dst && len >= 0)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst,
+                                   (SIZE_T)len + 1 < dlen ? len + 1 : dlen);
+  return len;
+}
+
+INTERCEPTOR(int, strvisx, char *dst, const char *src, SIZE_T len, int flag) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strvisx, dst, src, len, flag);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, len);
+  int ret = REAL(strvisx)(dst, src, len, flag);
+  if (dst)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst, ret + 1);
+  return ret;
+}
+
+INTERCEPTOR(int, strnvisx, char *dst, SIZE_T dlen, const char *src, SIZE_T len,
+            int flag) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strnvisx, dst, dlen, src, len, flag);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, len);
+  int ret = REAL(strnvisx)(dst, dlen, src, len, flag);
+  if (dst && ret >= 0)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst,
+                                   (SIZE_T)ret + 1 < dlen ? ret + 1 : dlen);
+  return ret;
+}
+
+INTERCEPTOR(int, strenvisx, char *dst, SIZE_T dlen, const char *src, SIZE_T len,
+            int flag, int *cerr_ptr) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strenvisx, dst, dlen, src, len, flag, cerr_ptr);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, len);
+  // FIXME: only need to be checked when "flag | VIS_NOLOCALE" doesn't hold
+  // according to the implementation
+  if (cerr_ptr)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, cerr_ptr, sizeof(int));
+  int ret = REAL(strenvisx)(dst, dlen, src, len, flag, cerr_ptr);
+  if (dst && ret >= 0)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst,
+                                   (SIZE_T)ret + 1 < dlen ? ret + 1 : dlen);
+  if (cerr_ptr)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, cerr_ptr, sizeof(int));
+  return ret;
+}
+
+INTERCEPTOR(char *, svis, char *dst, int c, int flag, int nextc,
+            const char *extra) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, svis, dst, c, flag, nextc, extra);
+  if (extra)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, extra, REAL(strlen)(extra) + 1);
+  char *end = REAL(svis)(dst, c, flag, nextc, extra);
+  if (dst && end)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst, end - dst + 1);
+  return end;
+}
+
+INTERCEPTOR(char *, snvis, char *dst, SIZE_T dlen, int c, int flag, int nextc,
+            const char *extra) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, snvis, dst, dlen, c, flag, nextc, extra);
+  if (extra)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, extra, REAL(strlen)(extra) + 1);
+  char *end = REAL(snvis)(dst, dlen, c, flag, nextc, extra);
+  if (dst && end)
+    COMMON_INTERCEPTOR_WRITE_RANGE(
+        ctx, dst, (SIZE_T)(end - dst + 1) < dlen ? end - dst + 1 : dlen);
+  return end;
+}
+
+INTERCEPTOR(int, strsvis, char *dst, const char *src, int flag,
+            const char *extra) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strsvis, dst, src, flag, extra);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, REAL(strlen)(src) + 1);
+  if (extra)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, extra, REAL(strlen)(extra) + 1);
+  int len = REAL(strsvis)(dst, src, flag, extra);
+  if (dst)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst, len + 1);
+  return len;
+}
+
+INTERCEPTOR(int, strsnvis, char *dst, SIZE_T dlen, const char *src, int flag,
+            const char *extra) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strsnvis, dst, dlen, src, flag, extra);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, REAL(strlen)(src) + 1);
+  if (extra)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, extra, REAL(strlen)(extra) + 1);
+  int len = REAL(strsnvis)(dst, dlen, src, flag, extra);
+  // The interface will be valid even if there is no space for NULL char
+  if (dst && len >= 0)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst,
+                                   (SIZE_T)len + 1 < dlen ? len + 1 : dlen);
+  return len;
+}
+
+INTERCEPTOR(int, strsvisx, char *dst, const char *src, SIZE_T len, int flag,
+            const char *extra) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strsvisx, dst, src, len, flag, extra);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, len);
+  if (extra)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, extra, REAL(strlen)(extra) + 1);
+  int ret = REAL(strsvisx)(dst, src, len, flag, extra);
+  if (dst)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst, ret + 1);
+  return ret;
+}
+
+INTERCEPTOR(int, strsnvisx, char *dst, SIZE_T dlen, const char *src, SIZE_T len,
+            int flag, const char *extra) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strsnvisx, dst, dlen, src, len, flag, extra);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, len);
+  if (extra)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, extra, REAL(strlen)(extra) + 1);
+  int ret = REAL(strsnvisx)(dst, dlen, src, len, flag, extra);
+  if (dst && ret >= 0)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst,
+                                   (SIZE_T)ret + 1 < dlen ? ret + 1 : dlen);
+  return ret;
+}
+
+INTERCEPTOR(int, strsenvisx, char *dst, SIZE_T dlen, const char *src,
+            SIZE_T len, int flag, const char *extra, int *cerr_ptr) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strsenvisx, dst, dlen, src, len, flag, extra,
+                           cerr_ptr);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, len);
+  if (extra)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, extra, REAL(strlen)(extra) + 1);
+  // FIXME: only need to be checked when "flag | VIS_NOLOCALE" doesn't hold
+  // according to the implementation
+  if (cerr_ptr)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, cerr_ptr, sizeof(int));
+  int ret = REAL(strsenvisx)(dst, dlen, src, len, flag, extra, cerr_ptr);
+  if (dst && ret >= 0)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst,
+                                   (SIZE_T)ret + 1 < dlen ? ret + 1 : dlen);
+  if (cerr_ptr)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, cerr_ptr, sizeof(int));
+  return ret;
+}
+
+INTERCEPTOR(int, unvis, char *cp, int c, int *astate, int flag) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, unvis, cp, c, astate, flag);
+  if (astate)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, astate, sizeof(*astate));
+  int ret = REAL(unvis)(cp, c, astate, flag);
+  if (ret == unvis_valid || ret == unvis_validpush) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, cp, sizeof(*cp));
+  }
+  return ret;
+}
+
+INTERCEPTOR(int, strunvis, char *dst, const char *src) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strunvis, dst, src);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, REAL(strlen)(src) + 1);
+  int ret = REAL(strunvis)(dst, src);
+  if (ret != -1)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst, ret + 1);
+  return ret;
+}
+
+INTERCEPTOR(int, strnunvis, char *dst, SIZE_T dlen, const char *src) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strnunvis, dst, dlen, src);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, REAL(strlen)(src) + 1);
+  int ret = REAL(strnunvis)(dst, dlen, src);
+  if (ret != -1)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst,
+                                   (SIZE_T)ret + 1 < dlen ? ret + 1 : dlen);
+  return ret;
+}
+
+INTERCEPTOR(int, strunvisx, char *dst, const char *src, int flag) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strunvisx, dst, src, flag);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, REAL(strlen)(src) + 1);
+  int ret = REAL(strunvisx)(dst, src, flag);
+  if (ret != -1)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst, ret + 1);
+  return ret;
+}
+
+INTERCEPTOR(int, strnunvisx, char *dst, SIZE_T dlen, const char *src,
+            int flag) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, strnunvisx, dst, dlen, src, flag);
+  if (src)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, src, REAL(strlen)(src) + 1);
+  int ret = REAL(strnunvisx)(dst, dlen, src, flag);
+  if (ret != -1)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, dst,
+                                   (SIZE_T)ret + 1 < dlen ? ret + 1 : dlen);
+  return ret;
+}
+
+#define INIT_VIS                                                               \
+  COMMON_INTERCEPT_FUNCTION(vis);                                              \
+  COMMON_INTERCEPT_FUNCTION(nvis);                                             \
+  COMMON_INTERCEPT_FUNCTION(strvis);                                           \
+  COMMON_INTERCEPT_FUNCTION(stravis);                                          \
+  COMMON_INTERCEPT_FUNCTION(strnvis);                                          \
+  COMMON_INTERCEPT_FUNCTION(strvisx);                                          \
+  COMMON_INTERCEPT_FUNCTION(strnvisx);                                         \
+  COMMON_INTERCEPT_FUNCTION(strenvisx);                                        \
+  COMMON_INTERCEPT_FUNCTION(svis);                                             \
+  COMMON_INTERCEPT_FUNCTION(snvis);                                            \
+  COMMON_INTERCEPT_FUNCTION(strsvis);                                          \
+  COMMON_INTERCEPT_FUNCTION(strsnvis);                                         \
+  COMMON_INTERCEPT_FUNCTION(strsvisx);                                         \
+  COMMON_INTERCEPT_FUNCTION(strsnvisx);                                        \
+  COMMON_INTERCEPT_FUNCTION(strsenvisx);                                       \
+  COMMON_INTERCEPT_FUNCTION(unvis);                                            \
+  COMMON_INTERCEPT_FUNCTION(strunvis);                                         \
+  COMMON_INTERCEPT_FUNCTION(strnunvis);                                        \
+  COMMON_INTERCEPT_FUNCTION(strunvisx);                                        \
+  COMMON_INTERCEPT_FUNCTION(strnunvisx)
+#else
+#define INIT_VIS
+#endif
+
+#if SANITIZER_INTERCEPT_GETMNTINFO
+INTERCEPTOR(int, getmntinfo, void **mntbufp, int flags) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, getmntinfo, mntbufp, flags);
+  int cnt = REAL(getmntinfo)(mntbufp, flags);
+  if (cnt > 0 && mntbufp) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, mntbufp, sizeof(void *));
+    if (*mntbufp)
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *mntbufp, cnt * struct_statvfs_sz);
+  }
+  return cnt;
+}
+
+#define INIT_GETMNTINFO COMMON_INTERCEPT_FUNCTION(getmntinfo)
+#else
+#define INIT_GETMNTINFO
+#endif
+
+#if SANITIZER_INTERCEPT_SHA1
+
+INTERCEPTOR(void, SHA1Init, void *context) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, SHA1Init, context);
+  REAL(SHA1Init)(context);
+  COMMON_INTERCEPTOR_WRITE_RANGE(ctx, context, SHA1_CTX_sz);
+}
+
+INTERCEPTOR(void, SHA1Update, void *context, const u8 *data, unsigned len) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, SHA1Update, context, data, len);
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len);
+  if (context)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, context, SHA1_CTX_sz);
+  REAL(SHA1Update)(context, data, len);
+}
+
+INTERCEPTOR(void, SHA1Final, u8 digest[20], void *context) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, SHA1Final, digest, context);
+  REAL(SHA1Final)(digest, context);
+  if (digest)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, digest, sizeof(u8) * 20);
+}
+
+INTERCEPTOR(void, SHA1Transform, u32 state[5], u8 buffer[64]) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, SHA1Transform, state, buffer);
+  if (state)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, state, sizeof(u32) * 5);
+  if (buffer)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, buffer, sizeof(u8) * 64);
+  REAL(SHA1Transform)(state, buffer);
+}
+
+INTERCEPTOR(char *, SHA1End, void *context, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, SHA1End, context, buf);
+  if (context)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, context, SHA1_CTX_sz);
+  char *ret = REAL(SHA1End)(context, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, SHA1_return_length);
+  return ret;
+}
+
+INTERCEPTOR(char *, SHA1File, char *filename, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, SHA1File, filename, buf);
+  if (filename)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, filename, REAL(strlen)(filename) + 1);
+  char *ret = REAL(SHA1File)(filename, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, SHA1_return_length);
+  return ret;
+}
+
+INTERCEPTOR(char *, SHA1Data, u8 *data, SIZE_T len, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, SHA1Data, data, len, buf);
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len);
+  char *ret = REAL(SHA1Data)(data, len, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, SHA1_return_length);
+  return ret;
+}
+
+#define INIT_SHA1                                                              \
+  COMMON_INTERCEPT_FUNCTION(SHA1Init);                                         \
+  COMMON_INTERCEPT_FUNCTION(SHA1Update);                                       \
+  COMMON_INTERCEPT_FUNCTION(SHA1Final);                                        \
+  COMMON_INTERCEPT_FUNCTION(SHA1Transform);                                    \
+  COMMON_INTERCEPT_FUNCTION(SHA1End);                                          \
+  COMMON_INTERCEPT_FUNCTION(SHA1File);                                         \
+  COMMON_INTERCEPT_FUNCTION(SHA1Data)
+#else
+#define INIT_SHA1
+#endif
+
+#if SANITIZER_INTERCEPT_MD2
+
+INTERCEPTOR(void, MD2Init, void *context) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD2Init, context);
+  REAL(MD2Init)(context);
+  COMMON_INTERCEPTOR_WRITE_RANGE(ctx, context, MD2_CTX_sz);
+}
+
+INTERCEPTOR(void, MD2Update, void *context, const unsigned char *data,
+            unsigned int len) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD2Update, context, data, len);
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len);
+  if (context)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, context, MD2_CTX_sz);
+  REAL(MD2Update)(context, data, len);
+}
+
+INTERCEPTOR(void, MD2Final, unsigned char digest[16], void *context) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD2Final, digest, context);
+  REAL(MD2Final)(digest, context);
+  if (digest)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, digest, sizeof(unsigned char) * 16);
+}
+
+INTERCEPTOR(char *, MD2End, void *context, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD2End, context, buf);
+  if (context)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, context, MD2_CTX_sz);
+  char *ret = REAL(MD2End)(context, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, MD2_return_length);
+  return ret;
+}
+
+INTERCEPTOR(char *, MD2File, const char *filename, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD2File, filename, buf);
+  if (filename)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, filename, REAL(strlen)(filename) + 1);
+  char *ret = REAL(MD2File)(filename, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, MD2_return_length);
+  return ret;
+}
+
+INTERCEPTOR(char *, MD2Data, const unsigned char *data, unsigned int len,
+            char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD2Data, data, len, buf);
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len);
+  char *ret = REAL(MD2Data)(data, len, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, MD2_return_length);
+  return ret;
+}
+
+#define INIT_MD2                                                               \
+  COMMON_INTERCEPT_FUNCTION(MD2Init);                                          \
+  COMMON_INTERCEPT_FUNCTION(MD2Update);                                        \
+  COMMON_INTERCEPT_FUNCTION(MD2Final);                                         \
+  COMMON_INTERCEPT_FUNCTION(MD2End);                                           \
+  COMMON_INTERCEPT_FUNCTION(MD2File);                                          \
+  COMMON_INTERCEPT_FUNCTION(MD2Data)
+#else
+#define INIT_MD2
+#endif
+
+#if SANITIZER_INTERCEPT_MD4
+
+INTERCEPTOR(void, MD4Init, void *context) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD4Init, context);
+  REAL(MD4Init)(context);
+  COMMON_INTERCEPTOR_WRITE_RANGE(ctx, context, MD4_CTX_sz);
+}
+
+INTERCEPTOR(void, MD4Update, void *context, const unsigned char *data,
+            unsigned int len) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD4Update, context, data, len);
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len);
+  if (context)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, context, MD4_CTX_sz);
+  REAL(MD4Update)(context, data, len);
+}
+
+INTERCEPTOR(void, MD4Final, unsigned char digest[16], void *context) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD4Final, digest, context);
+  REAL(MD4Final)(digest, context);
+  if (digest)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, digest, sizeof(unsigned char) * 16);
+}
+
+INTERCEPTOR(char *, MD4End, void *context, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD4End, context, buf);
+  if (context)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, context, MD4_CTX_sz);
+  char *ret = REAL(MD4End)(context, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, MD4_return_length);
+  return ret;
+}
+
+INTERCEPTOR(char *, MD4File, const char *filename, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD4File, filename, buf);
+  if (filename)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, filename, REAL(strlen)(filename) + 1);
+  char *ret = REAL(MD4File)(filename, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, MD4_return_length);
+  return ret;
+}
+
+INTERCEPTOR(char *, MD4Data, const unsigned char *data, unsigned int len,
+            char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD4Data, data, len, buf);
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len);
+  char *ret = REAL(MD4Data)(data, len, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, MD4_return_length);
+  return ret;
+}
+
+#define INIT_MD4                                                               \
+  COMMON_INTERCEPT_FUNCTION(MD4Init);                                          \
+  COMMON_INTERCEPT_FUNCTION(MD4Update);                                        \
+  COMMON_INTERCEPT_FUNCTION(MD4Final);                                         \
+  COMMON_INTERCEPT_FUNCTION(MD4End);                                           \
+  COMMON_INTERCEPT_FUNCTION(MD4File);                                          \
+  COMMON_INTERCEPT_FUNCTION(MD4Data)
+#else
+#define INIT_MD4
+#endif
+
+#if SANITIZER_INTERCEPT_MD5
+
+INTERCEPTOR(void, MD5Init, void *context) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD5Init, context);
+  REAL(MD5Init)(context);
+  COMMON_INTERCEPTOR_WRITE_RANGE(ctx, context, MD5_CTX_sz);
+}
+
+INTERCEPTOR(void, MD5Update, void *context, const unsigned char *data,
+            unsigned int len) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD5Update, context, data, len);
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len);
+  if (context)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, context, MD5_CTX_sz);
+  REAL(MD5Update)(context, data, len);
+}
+
+INTERCEPTOR(void, MD5Final, unsigned char digest[16], void *context) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD5Final, digest, context);
+  REAL(MD5Final)(digest, context);
+  if (digest)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, digest, sizeof(unsigned char) * 16);
+}
+
+INTERCEPTOR(char *, MD5End, void *context, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD5End, context, buf);
+  if (context)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, context, MD5_CTX_sz);
+  char *ret = REAL(MD5End)(context, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, MD5_return_length);
+  return ret;
+}
+
+INTERCEPTOR(char *, MD5File, const char *filename, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD5File, filename, buf);
+  if (filename)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, filename, REAL(strlen)(filename) + 1);
+  char *ret = REAL(MD5File)(filename, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, MD5_return_length);
+  return ret;
+}
+
+INTERCEPTOR(char *, MD5Data, const unsigned char *data, unsigned int len,
+            char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, MD5Data, data, len, buf);
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len);
+  char *ret = REAL(MD5Data)(data, len, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, MD5_return_length);
+  return ret;
+}
+
+#define INIT_MD5                                                               \
+  COMMON_INTERCEPT_FUNCTION(MD5Init);                                          \
+  COMMON_INTERCEPT_FUNCTION(MD5Update);                                        \
+  COMMON_INTERCEPT_FUNCTION(MD5Final);                                         \
+  COMMON_INTERCEPT_FUNCTION(MD5End);                                           \
+  COMMON_INTERCEPT_FUNCTION(MD5File);                                          \
+  COMMON_INTERCEPT_FUNCTION(MD5Data)
+#else
+#define INIT_MD5
+#endif
+
+#if SANITIZER_INTERCEPT_GETVFSSTAT
+INTERCEPTOR(int, getvfsstat, void *buf, SIZE_T bufsize, int flags) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, getvfsstat, buf, bufsize, flags);
+  int ret = REAL(getvfsstat)(buf, bufsize, flags);
+  if (buf && ret > 0)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, ret * struct_statvfs_sz);
+  return ret;
+}
+#define INIT_GETVFSSTAT COMMON_INTERCEPT_FUNCTION(getvfsstat)
+#else
+#define INIT_GETVFSSTAT
+#endif
+
+#if SANITIZER_INTERCEPT_NL_LANGINFO
+INTERCEPTOR(char *, nl_langinfo, long item) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, nl_langinfo, item);
+  char *ret = REAL(nl_langinfo)(item);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, REAL(strlen)(ret) + 1);
+  return ret;
+}
+#define INIT_NL_LANGINFO COMMON_INTERCEPT_FUNCTION(nl_langinfo)
+#else
+#define INIT_NL_LANGINFO
+#endif
+
+#if SANITIZER_INTERCEPT_FPARSELN
+INTERCEPTOR(char *, fparseln, __sanitizer_FILE *stream, SIZE_T *len,
+            SIZE_T *lineno, const char delim[3], int flags) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, fparseln, stream, len, lineno, delim, flags);
+  if (len)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, len, sizeof(*len));
+  if (lineno)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, lineno, sizeof(*lineno));
+  if (delim)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, delim, sizeof(delim[0]) * 3);
+  char *ret = REAL(fparseln)(stream, len, lineno, delim, flags);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, REAL(strlen)(ret) + 1);
+  return ret;
+}
+#define INIT_FPARSELN COMMON_INTERCEPT_FUNCTION(fparseln)
+#else
+#define INIT_FPARSELN
+#endif
+
+#if SANITIZER_INTERCEPT_MODCTL
+INTERCEPTOR(int, modctl, int operation, void *argp) {
+  void *ctx;
+  int ret;
+  COMMON_INTERCEPTOR_ENTER(ctx, modctl, operation, argp);
+
+  if (operation == modctl_load) {
+    if (argp) {
+      __sanitizer_modctl_load_t *ml = (__sanitizer_modctl_load_t *)argp;
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, ml, sizeof(*ml));
+      if (ml->ml_filename)
+        COMMON_INTERCEPTOR_READ_RANGE(ctx, ml->ml_filename,
+                                      REAL(strlen)(ml->ml_filename) + 1);
+      if (ml->ml_props)
+        COMMON_INTERCEPTOR_READ_RANGE(ctx, ml->ml_props, ml->ml_propslen);
+    }
+    ret = REAL(modctl)(operation, argp);
+  } else if (operation == modctl_unload) {
+    if (argp) {
+      const char *name = (const char *)argp;
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, name, REAL(strlen)(name) + 1);
+    }
+    ret = REAL(modctl)(operation, argp);
+  } else if (operation == modctl_stat) {
+    uptr iov_len;
+    struct __sanitizer_iovec *iov = (struct __sanitizer_iovec *)argp;
+    if (iov) {
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, iov, sizeof(*iov));
+      iov_len = iov->iov_len;
+    }
+    ret = REAL(modctl)(operation, argp);
+    if (iov)
+      COMMON_INTERCEPTOR_WRITE_RANGE(
+          ctx, iov->iov_base, iov_len < iov->iov_len ? iov_len : iov->iov_len);
+  } else if (operation == modctl_exists)
+    ret = REAL(modctl)(operation, argp);
+  else
+    ret = REAL(modctl)(operation, argp);
+
+  return ret;
+}
+#define INIT_MODCTL COMMON_INTERCEPT_FUNCTION(modctl)
+#else
+#define INIT_MODCTL
+#endif
+
+#if SANITIZER_INTERCEPT_STATVFS1
+INTERCEPTOR(int, statvfs1, const char *path, void *buf, int flags) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, statvfs1, path, buf, flags);
+  if (path) COMMON_INTERCEPTOR_READ_RANGE(ctx, path, REAL(strlen)(path) + 1);
+
+  int res = REAL(statvfs1)(path, buf, flags);
+  if (!res) COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, struct_statvfs_sz);
+  return res;
+}
+INTERCEPTOR(int, fstatvfs1, int fd, void *buf, int flags) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, fstatvfs1, fd, buf, flags);
+
+  int res = REAL(fstatvfs1)(fd, buf, flags);
+  if (!res) COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, struct_statvfs_sz);
+  return res;
+}
+#define INIT_STATVFS1                  \
+  COMMON_INTERCEPT_FUNCTION(statvfs1);  \
+  COMMON_INTERCEPT_FUNCTION(fstatvfs1);
+#else
+#define INIT_STATVFS1
+#endif
+
+#if SANITIZER_INTERCEPT_NETBSD_MOUNT
+
+INTERCEPTOR(int, mount, const char *type, const char *dir, int flags,
+            void *data, SIZE_T data_len) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, mount, type, dir, flags, data, data_len);
+  if (type)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, type, REAL(strlen)(type) + 1);
+  if (dir)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, dir, REAL(strlen)(dir) + 1);
+
+  // FIXME The data is a type-dependant structure which may contain
+  // pointers inside. It is necessary to check them separately. But
+  // the number of types is too large, temporarily relax this check
+  // here.
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, data_len);
+
+  return REAL(mount)(type, dir, flags, data, data_len);
+}
+
+INTERCEPTOR(int, unmount, const char *dir, int flags) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, unmount, dir, flags);
+  if (dir)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, dir, strlen(dir) + 1);
+  return REAL(unmount)(dir, flags);
+}
+
+#define INIT_NETBSD_MOUNT \
+  COMMON_INTERCEPT_FUNCTION(mount); \
+  COMMON_INTERCEPT_FUNCTION(unmount)
+#else
+#define INIT_NETBSD_MOUNT
+#endif
+
+#if SANITIZER_INTERCEPT_FSEEK
+
+// FIXME The FILE type should be checked.
+// Current challenge is that this type is OS-specific and for some
+// OSs, it is not self-contained, i.e., it contains pointers inside
+// and needs extra inside checking. So, we need to check them
+// separately for different OSs.
+
+INTERCEPTOR(int, fseek, __sanitizer_FILE *stream, long int offset, int whence) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, fseek, stream, offset, whence);
+  return REAL(fseek)(stream, offset, whence);
+}
+
+INTERCEPTOR(int, fseeko, __sanitizer_FILE *stream, OFF_T offset, int whence) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, fseeko, stream, offset, whence);
+  return REAL(fseeko)(stream, offset, whence);
+}
+
+INTERCEPTOR(long int, ftell, __sanitizer_FILE *stream) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, ftell, stream);
+  return REAL(ftell)(stream);
+}
+
+INTERCEPTOR(long int, ftello, __sanitizer_FILE *stream) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, ftello, stream);
+  return REAL(ftello)(stream);
+}
+
+INTERCEPTOR(void, rewind, __sanitizer_FILE *stream) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, rewind, stream);
+  return REAL(rewind)(stream);
+}
+
+INTERCEPTOR(int, fgetpos, __sanitizer_FILE *stream, void *pos) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, fgetpos, stream, pos);
+  int ret = REAL(fgetpos)(stream, pos);
+  if (pos && ret == 0)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, pos, fpos_t_sz);
+  return ret;
+}
+
+INTERCEPTOR(int, fsetpos, __sanitizer_FILE *stream, const void *pos) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, fsetpos, stream, pos);
+  if (pos)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, pos, fpos_t_sz);
+  return REAL(fsetpos)(stream, pos);
+}
+
+#define INIT_FSEEK \
+  COMMON_INTERCEPT_FUNCTION(fseek); \
+  COMMON_INTERCEPT_FUNCTION(fseeko); \
+  COMMON_INTERCEPT_FUNCTION(ftell); \
+  COMMON_INTERCEPT_FUNCTION(ftello); \
+  COMMON_INTERCEPT_FUNCTION(rewind); \
+  COMMON_INTERCEPT_FUNCTION(fgetpos); \
+  COMMON_INTERCEPT_FUNCTION(fsetpos)
+#else
+#define INIT_FSEEK
+#endif
+
+#if SANITIZER_INTERCEPT_CDBR
+static void cdbr_read_range(void *ctx, struct __sanitizer_cdbr *cdbr) {
+  if (cdbr) {
+    // other pointers like hash_base, offset_base and data_base
+    // are calculated from the mmap_base
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, cdbr, sizeof(*cdbr));
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, cdbr->mmap_base, cdbr->mmap_size);
+  }
+}
+
+static void cdbr_write_range(void *ctx, struct __sanitizer_cdbr *cdbr) {
+  if (cdbr) {
+    // other pointers like hash_base, offset_base and data_base
+    // are calculated from the mmap_base
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, cdbr, sizeof(*cdbr));
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, cdbr->mmap_base, cdbr->mmap_size);
+  }
+}
+
+INTERCEPTOR(struct __sanitizer_cdbr *, cdbr_open, const char *path, int flags) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, cdbr_open, path, flags);
+  if (path)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, path, REAL(strlen)(path) + 1);
+  struct __sanitizer_cdbr *ret = REAL(cdbr_open)(path, flags);
+  cdbr_write_range(ctx, ret);
+  return ret;
+}
+
+
+INTERCEPTOR(u32, cdbr_entries, struct __sanitizer_cdbr *cdbr) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, cdbr_entries, cdbr);
+  cdbr_read_range(ctx, cdbr);
+  return REAL(cdbr_entries)(cdbr);
+}
+
+INTERCEPTOR(int, cdbr_get, struct __sanitizer_cdbr *cdbr, u32 index,
+            const void **data, SIZE_T *datalen) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, cdbr_get, cdbr, index, data, datalen);
+  cdbr_read_range(ctx, cdbr);
+  int ret = REAL(cdbr_get)(cdbr, index, data, datalen);
+  if (data && datalen && ret == 0) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, data, sizeof(*data));
+    if (*data) {
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, datalen, sizeof(*datalen));
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *data, *datalen);
+    }
+  }
+  return ret;
+}
+
+INTERCEPTOR(int, cdbr_find, struct __sanitizer_cdbr *cdbr, const void *key,
+            SIZE_T keylen, const void **data, SIZE_T *datalen) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, cdbr_find, cdbr, key, keylen, data, datalen);
+  cdbr_read_range(ctx, cdbr);
+  if (key)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, key, keylen);
+  int ret = REAL(cdbr_find)(cdbr, key, keylen, data, datalen);
+  if (data && datalen && ret == 0) {
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, data, sizeof(*data));
+    if (*data) {
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, datalen, sizeof(*datalen));
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, *data, *datalen);
+    }
+  }
+  return ret;
+}
+
+INTERCEPTOR(void, cdbr_close, struct __sanitizer_cdbr *cdbr) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, cdbr_close, cdbr);
+  cdbr_read_range(ctx, cdbr);
+  REAL(cdbr_close)(cdbr);
+}
+
+#define INIT_CDBR \
+  COMMON_INTERCEPT_FUNCTION(cdbr_open); \
+  COMMON_INTERCEPT_FUNCTION(cdbr_entries); \
+  COMMON_INTERCEPT_FUNCTION(cdbr_get); \
+  COMMON_INTERCEPT_FUNCTION(cdbr_find); \
+  COMMON_INTERCEPT_FUNCTION(cdbr_close)
+#else
+#define INIT_CDBR
+#endif
+
+#if SANITIZER_INTERCEPT_RMD160
+
+INTERCEPTOR(void, RMD160Init, void *context) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, RMD160Init, context);
+  REAL(RMD160Init)(context);
+  COMMON_INTERCEPTOR_WRITE_RANGE(ctx, context, RMD160_CTX_sz);
+}
+
+INTERCEPTOR(void, RMD160Update, void *context,
+            const unsigned char *data, unsigned int len) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, RMD160Update, context, data, len);
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len);
+  if (context)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, context, RMD160_CTX_sz);
+  REAL(RMD160Update)(context, data, len);
+}
+
+INTERCEPTOR(void, RMD160Final, unsigned char digest[20], void *context) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, RMD160Final, digest, context);
+  REAL(RMD160Final)(digest, context);
+  if (digest)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, digest, sizeof(unsigned char) * 20);
+}
+
+INTERCEPTOR(void, RMD160Transform, u32 state[5], const u32 buffer[16]) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, RMD160Transform, state, buffer);
+  if (state)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, state, sizeof(u32) * 5);
+  if (buffer)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, buffer, sizeof(u32) * 16);
+  REAL(RMD160Transform)(state, buffer);
+}
+
+INTERCEPTOR(char *, RMD160End, void *context, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, RMD160End, context, buf);
+  if (context)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, context, RMD160_CTX_sz);
+  char *ret = REAL(RMD160End)(context, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, RMD160_return_length);
+  return ret;
+}
+
+INTERCEPTOR(char *, RMD160File, char *filename, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, RMD160File, filename, buf);
+  if (filename)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, filename, REAL(strlen)(filename) + 1);
+  char *ret = REAL(RMD160File)(filename, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, RMD160_return_length);
+  return ret;
+}
+
+INTERCEPTOR(char *, RMD160Data, unsigned char *data, SIZE_T len, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, RMD160Data, data, len, buf);
+  if (data)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len);
+  char *ret = REAL(RMD160Data)(data, len, buf);
+  if (ret)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, RMD160_return_length);
+  return ret;
+}
+
+#define INIT_RMD160                                                            \
+  COMMON_INTERCEPT_FUNCTION(RMD160Init);                                       \
+  COMMON_INTERCEPT_FUNCTION(RMD160Update);                                     \
+  COMMON_INTERCEPT_FUNCTION(RMD160Final);                                      \
+  COMMON_INTERCEPT_FUNCTION(RMD160Transform);                                  \
+  COMMON_INTERCEPT_FUNCTION(RMD160End);                                        \
+  COMMON_INTERCEPT_FUNCTION(RMD160File);                                       \
+  COMMON_INTERCEPT_FUNCTION(RMD160Data)
+#else
+#define INIT_RMD160
+#endif
+
+#if SANITIZER_INTERCEPT_SHA2
+
+#define SHA2_INTERCEPTORS(LEN, SHA2_STATE_T) \
+  INTERCEPTOR(void, SHA##LEN##_Init, void *context) { \
+    void *ctx; \
+    COMMON_INTERCEPTOR_ENTER(ctx, SHA##LEN##_Init, context); \
+    REAL(SHA##LEN##_Init)(context); \
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, context, SHA##LEN##_CTX_sz); \
+  } \
+  INTERCEPTOR(void, SHA##LEN##_Update, void *context, \
+              const u8 *data, SIZE_T len) { \
+    void *ctx; \
+    COMMON_INTERCEPTOR_ENTER(ctx, SHA##LEN##_Update, context, data, len); \
+    if (data) \
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len); \
+    if (context) \
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, context, SHA##LEN##_CTX_sz); \
+    REAL(SHA##LEN##_Update)(context, data, len); \
+  } \
+  INTERCEPTOR(void, SHA##LEN##_Pad, void *context) { \
+    void *ctx; \
+    COMMON_INTERCEPTOR_ENTER(ctx, SHA##LEN##_Pad, context); \
+    if (context) \
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, context, SHA##LEN##_CTX_sz); \
+    REAL(SHA##LEN##_Pad)(context); \
+  } \
+  INTERCEPTOR(void, SHA##LEN##_Final, u8 digest[SHA##LEN##_digest_length], \
+  void *context) { \
+    void *ctx; \
+    COMMON_INTERCEPTOR_ENTER(ctx, SHA##LEN##_Final, digest, context); \
+    REAL(SHA##LEN##_Final)(digest, context); \
+    if (digest) \
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, digest, \
+                                     sizeof(digest[0]) * \
+  SHA##LEN##_digest_length); \
+  } \
+  INTERCEPTOR(void, SHA##LEN##_Transform, SHA2_STATE_T state[8], \
+              const u8 buffer[SHA##LEN##_block_length]) { \
+    void *ctx; \
+    COMMON_INTERCEPTOR_ENTER(ctx, SHA##LEN##_Transform, state, buffer); \
+    if (state) \
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, state, sizeof(state[0]) * 8); \
+    if (buffer) \
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, buffer, \
+                                    sizeof(buffer[0]) * \
+  SHA##LEN##_block_length); \
+    REAL(SHA##LEN##_Transform)(state, buffer); \
+  } \
+  INTERCEPTOR(char *, SHA##LEN##_End, void *context, char *buf) { \
+    void *ctx; \
+    COMMON_INTERCEPTOR_ENTER(ctx, SHA##LEN##_End, context, buf); \
+    if (context) \
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, context, SHA##LEN##_CTX_sz); \
+    char *ret = REAL(SHA##LEN##_End)(context, buf); \
+    if (ret) \
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, SHA##LEN##_return_length); \
+    return ret; \
+  } \
+  INTERCEPTOR(char *, SHA##LEN##_File, const char *filename, char *buf) { \
+    void *ctx; \
+    COMMON_INTERCEPTOR_ENTER(ctx, SHA##LEN##_File, filename, buf); \
+    if (filename) \
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, filename, REAL(strlen)(filename) + 1);\
+    char *ret = REAL(SHA##LEN##_File)(filename, buf); \
+    if (ret) \
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, SHA##LEN##_return_length); \
+    return ret; \
+  } \
+  INTERCEPTOR(char *, SHA##LEN##_FileChunk, const char *filename, char *buf, \
+              OFF_T offset, OFF_T length) { \
+    void *ctx; \
+    COMMON_INTERCEPTOR_ENTER(ctx, SHA##LEN##_FileChunk, filename, buf, offset, \
+  length); \
+    if (filename) \
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, filename, REAL(strlen)(filename) + 1);\
+    char *ret = REAL(SHA##LEN##_FileChunk)(filename, buf, offset, length); \
+    if (ret) \
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, SHA##LEN##_return_length); \
+    return ret; \
+  } \
+  INTERCEPTOR(char *, SHA##LEN##_Data, u8 *data, SIZE_T len, char *buf) { \
+    void *ctx; \
+    COMMON_INTERCEPTOR_ENTER(ctx, SHA##LEN##_Data, data, len, buf); \
+    if (data) \
+      COMMON_INTERCEPTOR_READ_RANGE(ctx, data, len); \
+    char *ret = REAL(SHA##LEN##_Data)(data, len, buf); \
+    if (ret) \
+      COMMON_INTERCEPTOR_WRITE_RANGE(ctx, ret, SHA##LEN##_return_length); \
+    return ret; \
+  }
+
+SHA2_INTERCEPTORS(224, u32);
+SHA2_INTERCEPTORS(256, u32);
+SHA2_INTERCEPTORS(384, u64);
+SHA2_INTERCEPTORS(512, u64);
+
+
+#define INIT_SHA2 \
+  COMMON_INTERCEPT_FUNCTION(SHA224_Init); \
+  COMMON_INTERCEPT_FUNCTION(SHA224_Update); \
+  COMMON_INTERCEPT_FUNCTION(SHA224_Pad); \
+  COMMON_INTERCEPT_FUNCTION(SHA224_Final); \
+  COMMON_INTERCEPT_FUNCTION(SHA224_Transform); \
+  COMMON_INTERCEPT_FUNCTION(SHA224_End); \
+  COMMON_INTERCEPT_FUNCTION(SHA224_File); \
+  COMMON_INTERCEPT_FUNCTION(SHA224_FileChunk); \
+  COMMON_INTERCEPT_FUNCTION(SHA224_Data); \
+  COMMON_INTERCEPT_FUNCTION(SHA256_Init); \
+  COMMON_INTERCEPT_FUNCTION(SHA256_Update); \
+  COMMON_INTERCEPT_FUNCTION(SHA256_Pad); \
+  COMMON_INTERCEPT_FUNCTION(SHA256_Final); \
+  COMMON_INTERCEPT_FUNCTION(SHA256_Transform); \
+  COMMON_INTERCEPT_FUNCTION(SHA256_End); \
+  COMMON_INTERCEPT_FUNCTION(SHA256_File); \
+  COMMON_INTERCEPT_FUNCTION(SHA256_FileChunk); \
+  COMMON_INTERCEPT_FUNCTION(SHA256_Data); \
+  COMMON_INTERCEPT_FUNCTION(SHA384_Init); \
+  COMMON_INTERCEPT_FUNCTION(SHA384_Update); \
+  COMMON_INTERCEPT_FUNCTION(SHA384_Pad); \
+  COMMON_INTERCEPT_FUNCTION(SHA384_Final); \
+  COMMON_INTERCEPT_FUNCTION(SHA384_Transform); \
+  COMMON_INTERCEPT_FUNCTION(SHA384_End); \
+  COMMON_INTERCEPT_FUNCTION(SHA384_File); \
+  COMMON_INTERCEPT_FUNCTION(SHA384_FileChunk); \
+  COMMON_INTERCEPT_FUNCTION(SHA384_Data); \
+  COMMON_INTERCEPT_FUNCTION(SHA512_Init); \
+  COMMON_INTERCEPT_FUNCTION(SHA512_Update); \
+  COMMON_INTERCEPT_FUNCTION(SHA512_Pad); \
+  COMMON_INTERCEPT_FUNCTION(SHA512_Final); \
+  COMMON_INTERCEPT_FUNCTION(SHA512_Transform); \
+  COMMON_INTERCEPT_FUNCTION(SHA512_End); \
+  COMMON_INTERCEPT_FUNCTION(SHA512_File); \
+  COMMON_INTERCEPT_FUNCTION(SHA512_FileChunk); \
+  COMMON_INTERCEPT_FUNCTION(SHA512_Data)
+
+#undef SHA2_INTERCEPTORS
+
+#else
+#define INIT_SHA2
+#endif
+
+#if SANITIZER_INTERCEPT_GETCHAR
+INTERCEPTOR(int, fgetc, __sanitizer_FILE *stream) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, fgetc, stream);
+  return REAL(fgetc)(stream);
+}
+INTERCEPTOR(int, getc, __sanitizer_FILE *stream) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, getc, stream);
+  return REAL(getc)(stream);
+}
+
+INTERCEPTOR(int, getchar) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, getchar);
+  return REAL(getchar)();
+}
+
+INTERCEPTOR(int, getc_unlocked, __sanitizer_FILE *stream) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, getc_unlocked, stream);
+  return REAL(getc_unlocked)(stream);
+}
+
+INTERCEPTOR(int, getchar_unlocked) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, getchar_unlocked);
+  return REAL(getchar_unlocked)();
+}
+
+#define INIT_GETCHAR \
+  COMMON_INTERCEPT_FUNCTION(fgetc); \
+  COMMON_INTERCEPT_FUNCTION(getc); \
+  COMMON_INTERCEPT_FUNCTION(getchar); \
+  COMMON_INTERCEPT_FUNCTION(getc_unlocked); \
+  COMMON_INTERCEPT_FUNCTION(getchar_unlocked)
+#else
+#define INIT_GETCHAR
+#endif
+
+#if SANITIZER_INTERCEPT_SETVBUF
+
+INTERCEPTOR(void, setbuf, __sanitizer_FILE *stream, char *buf) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, setbuf, stream, buf);
+  REAL(setbuf)(stream, buf);
+  if (buf)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, buf, setvbuf_bufsiz);
+}
+
+INTERCEPTOR(int, setvbuf, __sanitizer_FILE *stream, char *buf, int mode,
+  SIZE_T size) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, setvbuf, stream, buf, mode, size);
+  int ret = REAL(setvbuf)(stream, buf, mode, size);
+  if (buf)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, size);
+  return ret;
+}
+
+INTERCEPTOR(void, setbuffer, __sanitizer_FILE *stream, char *buf, SIZE_T size) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, setbuffer, stream, buf, size);
+  REAL(setbuffer)(stream, buf, size);
+  if (buf)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, buf, size);
+}
+
+#define INIT_SETVBUF \
+  COMMON_INTERCEPT_FUNCTION(setbuf); \
+  COMMON_INTERCEPT_FUNCTION(setbuffer); \
+  COMMON_INTERCEPT_FUNCTION(setvbuf)
+#else
+#define INIT_SETVBUF
+#endif
+
+#if SANITIZER_INTERCEPT_MI_VECTOR_HASH
+INTERCEPTOR(void, mi_vector_hash, const void *key, SIZE_T len, u32 seed,
+            u32 hashes[3]) {
+  void *ctx;
+  COMMON_INTERCEPTOR_ENTER(ctx, mi_vector_hash, key, len, seed, hashes);
+  if (key)
+    COMMON_INTERCEPTOR_READ_RANGE(ctx, key, len);
+  REAL(mi_vector_hash)(key, len, seed, hashes);
+  if (hashes)
+    COMMON_INTERCEPTOR_WRITE_RANGE(ctx, hashes, sizeof(hashes[0]) * 3);
+}
+#define INIT_MI_VECTOR_HASH COMMON_INTERCEPT_FUNCTION(mi_vector_hash)
+#else
+#define INIT_MI_VECTOR_HASH
+#endif
+
 static void InitializeCommonInterceptors() {
   static u64 metadata_mem[sizeof(MetadataHashMap) / sizeof(u64) + 1];
   interceptor_metadata_map = new((void *)&metadata_mem) MetadataHashMap();
@@ -7484,6 +9102,30 @@ static void InitializeCommonInterceptors
   INIT_TTYENT;
   INIT_PROTOENT;
   INIT_NETENT;
+  INIT_SYSCTL;
+  INIT_ATOF;
+  INIT_FTS;
+  INIT_REGEX;
+  INIT_STRTONUM;
+  INIT_VIS;
+  INIT_GETMNTINFO;
+  INIT_SHA1;
+  INIT_MD2;
+  INIT_MD4;
+  INIT_MD5;
+  INIT_GETVFSSTAT;
+  INIT_NL_LANGINFO;
+  INIT_FPARSELN;
+  INIT_MODCTL;
+  INIT_STATVFS1;
+  INIT_NETBSD_MOUNT;
+  INIT_FSEEK;
+  INIT_CDBR;
+  INIT_RMD160;
+  INIT_SHA2;
+  INIT_GETCHAR;
+  INIT_SETVBUF;
+  INIT_MI_VECTOR_HASH;
 
   INIT___PRINTF_CHK;
 }
