$NetBSD$

- include strings.h for strcasecmp(3) on NetBSD

--- pinentry/pinentry.c.orig	2020-05-23 11:50:06.000000000 +0000
+++ pinentry/pinentry.c
@@ -19,6 +19,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <unistd.h>
 #include <assert.h>
 
