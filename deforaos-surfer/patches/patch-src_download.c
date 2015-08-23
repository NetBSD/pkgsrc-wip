$NetBSD: patch-src_download.c,v 1.3 2015/08/23 13:26:51 thomasklausner Exp $

Add missing header for h_errno.

--- src/download.c.orig	2014-12-24 17:59:14.000000000 +0000
+++ src/download.c
@@ -21,6 +21,7 @@
 
 #include <sys/time.h>
 #include <unistd.h>
+#include <netdb.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
