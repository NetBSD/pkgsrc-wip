$NetBSD$

--- src/pins-lib/modules/opaal-pins.c.orig	2018-07-03 19:28:10.000000000 +0000
+++ src/pins-lib/modules/opaal-pins.c
@@ -6,6 +6,7 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 #include <unistd.h>
 
 #include <dm/dm.h>
