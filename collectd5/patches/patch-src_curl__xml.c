$NetBSD: patch-src_curl__xml.c,v 1.1 2014/01/18 19:13:53 fhajny Exp $

Fix clang build as per

http://svnweb.freebsd.org/ports/head/net-mgmt/collectd5/files/patch-src-curl_xml.c
--- src/curl_xml.c.orig	2013-08-18 10:24:25.069973376 +0000
+++ src/curl_xml.c
@@ -607,7 +607,7 @@ static int cx_curl_perform (cx_t *db, CU
   int status;
   long rc;
   char *ptr;
-  char *url;
+  char *url = NULL;
 
   db->buffer_fill = 0; 
   status = curl_easy_perform (curl);
