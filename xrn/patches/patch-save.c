$NetBSD$

Don't declare own errno.

--- save.c.orig	2008-11-28 19:48:24.000000000 +0000
+++ save.c
@@ -50,8 +50,6 @@ static char XRNrcsid[] = "$Id: save.c 23
 #include "refile.h"
 #include "file_cache.h"
 
-extern int errno;
-
 #define BUFFER_SIZE 1024
 
 #ifndef S_ISDIR
