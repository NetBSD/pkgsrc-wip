$NetBSD$

Add support for NetBSD and OpenBSD.

--- cmake/platforms.cmake.orig	2019-11-03 18:11:21.000000000 +0000
+++ cmake/platforms.cmake
@@ -17,6 +17,10 @@ ELSEIF(UNIX)
 
 	IF(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
 		INCLUDE(platform-freebsd)
+	ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
+		INCLUDE(platform-freebsd)
+	ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD")
+		INCLUDE(platform-freebsd)
 	ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
 		INCLUDE(platform-solaris)
 	ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
