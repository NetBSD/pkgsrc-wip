--- ARMA_FindLAPACK.cmake.orig	2011-08-14 10:04:05.000000000 -0500
+++ ARMA_FindLAPACK.cmake	2011-08-14 10:05:20.000000000 -0500
@@ -8,7 +8,7 @@
 SET(LAPACK_NAMES ${LAPACK_NAMES} lapack)
 FIND_LIBRARY(LAPACK_LIBRARY
   NAMES ${LAPACK_NAMES}
-  PATHS /usr/lib64/atlas /usr/lib/atlas /usr/lib64 /usr/lib /usr/local/lib64 /usr/local/lib
+  PATHS /sharedapps/uwm/ceas/gcc-4.4.3/pkgsrc-v2/lib
   )
 
 IF (LAPACK_LIBRARY)
