$NetBSD$

Add missing #include

--- in.proxy/in.proxy.c.orig	2013-04-26 20:00:11.000000000 +0000
+++ in.proxy/in.proxy.c
@@ -26,6 +26,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <string.h>
 #include <time.h>
 #include <netinet/in.h>
