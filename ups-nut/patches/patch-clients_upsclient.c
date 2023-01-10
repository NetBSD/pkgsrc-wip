$NetBSD: patch-clients_upsclient.c,v 1.2 2018/09/21 00:59:53 jym Exp $

Add missing header for timeval(3) functions.

--- clients/upsclient.c.orig	2022-11-26 14:02:03.000000000 +0000
+++ clients/upsclient.c
@@ -38,6 +38,7 @@
 #ifndef WIN32
 # include <netdb.h>
 # include <sys/socket.h>
+# include <sys/time.h>
 # include <netinet/in.h>
 # include <arpa/inet.h>
 # include <fcntl.h>
