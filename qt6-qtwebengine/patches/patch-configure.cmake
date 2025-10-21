$NetBSD$

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- configure.cmake.orig	2025-08-18 00:53:11.000000000 +0000
+++ configure.cmake
@@ -105,7 +105,7 @@ endif()
 
 #### Tests
 
-if(LINUX)
+if(UNIX)
    qt_webengine_configure_check_for_ulimit()
 endif()
 
@@ -291,16 +291,16 @@ unset(targets_to_check)
 
 qt_webengine_configure_check("supported-platform"
     MODULES QtWebEngine
-    CONDITION LINUX OR WIN32 OR MACOS
+    CONDITION UNIX OR WIN32 OR MACOS
     MESSAGE "Build can be done only on Linux, Windows or macOS."
 )
 qt_webengine_configure_check("supported-platform"
     MODULES QtPdf
-    CONDITION LINUX OR WIN32 OR MACOS OR IOS OR ANDROID
+    CONDITION UNIX OR WIN32 OR MACOS OR IOS OR ANDROID
     MESSAGE "Build can be done only on Linux, Windows, macO, iOS and Android."
 )
 
-if(LINUX AND CMAKE_CROSSCOMPILING)
+if(UNIX AND CMAKE_CROSSCOMPILING)
     set(supported_targets "arm" "arm64" "armv7-a" "x86_64")
     qt_webengine_configure_check("supported-arch"
         MODULES QtWebEngine QtPdf
@@ -364,7 +364,7 @@ qt_webengine_configure_check("flex"
 )
 qt_webengine_configure_check("pkg-config"
     MODULES QtWebEngine QtPdf
-    CONDITION NOT LINUX OR PkgConfig_FOUND
+    CONDITION NOT UNIX OR PkgConfig_FOUND
     MESSAGE "A pkg-config support is required."
     DOCUMENTATION "A pkg-config binary on Linux."
     TAGS LINUX_PLATFORM
@@ -394,28 +394,28 @@ qt_webengine_configure_check("harfbuzz"
 )
 qt_webengine_configure_check("mesa-headers"
     MODULES QtWebEngine
-    CONDITION NOT LINUX OR TEST_khr
+    CONDITION NOT UNIX OR TEST_khr
     MESSAGE "Build requires Khronos development headers for build - see mesa/libegl1-mesa-dev"
     DOCUMENTATION "Mesa development headers."
     TAGS LINUX_PLATFORM
 )
 qt_webengine_configure_check("fontconfig"
     MODULES QtWebEngine
-    CONDITION NOT LINUX OR FONTCONFIG_FOUND
+    CONDITION NOT UNIX OR FONTCONFIG_FOUND
     MESSAGE "Build requires fontconfig."
     DOCUMENTATION "Fontconfig"
     TAGS LINUX_PKG_CONFIG
 )
 qt_webengine_configure_check("nss"
     MODULES QtWebEngine
-    CONDITION NOT LINUX OR NSS_FOUND
+    CONDITION NOT UNIX OR NSS_FOUND
     MESSAGE "Build requires nss >= ${QT_CONFIGURE_CHECK_nss_version}."
     DOCUMENTATION "Nss library are least ${QT_CONFIGURE_CHECK_nss_version} version."
     TAGS LINUX_PLATFORM
 )
 qt_webengine_configure_check("dbus"
     MODULES QtWebEngine
-    CONDITION NOT LINUX OR DBUS_FOUND
+    CONDITION NOT UNIX OR DBUS_FOUND
     MESSAGE "Build requires dbus."
     DOCUMENTATION "Dbus"
     TAGS LINUX_PKG_CONFIG
@@ -437,7 +437,7 @@ foreach(x_lib ${x_libs})
     string(TOLOWER ${x_lib} x)
     qt_webengine_configure_check("${x}"
         MODULES QtWebEngine
-        CONDITION NOT TARGET Qt6::Gui OR NOT LINUX OR NOT QT_FEATURE_xcb OR ${x_lib}_FOUND
+        CONDITION NOT TARGET Qt6::Gui OR NOT UNIX OR NOT QT_FEATURE_xcb OR ${x_lib}_FOUND
         MESSAGE "Could not find ${x} library for qpa-xcb support."
         DOCUMENTATION "${x}"
         TAGS LINUX_XCB
@@ -453,8 +453,8 @@ unset(x_libs)
 qt_webengine_configure_check("compiler"
     MODULES QtWebEngine
     CONDITION MSVC OR
-        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
-        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
+        (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
+        (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
         (MACOS AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
     MESSAGE
         "${CMAKE_CXX_COMPILER_ID} compiler is not supported."
@@ -462,8 +462,8 @@ qt_webengine_configure_check("compiler"
 qt_webengine_configure_check("compiler"
     MODULES QtPdf
     CONDITION MSVC OR
-        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
-        (LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
+        (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
+        (UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
         (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang") OR
         (ANDROID AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang") OR
         (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR
@@ -495,7 +495,7 @@ qt_webengine_configure_check("msvc-2022"
 
 qt_webengine_configure_check("gcc"
     MODULES QtWebEngine
-    CONDITION NOT (LINUX OR MINGW) OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
+    CONDITION NOT (UNIX OR MINGW) OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
               NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${QT_CONFIGURE_CHECK_gcc_version}
     MESSAGE "GCC version must be at least ${QT_CONFIGURE_CHECK_gcc_version}"
     DOCUMENTATION "GCC version must be at least ${QT_CONFIGURE_CHECK_gcc_version}"
@@ -504,7 +504,7 @@ qt_webengine_configure_check("gcc"
 
 qt_webengine_configure_check("gcc-pdf"
     MODULES QtPdf
-    CONDITION NOT (LINUX OR MINGW) OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
+    CONDITION NOT (UNIX OR MINGW) OR NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
               NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${QT_CONFIGURE_CHECK_gcc-pdf_version}
     MESSAGE "GCC version must be at least ${QT_CONFIGURE_CHECK_gcc-pdf_version}"
     DOCUMENTATION "GCC version must be at least ${QT_CONFIGURE_CHECK_gcc-pdf_version}"
@@ -725,7 +725,7 @@ qt_feature("webengine-system-libudev" PR
 
 qt_feature("webengine-ozone-x11" PRIVATE
     LABEL "Support X11 on qpa-xcb"
-    CONDITION LINUX
+    CONDITION UNIX
         AND TARGET Qt::Gui
         AND QT_FEATURE_xcb
         AND qpa_xcb_support_check
