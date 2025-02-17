$NetBSD$

--- libpkg/pkgsign_ecc.c.orig	2025-02-17 16:32:34.691110431 +0000
+++ libpkg/pkgsign_ecc.c
@@ -819,6 +819,8 @@ _specific_explicit_bzero(void *buf, size
 
 #ifdef __APPLE__
 	memset_s(buf, bufsz, 0, bufsz);
+#elif defined(__NetBSD__)
+	explicit_memset(buf, 0, bufsz);
 #else
 	explicit_bzero(buf, bufsz);
 #endif
