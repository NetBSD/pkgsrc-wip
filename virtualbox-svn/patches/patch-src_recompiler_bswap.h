$NetBSD$

--- src/recompiler/bswap.h.orig	2016-08-05 16:11:33.000000000 +0000
+++ src/recompiler/bswap.h
@@ -49,6 +49,7 @@
 
 #endif /* !CONFIG_BYTESWAP_H */
 
+#ifndef __NetBSD__
 static inline uint16_t bswap16(uint16_t x)
 {
     return bswap_16(x);
@@ -63,9 +64,11 @@ static inline uint64_t bswap64(uint64_t 
 {
     return bswap_64(x);
 }
+#endif
 
 #endif /* ! CONFIG_MACHINE_BSWAP_H */
 
+#ifndef __NetBSD__
 static inline void bswap16s(uint16_t *s)
 {
     *s = bswap16(*s);
@@ -80,6 +83,7 @@ static inline void bswap64s(uint64_t *s)
 {
     *s = bswap64(*s);
 }
+#endif
 
 #if defined(HOST_WORDS_BIGENDIAN)
 #define be_bswap(v, size) (v)
