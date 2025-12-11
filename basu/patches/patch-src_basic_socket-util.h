$NetBSD$

--- src/basic/socket-util.h.orig	2022-12-16 10:13:02.000000000 +0000
+++ src/basic/socket-util.h
@@ -29,6 +29,9 @@ struct ucred {
         uint32_t uid;
         uint32_t gid;
 };
+#elif defined(__NetBSD__)
+#define ucred unpcbid
+#define SO_PEERCRED LOCAL_PEEREID
 #endif
 
 int fd_inc_sndbuf(int fd, size_t n);
