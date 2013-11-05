$NetBSD: patch-src_lib_torsocks.h,v 1.1 2013/11/05 14:56:43 thomasklausner Exp $

Handle NetBSD like FreeBSD.

--- src/lib/torsocks.h.orig	2013-11-03 18:24:51.000000000 +0000
+++ src/lib/torsocks.h
@@ -33,7 +33,7 @@
 #define TSOCKS_DECL(name, type, sig) \
 	extern type tsocks_##name(sig);
 
-#if (defined(__GLIBC__) || defined(__FreeBSD__) || defined(__darwin__))
+#if (defined(__GLIBC__) || defined(__FreeBSD__) || defined(__darwin__) || defined(__NetBSD__))
 
 /* connect(2) */
 #include <sys/types.h>
@@ -171,7 +171,7 @@ struct hostent **__result, int *__h_errn
 
 #else
 #error "OS not supported."
-#endif /* __GLIBC__ , __FreeBSD__, __darwin__ */
+#endif /* __GLIBC__ , __FreeBSD__, __darwin__, __NetBSD__ */
 
 #if (defined(__linux__))
 
@@ -186,7 +186,7 @@ struct hostent **__result, int *__h_errn
 
 #endif /* __linux__ */
 
-#if (defined(__FreeBSD__) || defined(__darwin__))
+#if (defined(__FreeBSD__) || defined(__darwin__) || defined(__NetBSD__))
 
 /* syscall(2) */
 #define LIBC_SYSCALL_NAME syscall
@@ -195,7 +195,7 @@ struct hostent **__result, int *__h_errn
 #define LIBC_SYSCALL_SIG int __number, ...
 #define LIBC_SYSCALL_ARGS __number
 
-#endif /* __FreeBSD__, __darwin__ */
+#endif /* __FreeBSD__, __darwin__, __NetBSD__ */
 
 #if defined(__GLIBC__) && defined(__FreeBSD_kernel__)
 
