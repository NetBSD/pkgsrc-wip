$NetBSD$

--- third_party/mesa/src/src/mesa/main/arrayobj.c.orig	2016-06-24 01:03:55.000000000 +0000
+++ third_party/mesa/src/src/mesa/main/arrayobj.c
@@ -52,6 +52,10 @@
 #include "varray.h"
 #include "main/dispatch.h"
 
+#if defined(__NetBSD__)
+#include <sys/bitops.h>
+#define ffsll ffs64
+#endif
 
 /**
  * Look up the array object for the given ID.
