$NetBSD$

Adapt to NetBSD.

--- cutils.h.orig	2019-07-09 17:49:47.000000000 +0000
+++ cutils.h
@@ -207,6 +207,7 @@ static inline void put_u8(uint8_t *tab, 
     *tab = val;
 }
 
+#ifndef __NetBSD__
 static inline uint16_t bswap16(uint16_t x)
 {
     return (x >> 8) | (x << 8);
@@ -229,6 +230,7 @@ static inline uint64_t bswap64(uint64_t 
         ((v & ((uint64_t)0xff << (1 * 8))) << (5 * 8)) | 
         ((v & ((uint64_t)0xff << (0 * 8))) << (7 * 8));
 }
+#endif /* __NetBSD__ */
 
 /* XXX: should take an extra argument to pass slack information to the caller */
 typedef void *DynBufReallocFunc(void *opaque, void *ptr, size_t size);
