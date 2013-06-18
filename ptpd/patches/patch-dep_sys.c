$NetBSD: patch-dep_sys.c,v 1.1 2013/06/18 10:29:14 fhajny Exp $

Add support for SunOS.
--- dep/sys.c.orig	2012-06-20 20:02:51.000000000 +0000
+++ dep/sys.c
@@ -231,7 +231,7 @@ int ether_ntohost_cache(char *hostname,
 	static struct ether_addr prev_addr;
 	static char buf[BUF_SIZE];
 
-#if defined(linux) || defined(__NetBSD__)
+#if defined(linux) || defined(__NetBSD__) || defined(__sun)
 	if (memcmp(addr->ether_addr_octet, &prev_addr, 
 		  sizeof(struct ether_addr )) != 0) {
 		valid = 0;
@@ -275,7 +275,7 @@ snprint_ClockIdentity_ntohost(char *s, i
 	for (i = 0, j = 0; i< CLOCK_IDENTITY_LENGTH ; i++ ){
 		/* skip bytes 3 and 4 */
 		if(!((i==3) || (i==4))){
-#if defined(linux) || defined(__NetBSD__)
+#if defined(linux) || defined(__NetBSD__) || defined(__sun)
 			e.ether_addr_octet[j] = (uint8_t) id[i];
 #else // e.g. defined(__FreeBSD__)
 			e.octet[j] = (uint8_t) id[i];
