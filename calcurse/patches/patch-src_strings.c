$NetBSD$

--- src/strings.c.orig	2017-01-12 07:38:27.000000000 +0000
+++ src/strings.c
@@ -35,6 +35,7 @@
  */
 
 #include "calcurse.h"
+#include <stdarg.h>
 
 #define STRING_INITIAL_BUFSIZE 128
 
