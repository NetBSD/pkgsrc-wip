$NetBSD$

--- generic/itk.h.orig	2016-02-16 19:44:44.000000000 +0000
+++ generic/itk.h
@@ -76,7 +76,7 @@
 #ifndef RC_INVOKED
 
 #include "tk.h"
-#include "itclInt.h"
+#include "itcl3/itclInt.h"
 
 #undef TCL_STORAGE_CLASS
 #ifdef BUILD_itk
