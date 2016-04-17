$NetBSD$

--- src/Native/configure.cmake.orig	2016-04-09 19:53:47.000000000 +0000
+++ src/Native/configure.cmake
@@ -447,10 +447,13 @@ if (HAVE_GSSFW_HEADERS)
         "GSS/GSS.h"
         HAVE_GSS_SPNEGO_MECHANISM)
 else ()
+    find_path(LIBGSS_INCLUDE_DIR gssapi/gssapi_ext.h)
+    set(CMAKE_REQUIRED_INCLUDES ${LIBGSS_INCLUDE_DIR})
     check_symbol_exists(
         GSS_SPNEGO_MECHANISM
         "gssapi/gssapi.h"
         HAVE_GSS_SPNEGO_MECHANISM)
+    unset(CMAKE_REQUIRED_INCLUDES)
 endif ()
 
 set (CMAKE_REQUIRED_LIBRARIES)
