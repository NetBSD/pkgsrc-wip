$NetBSD$

	Make logdir absolute (XXX really needed?)
	Add setting of NDMP feature

--- core/cmake/BareosSetVariableDefaults.cmake.orig	2019-02-13 14:25:55.000000000 +0000
+++ core/cmake/BareosSetVariableDefaults.cmake
@@ -231,7 +231,7 @@ ELSE() # IF (${CMAKE_SYSTEM_NAME} MATCHE
 
   # logdir
   IF(NOT DEFINED logdir)
-    set(logdir "${CMAKE_INSTALL_LOCALSTATEDIR}/log/${CMAKE_PROJECT_NAME}")
+    set(logdir "/${CMAKE_INSTALL_LOCALSTATEDIR}/log/${CMAKE_PROJECT_NAME}")
   ENDIF()
 
   # datarootdir
@@ -438,6 +438,9 @@ ENDIF()
 # ndmp
 IF(NOT DEFINED ndmp)
    SET(ndmp ON)
+   SET(HAVE_NDMP 1)
+ELSE()
+   SET(HAVE_NDMP 0)
 ENDIF()
 
 # ipv6
