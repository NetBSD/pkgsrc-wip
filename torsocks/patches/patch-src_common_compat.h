$NetBSD: patch-src_common_compat.h,v 1.2 2013/11/05 14:56:43 thomasklausner Exp $

Handle NetBSD like FreeBSD.

--- src/common/compat.h.orig	2013-11-03 18:24:51.000000000 +0000
+++ src/common/compat.h
@@ -22,7 +22,7 @@
 #define __darwin__	1
 #endif
 
-#if (defined(__GLIBC__) || defined(__FreeBSD__) || defined(__darwin__))
+#if (defined(__GLIBC__) || defined(__FreeBSD__) || defined(__darwin__) || defined(__NetBSD__))
 
 #define RTLD_NEXT	((void *) -1)
 
@@ -43,7 +43,7 @@ void tsocks_mutex_unlock(tsocks_mutex_t 
 
 #else
 #error "OS not supported."
-#endif /* __GLIBC__, __darwin__, __FreeBSD__ */
+#endif /* __GLIBC__, __darwin__, __FreeBSD__, __NetBSD__ */
 
 #if defined(__linux__)
 
@@ -84,17 +84,21 @@ void tsocks_mutex_unlock(tsocks_mutex_t 
 
 #endif /* __linux__ */
 
-#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__darwin__))
+#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__darwin__) || defined(__NetBSD__))
 
 #include <sys/syscall.h>
 #include <unistd.h>
 
+#if defined(__NetBSD__)
+#define SYS_socket          SYS___socket30
+#endif
+
 #define TSOCKS_NR_SOCKET    SYS_socket
 #define TSOCKS_NR_CONNECT   SYS_connect
 #define TSOCKS_NR_CLOSE     SYS_close
 #define TSOCKS_NR_MMAP      SYS_mmap
 #define TSOCKS_NR_MUNMAP    SYS_munmap
 
-#endif /* __FreeBSD__, __FreeBSD_kernel__, __darwin__ */
+#endif /* __FreeBSD__, __FreeBSD_kernel__, __darwin__, __NetBSD__ */
 
 #endif /* TORSOCKS_COMPAT_H */
