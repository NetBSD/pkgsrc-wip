$NetBSD$

Fix warnings about prepocessor defined macros. 

--- xlax.c.orig	2008-07-31 20:18:25.000000000 +0000
+++ xlax.c
@@ -30,6 +30,7 @@
  *
  */
 
+#include "stddef.h"
 #include "xlax.h"
 #include "vroot.h"
 
