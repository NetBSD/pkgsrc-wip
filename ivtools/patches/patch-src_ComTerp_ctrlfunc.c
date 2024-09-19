$NetBSD$

Add definition for usleep

--- src/ComTerp/ctrlfunc.c.orig	2013-02-13 17:57:54.000000000 +0900
+++ src/ComTerp/ctrlfunc.c	2021-01-02 23:01:38.296553409 +0900
@@ -22,6 +22,7 @@
  * 
  */
 
+#include "unistd.h"
 #include <fstream.h>
 #include <iostream>
 #include <ComTerp/comhandler.h>
