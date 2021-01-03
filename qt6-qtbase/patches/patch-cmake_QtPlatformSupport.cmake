$NetBSD$

* add a common system type for all platforms that support X11

--- cmake/QtPlatformSupport.cmake.orig	2020-12-04 10:14:27.000000000 +0000
+++ cmake/QtPlatformSupport.cmake
@@ -20,6 +20,8 @@ qt_set01(WASM CMAKE_SYSTEM_NAME STREQUAL
 
 qt_set01(BSD APPLE OR OPENBSD OR FREEBSD OR NETBSD)
 
+qt_set01(X11_PLATFORM LINUX OR HPUX OR OPENBSD OR FREEBSD OR NETBSD)
+
 qt_set01(WINRT WIN32 AND CMAKE_VS_PLATFORM_TOOSLET STREQUAL "winrt") # FIXME: How to identify this?
 
 qt_set01(IOS APPLE AND CMAKE_SYSTEM_NAME STREQUAL "iOS")
