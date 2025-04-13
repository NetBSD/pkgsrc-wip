$NetBSD$

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- configure.cmake.orig	2024-11-21 04:36:37.000000000 +0000
+++ configure.cmake
@@ -73,7 +73,7 @@ if(Python3_EXECUTABLE)
 endif()
 
 #### Tests
-if(LINUX)
+if(UNIX)
    check_for_ulimit()
 endif()
 
@@ -434,7 +434,7 @@ qt_feature("webengine-system-libpci" PRI
 
 qt_feature("webengine-ozone-x11" PRIVATE
     LABEL "Support X11 on qpa-xcb"
-    CONDITION LINUX
+    CONDITION UNIX
         AND TARGET Qt::Gui
         AND QT_FEATURE_xcb
         AND X11_FOUND
@@ -474,12 +474,12 @@ assertTargets(
 )
 add_check_for_support(
    MODULES QtWebEngine
-   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS
+   CONDITION UNIX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS
    MESSAGE "Build can be done only on Linux, Windows or macOS."
 )
 add_check_for_support(
    MODULES QtPdf
-   CONDITION LINUX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR IOS OR ANDROID
+   CONDITION UNIX OR (WIN32 AND NOT WIN_ARM_64) OR MACOS OR IOS OR ANDROID
    MESSAGE "Build can be done only on Linux, Windows, macO, iOS and Android."
 )
 if(LINUX AND CMAKE_CROSSCOMPILING)
@@ -503,7 +503,7 @@ add_check_for_support(
 )
 add_check_for_support(
     MODULES QtWebEngine
-    CONDITION NOT (Nodejs_ARCH STREQUAL "ia32") AND
+    CONDITION NOT (Nodejs_ARCH STREQUAL "i386") AND
               NOT (Nodejs_ARCH STREQUAL "x86") AND
               NOT (Nodejs_ARCH STREQUAL "arm")
     MESSAGE "32bit version of Nodejs is not supported."
@@ -535,7 +535,7 @@ add_check_for_support(
 )
 add_check_for_support(
    MODULES QtWebEngine QtPdf
-   CONDITION NOT LINUX OR PkgConfig_FOUND
+   CONDITION NOT UNIX OR PkgConfig_FOUND
    MESSAGE "A pkg-config support is required."
 )
 add_check_for_support(
@@ -550,30 +550,30 @@ add_check_for_support(
 )
 add_check_for_support(
    MODULES QtWebEngine
-   CONDITION NOT LINUX OR FONTCONFIG_FOUND
+   CONDITION NOT UNIX OR FONTCONFIG_FOUND
    MESSAGE "Build requires fontconfig."
 )
 add_check_for_support(
    MODULES QtWebEngine
-   CONDITION NOT LINUX OR NSS_FOUND
+   CONDITION NOT UNIX OR NSS_FOUND
    MESSAGE "Build requires nss >= 3.26."
 )
 add_check_for_support(
    MODULES QtWebEngine
-   CONDITION NOT LINUX OR DBUS_FOUND
+   CONDITION NOT UNIX OR DBUS_FOUND
    MESSAGE "Build requires dbus."
 )
 add_check_for_support(
     MODULES QtWebEngine
-    CONDITION NOT LINUX OR NOT QT_FEATURE_webengine_system_ffmpeg OR TEST_libavformat
+    CONDITION NOT UNIX OR NOT QT_FEATURE_webengine_system_ffmpeg OR TEST_libavformat
     MESSAGE "Unmodified ffmpeg >= 5.0 is not supported."
 )
 
 add_check_for_support(
    MODULES QtWebEngine
    CONDITION MSVC OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
+       (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
+       (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
        (MACOS AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    MESSAGE
        "${CMAKE_CXX_COMPILER_ID} compiler is not supported."
@@ -582,8 +582,8 @@ add_check_for_support(
 add_check_for_support(
    MODULES QtPdf
    CONDITION MSVC OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
-       (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
+       (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
+       (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
        (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang") OR
        (ANDROID AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
        (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
