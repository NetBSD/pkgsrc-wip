$NetBSD$
Already defined in NetBSD.
--- lib/utils.h.orig	2017-01-12 22:25:43.250993980 +0000
+++ lib/utils.h	2017-01-12 22:26:10.706196178 +0000
@@ -249,7 +249,7 @@
                const char *code,
                const int code_len);
 
-
+#if !defined(__NetBSD__)
 /*
  * Utility functions for converting data to/from network byte order.
  */
@@ -271,6 +271,7 @@
 
     return ret;
 }
+#endif
 
 static inline uint64_t
 hton64(uint64_t val)
