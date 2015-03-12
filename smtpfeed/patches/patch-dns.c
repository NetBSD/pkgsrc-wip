$NetBSD: patch-dns.c,v 1.2 2015/03/12 01:05:05 makoto Exp $

show_query() returning nothing

--- dns.c.orig	2015-02-17 23:01:03.000000000 +0900
+++ dns.c	2015-03-12 10:02:48.000000000 +0900
@@ -42,6 +42,8 @@ static char *_id_ = "$Id: dns.c,v 1.90 2
 # include "common.h"
 # include "extern.h"
 
+void show_query(u_char* t, u_char* b, u_char* e);
+
 #if PACKETSZ > 1024
 #define MAXPACKET	PACKETSZ
 #else
@@ -2222,6 +2224,7 @@ long opt;	/* option described in map fil
 	return 0;
 }
 
+void
 show_query(t, b, e)
 u_char *t, *b, *e;
 {
