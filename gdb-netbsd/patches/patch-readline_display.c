$NetBSD$

--- readline/display.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ readline/display.c
@@ -47,6 +47,7 @@
 
 /* System-specific feature definitions and include files. */
 #include "rldefs.h"
+#include "rltty.h"
 #include "rlmbutil.h"
 
 /* Termcap library stuff. */
