$NetBSD$

--- external/libder/libder/libder_private.h.orig	2025-02-17 16:29:09.698886269 +0000
+++ external/libder/libder/libder_private.h
@@ -150,6 +150,8 @@ libder_bzero(uint8_t *buf, size_t bufsz)
 
 #ifdef __APPLE__
 	memset_s(buf, bufsz, 0, bufsz);
+#elif defined(__NetBSD__)
+	explicit_memset(buf, 0, bufsz);
 #else
 	explicit_bzero(buf, bufsz);
 #endif
