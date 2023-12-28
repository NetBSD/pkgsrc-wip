$NetBSD$

Also search PKGSRC include directories.

--- cmake/Findlibopenmpt.cmake.orig	2023-12-27 21:41:05.315007940 +0000
+++ cmake/Findlibopenmpt.cmake
@@ -5,6 +5,7 @@ find_path(LIBOPENMPT_INCLUDE_DIR DOC "Pa
 	/usr/local/include/
 	/usr/include/libopenmpt/
 	/usr/local/include/libopenmpt/
+	${PKGSRC_INCLUDE}/libopenmpt/
 	${EXTERNAL_INCLUDES_DIR}/libopenmpt/
 )
 mark_as_advanced(LIBOPENMPT_INCLUDE_DIR)
@@ -148,4 +149,4 @@ endif()
 if(NOT LIBOPENMPT_STATIC)
 	include(${CMAKE_ROOT}/Modules/FindPackageHandleStandardArgs.cmake)
 	find_package_handle_standard_args(libopenmpt REQUIRED_VARS LIBOPENMPT_LIBRARY LIBOPENMPT_INCLUDE_DIR)
-endif()
\ No newline at end of file
+endif()
