$NetBSD: patch-src_miniupnpc_connecthostport.c,v 1.1 2012/11/23 14:55:10 othyro Exp $

Generate correct reference to select().

--- src/miniupnpc/connecthostport.c.orig	2012-02-27 23:25:30.000000000 +0000
+++ src/miniupnpc/connecthostport.c
@@ -9,6 +9,7 @@
  * uncomment the following line in order to use gethostbyname() */
 /* #define USE_GETHOSTBYNAME */
 
+#include <sys/select.h>
 #include <string.h>
 #include <stdio.h>
 #ifdef WIN32
