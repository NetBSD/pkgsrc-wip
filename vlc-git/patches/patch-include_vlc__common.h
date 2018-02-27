$NetBSD$

--- include/vlc_common.h.orig	2018-02-22 06:29:54.000000000 +0000
+++ include/vlc_common.h
@@ -556,6 +556,8 @@ static inline unsigned (ctz)(unsigned x)
 #endif
 }
 
+
+#ifndef HAVE_POPCOUNT
 /** Bit weight */
 VLC_USED
 static inline unsigned (popcount)(unsigned x)
@@ -572,7 +574,9 @@ static inline unsigned (popcount)(unsign
     return count;
 #endif
 }
+#endif
 
+#ifndef HAVE_POPCOUNTLL
 /** Bit weight of long long */
 VLC_USED
 static inline int (popcountll)(unsigned long long x)
@@ -589,6 +593,7 @@ static inline int (popcountll)(unsigned 
     return count;
 #endif
 }
+#endif
 
 VLC_USED
 static inline unsigned (parity)(unsigned x)
@@ -602,13 +607,16 @@ static inline unsigned (parity)(unsigned
 #endif
 }
 
+#ifndef HAVE_BSWAP16
 /** Byte swap (16 bits) */
 VLC_USED
 static inline uint16_t (bswap16)(uint16_t x)
 {
     return (x << 8) | (x >> 8);
 }
+#endif
 
+#ifndef HAVE_BSWAP32
 /** Byte swap (32 bits) */
 VLC_USED
 static inline uint32_t (bswap32)(uint32_t x)
@@ -622,7 +630,9 @@ static inline uint32_t (bswap32)(uint32_
          | ((x & 0xFF000000) >> 24);
 #endif
 }
+#endif
 
+#ifndef HAVE_BSWAP64
 /** Byte swap (64 bits) */
 VLC_USED
 static inline uint64_t (bswap64)(uint64_t x)
@@ -649,6 +659,7 @@ static inline uint64_t (bswap64)(uint64_
          | ((x & 0xFF00000000000000ULL) >> 56);
 #endif
 }
+#endif
 
 /* Integer overflow */
 static inline bool uadd_overflow(unsigned a, unsigned b, unsigned *res)
