$NetBSD$

--- include/vlc_common.h.orig	2017-12-21 09:51:16.000000000 +0000
+++ include/vlc_common.h
@@ -556,6 +556,8 @@ static inline unsigned (ctz)(unsigned x)
 #endif
 }
 
+#ifndef __NetBSD__
+
 /** Bit weight */
 VLC_USED
 static inline unsigned (popcount)(unsigned x)
@@ -590,6 +592,8 @@ static inline int (popcountll)(unsigned 
 #endif
 }
 
+#endif
+
 VLC_USED
 static inline unsigned (parity)(unsigned x)
 {
@@ -602,6 +606,8 @@ static inline unsigned (parity)(unsigned
 #endif
 }
 
+#ifndef __NetBSD__
+
 /** Byte swap (16 bits) */
 VLC_USED
 static inline uint16_t (bswap16)(uint16_t x)
@@ -650,6 +656,8 @@ static inline uint64_t (bswap64)(uint64_
 #endif
 }
 
+#endif
+
 /* Integer overflow */
 static inline bool uadd_overflow(unsigned a, unsigned b, unsigned *res)
 {
