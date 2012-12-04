$NetBSD: patch-bottom.c,v 1.1 2012/12/04 01:29:38 othyro Exp $

Needs strstr and strchr.

--- bottom.c.orig	2003-10-14 07:54:07.000000000 +0000
+++ bottom.c
@@ -3,6 +3,7 @@
 #include <stdint.h>
 #include <time.h>
 #include <unistd.h>
+#include <string.h>
 
 typedef struct 
 {
