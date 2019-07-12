$NetBSD$

Adapt to NetBSD.

--- cutils.h.orig 2019-07-09 19:49:47.000000000 +0200
+++ cutils.h     2019-07-12 00:50:00.924951444 +0200
@@ -206,6 +206,7 @@
     *tab = val;
 }
 
+#ifndef __NetBSD__
 static inline uint16_t bswap16(uint16_t x)
 {
     return (x >> 8) | (x << 8);
@@ -228,6 +229,7 @@
         ((v & ((uint64_t)0xff << (1 * 8))) << (5 * 8)) | 
         ((v & ((uint64_t)0xff << (0 * 8))) << (7 * 8));
 }
+#endif /* __NetBSD__ */
 
 /* XXX: should take an extra argument to pass slack information to the caller */
 typedef void *DynBufReallocFunc(void *opaque, void *ptr, size_t size);
