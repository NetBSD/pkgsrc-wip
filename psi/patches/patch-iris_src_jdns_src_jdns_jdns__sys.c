$NetBSD$

--- iris/src/jdns/src/jdns/jdns_sys.c.orig	2018-11-18 10:47:00.011865328 +0000
+++ iris/src/jdns/src/jdns/jdns_sys.c
@@ -700,7 +700,7 @@ static jdns_dnsparams_t *dnsparams_get_u
 	return params;
 }
 
-#if defined(__GLIBC__) && ((__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 3)))
+#if defined(__GLIBC__) && ((__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 3))) || defined(JDNS_OS_NETBSD)
 # define JDNS_MODERN_RES_API
 #endif
 
