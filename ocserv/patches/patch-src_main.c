$NetBSD$

--- src/main.c.orig	2016-04-25 20:55:23.000000000 +0000
+++ src/main.c
@@ -139,7 +139,7 @@ int y;
 #endif
 		}
 	}
-#if defined(IP_PKTINFO)
+#if defined(IP_PKTINFO) && !defined(IP_RECVDSTADDR)
 	y = 1;
 	if (setsockopt(fd, SOL_IP, IP_PKTINFO,
 		       (const void *)&y, sizeof(y)) < 0)
