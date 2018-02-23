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
