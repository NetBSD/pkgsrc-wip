$NetBSD$

--- src/modules/influxdbc/ic.c.orig	2025-05-12 21:48:07.116509675 +0000
+++ src/modules/influxdbc/ic.c
@@ -18,13 +18,13 @@
 
     Compile: cc ic.c -g -O3 -o ic
  */
+#include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <ctype.h>
 #include <math.h>
 #include <string.h>
-#include <sys/errno.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
