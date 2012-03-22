--- ARMA_FindBLAS.cmake.orig	2011-08-14 10:03:54.000000000 -0500
+++ ARMA_FindBLAS.cmake	2011-08-14 10:04:43.000000000 -0500
@@ -8,7 +8,7 @@
 SET(BLAS_NAMES ${BLAS_NAMES} blas)
 FIND_LIBRARY(BLAS_LIBRARY
   NAMES ${BLAS_NAMES}
-  PATHS /usr/lib64/atlas /usr/lib/atlas /usr/lib64 /usr/lib /usr/local/lib64 /usr/local/lib
+  PATHS /sharedapps/uwm/ceas/gcc-4.4.3/pkgsrc-v2/lib
   )
 
 IF (BLAS_LIBRARY)
