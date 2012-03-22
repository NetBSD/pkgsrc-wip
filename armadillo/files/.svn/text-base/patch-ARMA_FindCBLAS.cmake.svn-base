--- ARMA_FindCBLAS.cmake.orig	2011-08-14 10:06:31.000000000 -0500
+++ ARMA_FindCBLAS.cmake	2011-08-14 10:07:46.000000000 -0500
@@ -7,16 +7,13 @@
 #  CBLAS_LIBRARY, where to find the library.
 
 FIND_PATH(CBLAS_INCLUDE_DIR cblas.h
-/usr/include/atlas/
-/usr/local/include/atlas/
-/usr/include/
-/usr/local/include/
+/sharedapps/uwm/ceas/gcc-4.4.3/pkgsrc
 )
 
 SET(CBLAS_NAMES ${CBLAS_NAMES} cblas)
 FIND_LIBRARY(CBLAS_LIBRARY
   NAMES ${CBLAS_NAMES}
-  PATHS /usr/lib64/atlas /usr/lib/atlas /usr/local/lib64/atlas /usr/local/lib/atlas /usr/lib64 /usr/lib /usr/local/lib64 /usr/local/lib
+  PATHS /sharedapps/uwm/ceas/gcc-4.4.3/pkgsrc
   )
 
 IF (CBLAS_LIBRARY AND CBLAS_INCLUDE_DIR)
