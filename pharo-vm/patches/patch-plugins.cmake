$NetBSD$

use uuidgen(2)

--- plugins.cmake.orig	2021-08-13 21:08:15.000000000 +0000
+++ plugins.cmake
@@ -77,7 +77,7 @@ if(NOT OPENBSD)
     addLibraryWithRPATH(UUIDPlugin ${UUIDPlugin_SOURCES})
     if(WIN)
         target_link_libraries(UUIDPlugin PRIVATE "-lole32")
-    elseif(UNIX AND NOT OSX)
+    elseif(UNIX AND NOT OSX AND HAVE_UUID_GENENATE)
        #find_path(LIB_UUID_INCLUDE_DIR uuid.h PATH_SUFFIXES uuid)
         find_library(LIB_UUID_LIBRARY uuid)
         message(STATUS "Using uuid library:" ${LIB_UUID_LIBRARY})
