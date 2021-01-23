$NetBSD$

Use the correct header for alloca(3) on NetBSD.

--- w_wad.c.orig	2021-01-04 15:51:51.000000000 +0000
+++ w_wad.c
@@ -17,7 +17,11 @@ along with this program.  If not, see <h
 */
 // W_wad.c
 
+#ifdef __NetBSD__
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <fcntl.h>
