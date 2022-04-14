$NetBSD$

--- cmake/FindGSSAPI.cmake.orig	2022-04-13 15:36:33.886229291 +0000
+++ cmake/FindGSSAPI.cmake
@@ -13,7 +13,8 @@ find_library(GSSAPI_LIBRARIES
              NAMES
              GSS # framework
              gss # solaris
-             gssapi_krb5
+             gssapi # heimdal
+             gssapi_krb5 # mit krb5
              HINTS ${PC_GSSAPI_LIBDIR}
 )
 
