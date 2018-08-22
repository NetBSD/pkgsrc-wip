$NetBSD$

Don't declare own errno.

--- server.c.orig	2009-03-02 15:12:09.000000000 +0000
+++ server.c
@@ -70,8 +70,6 @@ static char XRNrcsid[] = "$Id: server.c 
 #include <vfork.h>
 #endif
 
-extern int errno;
-
 #define BUFFER_SIZE 1024
 /* This constant must be a 2^x times BUFFER_SIZE, for some x. */
 #define MAX_BUFFER_SIZE (8*BUFFER_SIZE)
