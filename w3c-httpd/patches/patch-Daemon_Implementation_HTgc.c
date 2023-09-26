$NetBSD$

In NetBSD it's dirent.

--- Daemon/Implementation/HTgc.c.orig	1994-07-12 14:52:08.000000000 +0000
+++ Daemon/Implementation/HTgc.c
@@ -13,6 +13,9 @@
 **
 */
 
+#include <dirent.h>
+#define STRUCT_DIRENT struct dirent
+
 #include <string.h>
 #include <stdio.h>
 #ifdef VMS
