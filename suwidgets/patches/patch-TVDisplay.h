$NetBSD$

Fix C++ compilation.

--- TVDisplay.h.orig	2021-06-16 10:30:19.000000000 +0000
+++ TVDisplay.h
@@ -22,7 +22,7 @@
 #include <QFrame>
 
 #include <cmath>
-#include <complex.h>
+#include <complex>
 #include <vector>
 #include <tgmath.h>
 #include <sigutils/types.h>
