$NetBSD$

Don't link to lcms2 in the pkgconfig file when
using shared linking only link to it when using
static linking.
From upstream:
https://github.com/libjxl/libjxl/pull/3045

--- lib/jxl_cms.cmake.orig	2024-01-05 18:01:47.652697091 +0000
+++ lib/jxl_cms.cmake
@@ -23,14 +23,14 @@ generate_export_header(jxl_cms
 target_include_directories(jxl_cms PUBLIC
   "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>")
 
-set(JXL_CMS_PK_LIBS "")
+set(JPEGXL_CMS_LIBRARY_REQUIRES "")
 
 if (JPEGXL_ENABLE_SKCMS)
   target_link_libraries(jxl_cms PRIVATE skcms)
 else()
   target_link_libraries(jxl_cms PRIVATE lcms2)
   if (JPEGXL_FORCE_SYSTEM_LCMS2)
-    set(JXL_CMS_PK_LIBS "-llcms2")
+    set(JPEGXL_CMS_LIBRARY_REQUIRES "lcms2")
   endif()
 endif()
 
@@ -63,7 +63,6 @@ else()
   set(JPEGXL_REQUIRES_TYPE "Requires")
 endif()
 
-set(JPEGXL_CMS_LIBRARY_REQUIRES "")
 configure_file("${CMAKE_CURRENT_SOURCE_DIR}/jxl/libjxl_cms.pc.in"
                "libjxl_cms.pc" @ONLY)
 install(FILES "${CMAKE_CURRENT_BINARY_DIR}/libjxl_cms.pc"
