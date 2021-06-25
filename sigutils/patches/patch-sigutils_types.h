$NetBSD$

Fix C++ compilation.

--- sigutils/types.h.orig	2021-04-06 15:35:35.000000000 +0000
+++ sigutils/types.h
@@ -27,7 +27,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
+#if defined(__cplusplus)
+#include <complex>
+#else
 #include <complex.h>
+#endif
 #include <fftw3.h>
 
 #include <util.h>
