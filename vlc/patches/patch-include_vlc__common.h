$NetBSD$

Backport patch merged upstream: disable bswap* and popcount*
functions for NetBSD, as they are part of libc.

--- include/vlc_common.h.orig	2017-12-21 09:51:16.000000000 +0000
+++ include/vlc_common.h
@@ -556,6 +556,7 @@ static inline unsigned (ctz)(unsigned x)
 #endif
 }
 
+#if !defined(__NetBSD__)
 /** Bit weight */
 VLC_USED
 static inline unsigned (popcount)(unsigned x)
@@ -589,6 +590,7 @@ static inline int (popcountll)(unsigned 
     return count;
 #endif
 }
+#endif
 
 VLC_USED
 static inline unsigned (parity)(unsigned x)
@@ -602,6 +604,7 @@ static inline unsigned (parity)(unsigned
 #endif
 }
 
+#if !defined(__NetBSD__)
 /** Byte swap (16 bits) */
 VLC_USED
 static inline uint16_t (bswap16)(uint16_t x)
@@ -649,6 +652,7 @@ static inline uint64_t (bswap64)(uint64_
          | ((x & 0xFF00000000000000ULL) >> 56);
 #endif
 }
+#endif
 
 /* Integer overflow */
 static inline bool uadd_overflow(unsigned a, unsigned b, unsigned *res)
