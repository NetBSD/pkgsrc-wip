$NetBSD: patch-relay_control.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for _exit(2).

--- relay/control.c.orig	1994-09-08 19:42:09.000000000 +0000
+++ relay/control.c
@@ -26,6 +26,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <ctype.h>
 #include <string.h>
 #include <errno.h>
