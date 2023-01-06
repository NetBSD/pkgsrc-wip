$NetBSD$

Provide a declaration of exit() 

--- xdrestore/xtmRestore.c.orig	1997-05-04 22:02:14.000000000 +0000
+++ xdrestore/xtmRestore.c
@@ -37,6 +37,7 @@ static char SCCSID[] = "@(#) Module: xtm
 ----------------------------------------------------------------------------*/
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #include <ctype.h>
