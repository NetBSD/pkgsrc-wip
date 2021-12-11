$NetBSD$

Fix C++ compilation.

--- sigutils/types.h.orig	2021-11-21 19:52:52.000000000 +0000
+++ sigutils/types.h
@@ -28,7 +28,11 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <math.h>
+#if defined(__cplusplus)
+#include <complex>
+#else
 #include <complex.h>
+#endif
 #include <fftw3.h>
 
 #include <util.h>
