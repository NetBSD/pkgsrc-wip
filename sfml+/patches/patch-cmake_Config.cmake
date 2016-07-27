$NetBSD$

--- cmake/Config.cmake.orig	2015-08-24 16:01:06.000000000 +0000
+++ cmake/Config.cmake
@@ -31,6 +31,10 @@ elseif(${CMAKE_SYSTEM_NAME} MATCHES "Fre
     set(SFML_OS_FREEBSD 1)
     # don't use the OpenGL ES implementation on FreeBSD
     set(OPENGL_ES 0)
+elseif(${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
+    set(SFML_OS_NETBSD 1)
+    # XXX we want to use OPENGL_ES for some NetBSD, but which?
+    set(OPENGL_ES 0)
 elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
     if(IOS)
         set(SFML_OS_IOS 1)
@@ -110,7 +114,7 @@ endif()
 # define the install directory for miscellaneous files
 if(SFML_OS_WINDOWS OR SFML_OS_IOS)
     set(INSTALL_MISC_DIR .)
-elseif(SFML_OS_LINUX OR SFML_OS_FREEBSD OR SFML_OS_MACOSX)
+elseif(SFML_OS_LINUX OR SFML_OS_FREEBSD OR SFML_OS_NETBSD OR SFML_OS_MACOSX)
     set(INSTALL_MISC_DIR share/SFML)
 elseif(SFML_OS_ANDROID)
     set(INSTALL_MISC_DIR ${ANDROID_NDK}/sources/sfml)
