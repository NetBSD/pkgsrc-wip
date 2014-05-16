$NetBSD: patch-in.www_in.www.c,v 1.1 2014/05/16 15:19:19 hfath Exp $

--- in.www/in.www.c.orig	2011-01-13 15:53:56.000000000 +0000
+++ in.www/in.www.c
@@ -29,6 +29,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <string.h>
 #include <sys/stat.h>
 #include <dirent.h>
