$NetBSD$

Baskport patch from TCL 8.6.

--- src/other/tcl/generic/tclInt.h.orig	2016-08-09 06:47:11.000000000 +0000
+++ src/other/tcl/generic/tclInt.h
@@ -40,21 +40,9 @@
 #include <stdio.h>
 
 #include <ctype.h>
-#ifdef NO_STDLIB_H
-#   include "../compat/stdlib.h"
-#else
-#   include <stdlib.h>
-#endif
-#ifdef NO_STRING_H
-#include "../compat/string.h"
-#else
+#include <stdlib.h>
 #include <string.h>
-#endif
-#ifdef STDC_HEADERS
 #include <stddef.h>
-#else
-typedef int ptrdiff_t;
-#endif
 
 /*
  * Ensure WORDS_BIGENDIAN is defined correctly:
