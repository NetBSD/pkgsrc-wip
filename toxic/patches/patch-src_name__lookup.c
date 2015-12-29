$NetBSD$

Include stdarg.h.

--- src/name_lookup.c.orig	2015-12-26 05:56:46.000000000 +0000
+++ src/name_lookup.c
@@ -21,6 +21,7 @@
  */
 
 #include <stdlib.h>
+#include <stdarg.h>
 #include <string.h>
 #include <sys/types.h> /* for u_char */
 #include <curl/curl.h>
