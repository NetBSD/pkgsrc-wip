$NetBSD$

* add a common system type for all platforms that support X11

* Fix ICC check, since CMAKE_C_COMPILER can include the whole path to the
  compiler icc|icl matches directory names that include icl or icc

* Fix QCC check for the same reason as the ICC check

--- cmake/QtPlatformSupport.cmake.orig	2021-01-26 18:29:22.000000000 +0000
+++ cmake/QtPlatformSupport.cmake
@@ -20,6 +20,8 @@ qt_set01(WASM CMAKE_SYSTEM_NAME STREQUAL
 
 qt_set01(BSD APPLE OR OPENBSD OR FREEBSD OR NETBSD)
 
+qt_set01(X11_PLATFORM LINUX OR HPUX OR OPENBSD OR FREEBSD OR NETBSD)
+
 qt_set01(WINRT WIN32 AND CMAKE_VS_PLATFORM_TOOSLET STREQUAL "winrt") # FIXME: How to identify this?
 
 qt_set01(IOS APPLE AND CMAKE_SYSTEM_NAME STREQUAL "iOS")
@@ -31,8 +33,8 @@ qt_set01(MACOS APPLE AND NOT UIKIT)
 qt_set01(GCC CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
 qt_set01(CLANG CMAKE_CXX_COMPILER_ID MATCHES "Clang")
 qt_set01(APPLECLANG CMAKE_CXX_COMPILER_ID MATCHES "AppleClang")
-qt_set01(ICC CMAKE_C_COMPILER MATCHES "icc|icl")
-qt_set01(QCC CMAKE_C_COMPILER MATCHES "qcc") # FIXME: How to identify this?
+qt_set01(ICC CMAKE_CXX_COMPILER_ID MATCHES "Intel")
+qt_set01(QCC CMAKE_CXX_COMPILER_ID STREQUAL "QCC")
 
 if(CMAKE_SIZEOF_VOID_P EQUAL 8)
     set(QT_64BIT TRUE)
