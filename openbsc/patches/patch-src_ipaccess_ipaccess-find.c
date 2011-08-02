$NetBSD: patch-src_ipaccess_ipaccess-find.c,v 1.1 2011/08/02 23:05:26 khorben Exp $

--- src/ipaccess/ipaccess-find.c.orig	2011-03-05 14:16:19.000000000 +0000
+++ src/ipaccess/ipaccess-find.c
@@ -61,12 +61,14 @@ static int udp_sock(const char *ifname)
 	if (fd < 0)
 		return fd;
 
+#ifdef SO_BINDTODEVICE
 	if (ifname) {
 		rc = setsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE, ifname,
 				strlen(ifname));
 		if (rc < 0)
 			goto err;
 	}
+#endif
 
 	sa.sin_family = AF_INET;
 	sa.sin_port = htons(3006);
