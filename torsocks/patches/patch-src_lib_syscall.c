$NetBSD: patch-src_lib_syscall.c,v 1.1 2014/08/15 20:59:39 leot1990 Exp $

handle_mmap() is needed in order to correctly build torsocks.

--- src/lib/syscall.c.orig	2014-08-11 16:44:46.000000000 +0000
+++ src/lib/syscall.c
@@ -68,7 +68,7 @@ static LIBC_CONNECT_RET_TYPE handle_conn
 	return tsocks_connect(sockfd, addr, addrlen);
 }
 
-#if (defined(__linux__) || defined(__darwin__) || (defined(__FreeBSD_kernel__) && defined(__i386__)))
+#if (defined(__linux__) || defined(__darwin__) || (defined(__FreeBSD_kernel__) && defined(__i386__)) || defined(__NetBSD__))
 /*
  * Handle mmap(2) syscall.
  */
