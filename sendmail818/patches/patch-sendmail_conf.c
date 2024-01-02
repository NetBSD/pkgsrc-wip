$NetBSD: patch-af,v 1.13 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/conf.c.orig	2023-12-05 09:53:22.000000000 +0000
+++ sendmail/conf.c
@@ -45,6 +45,10 @@ SM_RCSID("@(#)$Id: conf.c,v 8.1192 2014-
 # include "tls.h"
 #endif
 
+#if !HAS_GETHOSTBYNAME2
+extern struct __res_state sm_res;
+#endif
+
 static void	setupmaps __P((void));
 static void	setupmailers __P((void));
 static void	setupqueues __P((void));
@@ -4317,15 +4321,15 @@ sm_getipnodebyname(name, family, flags, 
 	if (family == AF_INET6)
 	{
 		/* From RFC2133, section 6.1 */
-		resv6 = bitset(RES_USE_INET6, _res.options);
-		_res.options |= RES_USE_INET6;
+		resv6 = bitset(RES_USE_INET6, sm_res.options);
+		sm_res.options |= RES_USE_INET6;
 	}
 #  endif /* RES_USE_INET6 */
 	SM_SET_H_ERRNO(0);
 	h = gethostbyname(name);
 #  ifdef RES_USE_INET6
 	if (!resv6)
-		_res.options &= ~RES_USE_INET6;
+		sm_res.options &= ~RES_USE_INET6;
 #  endif
 
 	/* the function is supposed to return only the requested family */
@@ -4546,7 +4550,8 @@ sm_gethostbyaddr(addr, len, type)
 
 #if NETINET6
 	if (type == AF_INET6 &&
-	    IN6_IS_ADDR_UNSPECIFIED((struct in6_addr *) addr))
+	    (IN6_IS_ADDR_UNSPECIFIED((struct in6_addr *) addr) ||
+	    IN6_IS_ADDR_LINKLOCAL((struct in6_addr *) addr)))
 	{
 		/* Avoid reverse lookup for IPv6 unspecified address */
 		SM_SET_H_ERRNO(HOST_NOT_FOUND);
@@ -5719,12 +5724,12 @@ local_hostname_length(hostname)
 {
 	size_t len_host, len_domain;
 
-	if (!*_res.defdname)
+	if (!*sm_res.defdname)
 		res_init();
 	len_host = strlen(hostname);
-	len_domain = strlen(_res.defdname);
+	len_domain = strlen(sm_res.defdname);
 	if (len_host > len_domain &&
-	    (SM_STRCASEEQ(hostname + len_host - len_domain, _res.defdname)) &&
+	    (SM_STRCASEEQ(hostname + len_host - len_domain, sm_res.defdname)) &&
 	    hostname[len_host - len_domain - 1] == '.')
 		return len_host - len_domain - 1;
 	else
