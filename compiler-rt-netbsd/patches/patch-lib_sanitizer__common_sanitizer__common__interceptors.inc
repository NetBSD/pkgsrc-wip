$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2018-12-10 09:29:18.792901648 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -119,6 +119,7 @@
 #define times __times13
 #define wait3 __wait350
 #define wait4 __wait450
+#define mount __mount50
 extern const unsigned short *_ctype_tab_;
 extern const short *_toupper_tab_;
 extern const short *_tolower_tab_;
@@ -3085,17 +3086,28 @@ INTERCEPTOR(int, sendmmsg, int fd, struc
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
@@ -8460,6 +8472,464 @@ SHA2_INTERCEPTORS(512, u64);
 #define INIT_SHA2
 #endif
 
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
+#if SANITIZER_INTERCEPT_NETBSD_MOUNT
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
 static void InitializeCommonInterceptors() {
   static u64 metadata_mem[sizeof(MetadataHashMap) / sizeof(u64) + 1];
   interceptor_metadata_map =
@@ -8738,5 +9208,10 @@ static void InitializeCommonInterceptors
   INIT_MD2;
   INIT_SHA2;
 
+  INIT_VIS;
+  INIT_NETBSD_MOUNT;
+  INIT_CDBR;
+  INIT_GETCHAR;
+
   INIT___PRINTF_CHK;
 }
