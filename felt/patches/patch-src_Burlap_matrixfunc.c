$NetBSD: patch-src_Burlap_matrixfunc.c,v 1.1 2014/12/09 02:39:21 makoto Exp $

Fix readline use. Add missing include while here.

--- src/Burlap/matrixfunc.c.orig	2014-04-19 13:21:40.000000000 +0000
+++ src/Burlap/matrixfunc.c
@@ -25,6 +25,7 @@
  ************************************************************************/
 
 # include <math.h>
+# include <string.h>
 # include <time.h>
 # include "debug.h"
 # include "error.h"
