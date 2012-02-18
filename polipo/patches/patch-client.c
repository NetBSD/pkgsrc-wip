$NetBSD: patch-client.c,v 1.2 2012/02/18 21:31:43 ishit Exp $

fix security issue (CVE-2011-3596).
patch from Tor Project git repository.
cf.https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2011-3596

--- client.c.orig	2008-01-08 12:56:45.000000000 +0000
+++ client.c
@@ -987,7 +987,6 @@ httpClientDiscardBody(HTTPConnectionPtr 
         connection->reqlen = 0;
         httpConnectionDestroyReqbuf(connection);
     }
-    connection->reqte = TE_UNKNOWN;
 
     if(connection->bodylen > 0) {
         httpSetTimeout(connection, clientTimeout);
