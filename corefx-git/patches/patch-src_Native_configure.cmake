$NetBSD$

--- src/Native/configure.cmake.orig	2016-05-03 12:05:51.000000000 +0000
+++ src/Native/configure.cmake
@@ -437,6 +437,14 @@ check_cxx_source_compiles(
     "
     HAVE_CURL_SSLVERSION_TLSv1_012)
 
+option(HeimdalGssApi "use heimdal implementation of GssApi" OFF)
+
+if (HeimdalGssApi)
+   check_include_files(
+       gssapi/gssapi.h
+       HAVE_HEIMDAL_HEADERS)
+endif()
+
 check_include_files(
     GSS/GSS.h
     HAVE_GSSFW_HEADERS)
