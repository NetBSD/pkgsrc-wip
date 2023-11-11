$NetBSD$

--- cutils.h.orig	2023-03-09 11:57:59.000000000 +0000
+++ cutils.h
@@ -394,18 +394,18 @@ static inline void put_u8(uint8_t *tab, 
     *tab = val;
 }
 
-static inline uint16_t bswap16(uint16_t x)
+static inline uint16_t bswap16n(uint16_t x)
 {
     return (x >> 8) | (x << 8);
 }
 
-static inline uint32_t bswap32(uint32_t v)
+static inline uint32_t bswap32n(uint32_t v)
 {
     return ((v & 0xff000000) >> 24) | ((v & 0x00ff0000) >>  8) |
         ((v & 0x0000ff00) <<  8) | ((v & 0x000000ff) << 24);
 }
 
-static inline uint64_t bswap64(uint64_t v)
+static inline uint64_t bswap64n(uint64_t v)
 {
     return ((v & ((uint64_t)0xff << (7 * 8))) >> (7 * 8)) |
         ((v & ((uint64_t)0xff << (6 * 8))) >> (5 * 8)) |
