$NetBSD$

Inlcude missing system header file.

--- resources.c.orig	2008-11-28 19:48:24.000000000 +0000
+++ resources.c
@@ -34,6 +34,7 @@ static char XRNrcsid[] = "$Id: resources
 #include "copyright.h"
 #include "config.h"
 #include "utils.h"
+#include <stdlib.h>
 #include <X11/Xos.h>
 #ifdef MOTIF
 # include <Xm/Xm.h>
