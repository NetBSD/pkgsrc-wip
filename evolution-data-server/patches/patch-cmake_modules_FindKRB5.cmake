$NetBSD$

Fix for build with heimdal krb5

--- cmake/modules/FindKRB5.cmake.orig	2024-12-14 11:23:50.707574499 +0000
+++ cmake/modules/FindKRB5.cmake
@@ -34,6 +34,14 @@ if(KRB5_FOUND)
 		return()
 	endif(KRB5_VENDOR STREQUAL "MIT")
 
+	if(KRB5_VENDOR STREQUAL "Heimdal")
+		message(STATUS "Using Heimdal KRB5 implementation (found by pkg-config)")
+		set(WITH_KRB5 ON)
+		set(HAVE_KRB5 ON)
+		set(HAVE_HEIMDAL_KRB5 ON)
+		return()
+	endif(KRB5_VENDOR STREQUAL "Heimdal")
+
 	message(STATUS "Found Kerberos 5 with pkg-config, but unknown vendor '${KRB5_VENDOR}', continue with autodetection")
 endif()
 
