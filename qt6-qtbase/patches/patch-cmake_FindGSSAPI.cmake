$NetBSD$

* look for gss as used on Solaris

* look for heimdals gssapi implementation as well
  fixes build where KRB5_TYPE = heimdal, see mk/krb5.buildlink3.mk

--- cmake/FindGSSAPI.cmake.orig	2021-09-23 07:42:06.000000000 +0000
+++ cmake/FindGSSAPI.cmake
@@ -1,16 +1,20 @@
 find_package(PkgConfig QUIET)
-pkg_check_modules(PC_GSSAPI QUIET krb5-gssapi)
+pkg_check_modules(PC_GSSAPI QUIET heimdal-gssapi krb5-gssapi)
 
 find_path(GSSAPI_INCLUDE_DIRS
           NAMES gssapi/gssapi.h
           HINTS ${PC_GSSAPI_INCLUDEDIR}
-          PATH_SUFFIXES gssapi)
+          PATH_SUFFIXES
+          gssapi
+          krb5 #heimdal
+)
 
 find_library(GSSAPI_LIBRARIES
              NAMES
              GSS # framework
              gss # solaris
-             gssapi_krb5
+             gssapi # heimdal
+             gssapi_krb5 # mit krb5
              HINTS ${PC_GSSAPILIBDIR}
 )
 
