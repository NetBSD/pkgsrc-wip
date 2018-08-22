$NetBSD$

Inlcude missing system header file.
Don't declare own errno.

--- internals.c.orig	2008-11-28 19:48:24.000000000 +0000
+++ internals.c
@@ -36,6 +36,7 @@ static char XRNrcsid[] = "$Id: internals
 #include "copyright.h"
 #include "config.h"
 #include "utils.h"
+#include <stdlib.h>
 #include <X11/Xos.h>
 #include <errno.h>
 #include <assert.h>
@@ -142,7 +143,6 @@ void checkLock()
     char myhost[64];
     int pid;
     FILE *fp;
-    extern int errno;
 
     if (!buffer) {
 	/* silently ignore this condition */
