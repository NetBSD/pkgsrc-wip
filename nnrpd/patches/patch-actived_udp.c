$NetBSD: patch-actived_udp.c,v 1.1 2011/09/21 20:10:17 hfath Exp $

Add missing #includes for isdigit() and inet_addr()

--- actived/udp.c.orig	1997-12-17 18:00:32.000000000 +0000
+++ actived/udp.c
@@ -1,9 +1,11 @@
 #include	<stdio.h>
+#include        <ctype.h>
 #include	<sys/types.h>
 #include	"clibrary.h"
 #include	<errno.h>
 #include	<sys/socket.h>
 #include	<netinet/in.h>
+#include        <arpa/inet.h>
 #include	<netdb.h>
 #include	"logging.h"
 
