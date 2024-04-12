$NetBSD$

--- cupsfilters/filter.c.orig	2024-04-12 14:26:34.910553039 +0000
+++ cupsfilters/filter.c
@@ -19,6 +19,7 @@
 #include <errno.h>
 #include <signal.h>
 #include <sys/wait.h>
+#include <sys/stat.h>
 #include <cups/file.h>
 #include <cups/array.h>
 
