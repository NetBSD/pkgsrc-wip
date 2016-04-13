$NetBSD$

Include memrchr for platforms that don't have it.

--- egg/egg-armor.c.orig	2014-09-23 07:40:08.000000000 +0000
+++ egg/egg-armor.c
@@ -33,6 +33,10 @@
 #include <ctype.h>
 #include <string.h>
 
+#ifndef HAVE_MEMRCHR
+#include "memrchr.c"
+#endif
+
 /*
  * Armor looks like:
  *
