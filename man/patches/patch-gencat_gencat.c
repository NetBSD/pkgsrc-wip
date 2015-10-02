$NetBSD$

--- gencat/gencat.c.orig	2006-08-02 18:11:44.000000000 +0000
+++ gencat/gencat.c
@@ -43,7 +43,7 @@ up-to-date.  Many thanks.
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
-#ifdef SYSV
+#if defined(SYSV) || defined(__sun)
 #include <sys/fcntl.h>
 #include <string.h>
 #else
