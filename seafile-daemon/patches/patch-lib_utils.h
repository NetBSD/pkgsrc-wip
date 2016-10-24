$NetBSD$
Function bswap64 already defined in NetBSD

--- lib/utils.h.orig	2016-10-24 00:15:07.519135846 +0000
+++ lib/utils.h	2016-10-24 00:16:37.094914530 +0000
@@ -253,6 +253,7 @@
                const int code_len);
 
 
+#if !defined(__NetBSD__)
 /*
  * Utility functions for converting data to/from network byte order.
  */
@@ -274,6 +275,7 @@
 
     return ret;
 }
+#endif
 
 static inline uint64_t
 hton64(uint64_t val)
