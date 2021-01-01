$NetBSD$

Add definition for usleep

--- src/ComTerp/ctrlfunc.c.orig	2013-02-13 17:57:54.000000000 +0900
+++ src/ComTerp/ctrlfunc.c	2021-01-01 21:47:50.772502505 +0900
@@ -22,6 +22,7 @@
  * 
  */
 
+#include "unistd.h"
 #include <fstream.h>
 #include <iostream>
 #include <ComTerp/comhandler.h>
