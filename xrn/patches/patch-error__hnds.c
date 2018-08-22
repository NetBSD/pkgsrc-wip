$NetBSD$

Inlcude missing system header file.

--- error_hnds.c.orig	2008-11-28 19:48:24.000000000 +0000
+++ error_hnds.c
@@ -36,6 +36,7 @@ static char XRNrcsid[] = "$Id: error_hnd
 #include "copyright.h"
 #include "config.h"
 #include "utils.h"
+#include <stdlib.h>
 #include <X11/Xos.h>
 #include <signal.h>
 #include <X11/Intrinsic.h>
