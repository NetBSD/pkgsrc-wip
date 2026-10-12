$NetBSD$

AC_HEADER_STDC is obsolete, all pkgsrc supported platforms should
likely have them.

--- src/util.c.orig	2026-10-12 19:01:52.373251786 +0000
+++ src/util.c
@@ -37,10 +37,8 @@
 #include "config.h"
 #endif
 
-#ifdef STDC_HEADERS
 #include <stdio.h>
 #include <stdlib.h>
-#endif
 
 #ifdef HAVE_MEMORY_H
 #include <memory.h>
