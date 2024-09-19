$NetBSD$
--- src/client.c.orig	2018-02-18 04:15:26.483034514 -0800
+++ src/client.c	2018-02-18 04:15:40.067922408 -0800
@@ -11,6 +11,8 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include "client.h"
 #include "tinycthread.h"
 
