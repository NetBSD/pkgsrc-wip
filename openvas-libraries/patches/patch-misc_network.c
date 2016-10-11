$NetBSD$

Add NetBSD support.

--- misc/network.c.orig	2016-08-25 12:02:52.000000000 +0000
+++ misc/network.c
@@ -2068,7 +2068,11 @@ open_sock_opt_hn (const char *hostname, 
       bzero ((void *) &addr, sizeof (addr));
       addr.sin_family = AF_INET;
       addr.sin_port = htons ((unsigned short) port);
+#if defined(__NetBSD__)
+      memcpy(&addr.sin_addr.s_addr, &in6addr.s6_addr[12], 4);
+#else
       addr.sin_addr.s_addr = in6addr.s6_addr32[3];
+#endif
       return open_socket ((struct sockaddr *) &addr, type, protocol,
                           timeout, sizeof (struct sockaddr_in));
     }
@@ -2158,7 +2162,11 @@ open_sock_option (struct arglist *args, 
       bzero ((void *) &addr, sizeof (addr));
       addr.sin_family = AF_INET;
       addr.sin_port = htons ((unsigned short) port);
+#if defined(__NetBSD__)
+      memcpy(&addr.sin_addr.s_addr, &t->s6_addr[12], 4);
+#else
       addr.sin_addr.s_addr = t->s6_addr32[3];
+#endif
       return open_socket ((struct sockaddr *) &addr, type, protocol,
                           timeout, sizeof (struct sockaddr_in));
     }
