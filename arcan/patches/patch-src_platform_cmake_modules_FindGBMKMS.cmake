$NetBSD$

Tolerate /usr/X11R7
XXX pkgconfig would be good to add, too.

--- src/platform/cmake/modules/FindGBMKMS.cmake.orig	2018-12-10 23:33:36.000000000 +0000
+++ src/platform/cmake/modules/FindGBMKMS.cmake
@@ -9,6 +9,7 @@ find_path(DRM_INCLUDE_DIR drm.h
     /usr/include/libdrm
     /usr/include/drm
     /usr/X11R6/include/libdrm
+    /usr/X11R7/include/libdrm
 )
 
 find_path(GBM_INCLUDE_DIR gbm.h
@@ -16,12 +17,14 @@ find_path(GBM_INCLUDE_DIR gbm.h
 		/usr/local/include
 		/usr/include
                 /usr/X11R6/include 
+		/usr/X11R7/include
 )
 
 set(GBMKMS_LIB_PATHS
 	/usr/local/lib
 	/usr/lib
 	/usr/X11R6/lib
+	/usr/X11R7/lib
 )
 
 find_library(GBMKMS_DRM_LIBRARY NAMES drm HINTS ${GBMKMS_LIB_PATHS} REQUIRED)
