$NetBSD: patch-dep_net.c,v 1.1 2013/06/18 10:29:14 fhajny Exp $

Add support for SunOS.
--- dep/net.c.orig	2012-06-20 20:02:51.000000000 +0000
+++ dep/net.c
@@ -566,7 +566,11 @@ netInit(NetPath * netPath, RunTimeOpts *
 	if (rtOpts->unicastAddress[0]) {
 		/* Attempt a DNS lookup first. */
 		struct hostent *host;
+#if defined(__sun)
+		host = getipnodebyname(rtOpts->unicastAddress, AF_INET, AI_DEFAULT, &errno);
+#else
 		host = gethostbyname2(rtOpts->unicastAddress, AF_INET);
+#endif
                 if (host != NULL) {
 			if (host->h_length != 4) {
 				PERROR("unicast host resolved to non ipv4"
