$NetBSD$

Inlcude missing system header files.

--- refile.c.orig	2008-11-28 19:48:24.000000000 +0000
+++ refile.c
@@ -36,6 +36,8 @@ static char XRNrcsid[] = "$Id: refile.c 
 
 #include "config.h"
 #include "utils.h"
+#include <stdlib.h>
+#include <unistd.h>
 #include <ctype.h>
 #if defined(SYSV) || defined(SVR4)
 #include <fcntl.h>
