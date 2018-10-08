$NetBSD$

--- src/lib/accept.c.orig	2018-10-08 16:15:36.361359954 +0000
+++ src/lib/accept.c
@@ -87,7 +87,7 @@ LIBC_ACCEPT_DECL
 	return tsocks_accept(LIBC_ACCEPT_ARGS);
 }
 
-#if (defined(__linux__))
+#if (defined(__linux__) || defined(__NetBSD__))
 
 TSOCKS_LIBC_DECL(accept4, LIBC_ACCEPT4_RET_TYPE, LIBC_ACCEPT4_SIG)
 
