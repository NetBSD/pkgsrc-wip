$NetBSD$

stable_ptr_table undefined

--- ghc-6.4.2/ghc/includes/mkDerivedConstants.c.orig	2006-01-05 01:30:32.000000000 +0900
+++ ../ghc-6.4.2/ghc/includes/mkDerivedConstants.c	2019-10-06 22:13:40.076851104 +0900
@@ -20,6 +20,7 @@
 #include "Rts.h"
 #include "RtsFlags.h"
 #include "Storage.h"
+#include "Stable.h"
 
 #include <stdio.h>
 
