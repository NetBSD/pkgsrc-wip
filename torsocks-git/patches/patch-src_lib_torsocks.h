$NetBSD$

--- src/lib/torsocks.h.orig	2018-10-08 16:16:47.830610306 +0000
+++ src/lib/torsocks.h
@@ -242,6 +242,9 @@ struct hostent **result, int *h_errnop
 #define LIBC_SYSCALL_SIG long int number, ...
 #define LIBC_SYSCALL_ARGS number
 
+#endif /* __linux__ */
+
+#if defined(__linux__) || defined(__NetBSD__)
 /* accept4(2) */
 #define LIBC_ACCEPT4_NAME accept4
 #define LIBC_ACCEPT4_NAME_STR XSTR(LIBC_ACCEPT4_NAME)
@@ -249,8 +252,8 @@ struct hostent **result, int *h_errnop
 #define LIBC_ACCEPT4_SIG \
 	int sockfd, struct sockaddr *addr, socklen_t *addrlen, int flags
 #define LIBC_ACCEPT4_ARGS sockfd, addr, addrlen, flags
+#endif
 
-#endif /* __linux__ */
 
 #if (defined(__FreeBSD__) || defined(__darwin__) || defined(__NetBSD__))
 
@@ -414,7 +417,7 @@ TSOCKS_DECL(accept, LIBC_ACCEPT_RET_TYPE
 		LIBC_ACCEPT_NAME(LIBC_ACCEPT_SIG)
 
 /* accept4(2) */
-#if (defined(__linux__))
+#if (defined(__linux__) || defined(__NetBSD__))
 extern TSOCKS_LIBC_DECL(accept4, LIBC_ACCEPT4_RET_TYPE, LIBC_ACCEPT4_SIG)
 TSOCKS_DECL(accept4, LIBC_ACCEPT4_RET_TYPE, LIBC_ACCEPT4_SIG)
 #define LIBC_ACCEPT4_DECL LIBC_ACCEPT4_RET_TYPE \
