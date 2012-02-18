$NetBSD: patch-client.c,v 1.1 2012/02/18 20:20:37 ishit Exp $

fix security issues.
fix CVE-2009-3305 from Debian BTS.
fix CVE-2011-3596 from Tor Project git repository.
cf.https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2011-3596

--- client.c.orig	2008-01-08 12:56:45.000000000 +0000
+++ client.c
@@ -978,7 +978,7 @@ httpClientDiscardBody(HTTPConnectionPtr 
     if(connection->bodylen < 0)
         goto fail;
 
-    if(connection->bodylen + connection->reqbegin < connection->reqlen) {
+    if(connection->bodylen < connection->reqlen - connection->reqbegin) {
         connection->reqbegin += connection->bodylen;
         connection->bodylen = 0;
     } else {
@@ -987,7 +987,6 @@ httpClientDiscardBody(HTTPConnectionPtr 
         connection->reqlen = 0;
         httpConnectionDestroyReqbuf(connection);
     }
-    connection->reqte = TE_UNKNOWN;
 
     if(connection->bodylen > 0) {
         httpSetTimeout(connection, clientTimeout);
