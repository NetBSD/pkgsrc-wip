$NetBSD$

Remove complex.h to fix build.
https://github.com/opencv/opencv/pull/29455

--- modules/core/src/hal_internal.cpp.orig	2026-06-05 18:50:05.000000000 +0000
+++ modules/core/src/hal_internal.cpp
@@ -47,7 +47,6 @@
 
 #ifdef HAVE_LAPACK
 
-#include <complex.h>
 #include "opencv_lapack.h"
 
 #include <cmath>
