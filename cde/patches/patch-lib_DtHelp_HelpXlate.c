$NetBSD: patch-lib_DtHelp_HelpXlate.c,v 1.1 2014/07/27 07:44:56 obache Exp $

* <time.h> is required for time(3)

--- lib/DtHelp/HelpXlate.c.orig	2014-03-01 22:48:49.000000000 +0000
+++ lib/DtHelp/HelpXlate.c
@@ -39,6 +39,7 @@ $END$
 #include <stdlib.h>
 #include <string.h>
 #include <sys/param.h>        /* MAXPATHLEN */
+#include <time.h>
 
 /* for Xrm */
 #include <X11/Intrinsic.h>
