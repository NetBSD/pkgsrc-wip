$NetBSD: patch-src_airserv-ng.c,v 1.1 2015/02/07 01:35:39 tnn2 Exp $

--- src/airserv-ng.c.orig	2013-05-25 23:06:24.000000000 +0000
+++ src/airserv-ng.c
@@ -24,6 +24,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/select.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <stdio.h>
