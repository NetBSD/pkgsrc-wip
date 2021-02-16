$NetBSD$

* look for heimdals gssapi implementation as well
  fixes build where KRB5_TYPE = heimdal, see mk/krb5.buildlink3.mk

--- cmake/FindGSSAPI.cmake.orig	2021-02-15 21:57:24.639772681 +0000
+++ cmake/FindGSSAPI.cmake
@@ -1,15 +1,19 @@
 find_package(PkgConfig QUIET)
-pkg_check_modules(PC_GSSAPI QUIET krb5-gssapi)
+pkg_search_module(PC_GSSAPI QUIET krb5-gssapi heimdal-gssapi)
 
 find_path(GSSAPI_INCLUDE_DIRS
           NAMES gssapi/gssapi.h
           HINTS ${PC_GSSAPI_INCLUDEDIR}
-          PATH_SUFFIXES gssapi)
+          PATH_SUFFIXES 
+          gssapi
+          krb5 # heimdal
+)
 
 find_library(GSSAPI_LIBRARIES
              NAMES
              GSS # framework
-             gssapi_krb5
+             gssapi_krb5 # mit krb5
+             gssapi # heimdal
              HINTS ${PC_GSSAPILIBDIR}
 )
 
