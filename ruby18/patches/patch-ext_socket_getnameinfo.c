$NetBSD$

--- ext/socket/getnameinfo.c.orig	2011-05-20 22:28:18.000000000 +0000
+++ ext/socket/getnameinfo.c
@@ -139,11 +139,11 @@ getnameinfo(sa, salen, host, hostlen, serv, servlen, f
 int
 getnameinfo(sa, salen, host, hostlen, serv, servlen, flags)
 	const struct sockaddr *sa;
-	size_t salen;
+	socklen_t salen;
 	char *host;
-	size_t hostlen;
+	socklen_t hostlen;
 	char *serv;
-	size_t servlen;
+	socklen_t servlen;
 	int flags;
 {
 	struct afd *afd;
