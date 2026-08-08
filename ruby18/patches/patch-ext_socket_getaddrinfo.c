$NetBSD$

--- ext/socket/getaddrinfo.c.orig	2011-05-20 22:28:18.000000000 +0000
+++ ext/socket/getaddrinfo.c
@@ -91,10 +91,6 @@
 #include "addrinfo.h"
 #include "sockport.h"
 
-#if defined(__KAME__) && defined(INET6)
-# define FAITH
-#endif
-
 #define SUCCESS 0
 #define ANY 0
 #define YES 1
@@ -497,11 +493,7 @@ getaddrinfo(hostname, servname, hints, res)
 				break;
 #ifdef INET6
 			case AF_INET6:
-#ifdef HAVE_ADDR8
-				pfx = ((struct in6_addr *)pton)->s6_addr8[0];
-#else
 				pfx = ((struct in6_addr *)pton)->s6_addr[0];
-#endif
 				if (pfx == 0 || pfx == 0xfe || pfx == 0xff)
 					pai->ai_flags &= ~AI_CANONNAME;
 				break;
@@ -677,9 +669,10 @@ get_addr(hostname, af, res, pai, port0)
 
 			GET_AI(cur->ai_next, &afdl[N_INET6], ap, port);
 			in6 = &((struct sockaddr_in6 *)cur->ai_next->ai_addr)->sin6_addr;
-			memcpy(&in6->s6_addr32[0], &faith_prefix,
-			    sizeof(struct in6_addr) - sizeof(struct in_addr));
-			memcpy(&in6->s6_addr32[3], ap, sizeof(struct in_addr));
+			memcpy(&in6->s6_addr, &faith_prefix,
+			       sizeof(struct in6_addr) - sizeof(struct in_addr));
+			memcpy(&in6->s6_addr + sizeof(struct in_addr), ap,
+			       sizeof(struct in_addr));
 		} else
 #endif /* FAITH */
 		GET_AI(cur->ai_next, afd, ap, port);
