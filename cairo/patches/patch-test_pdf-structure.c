$NetBSD$

Add header for WIFEXITED and WAITSTATUS.

--- test/pdf-structure.c.orig	2023-09-23 14:18:32.000000000 +0000
+++ test/pdf-structure.c
@@ -29,6 +29,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#include <sys/wait.h>
 
 #ifdef HAVE_UNISTD_H
 #include <unistd.h> /* __unix__ */
