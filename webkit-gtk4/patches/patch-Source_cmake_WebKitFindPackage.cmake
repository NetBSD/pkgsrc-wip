$NetBSD$

--- Source/cmake/WebKitFindPackage.cmake.orig	2020-08-12 09:17:57.000000000 +0000
+++ Source/cmake/WebKitFindPackage.cmake
@@ -85,21 +85,6 @@ macro(find_package package)
         endif ()
     endif ()
 
-    # Apple builds have a unique location for ICU
-    if (APPLE AND "${package}" STREQUAL "ICU")
-        set(_found_package ON)
-
-        set(ICU_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/ICU/Headers)
-
-        # Apple just has a single dylib for ICU
-        set(ICU_I18N_LIBRARY /usr/lib/libicucore.dylib)
-        set(ICU_UC_LIBRARY /usr/lib/libicucore.dylib)
-        set(ICU_DATA_LIBRARY /usr/lib/libicucore.dylib)
-
-        set(ICU_LIBRARIES ${ICU_UC_LIBRARY})
-        set(ICU_FOUND ON)
-    endif ()
-
     if (NOT _found_package)
         _find_package(${ARGV})
     endif ()
