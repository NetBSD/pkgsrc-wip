$NetBSD$

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches
  - add sndio
  - add audioio

--- src/core/api/configure.cmake.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/core/api/configure.cmake
@@ -11,6 +11,7 @@ if(NOT QT_CONFIGURE_RUNNING)
         pkg_check_modules(ALSA alsa IMPORTED_TARGET)
         pkg_check_modules(PULSEAUDIO libpulse>=0.9.10 libpulse-mainloop-glib)
         pkg_check_modules(XDAMAGE xdamage)
+        pkg_check_modules(SNDIO sndio)
         pkg_check_modules(GBM gbm)
         pkg_check_modules(LIBVA libva>=1.14)
         if(NOT GIO_FOUND)
@@ -90,6 +91,16 @@ qt_feature("webengine-printing-and-pdf" 
     AUTODETECT NOT QT_FEATURE_webengine_embedded_build
     CONDITION TARGET Qt::PrintSupport AND QT_FEATURE_printer
 )
+qt_feature("webengine-system-sndio" PRIVATE
+    LABEL "Use sndio"
+    AUTODETECT UNIX
+    CONDITION SNDIO_FOUND
+)
+qt_feature("webengine-system-audioio" PRIVATE
+    LABEL "Use audioio"
+    AUTODETECT UNIX
+    CONDITION AUDIOIO_FOUND
+)
 qt_feature("webengine-pepper-plugins" PRIVATE
     LABEL "Pepper Plugins"
     PURPOSE "Enables use of Pepper plugins."
@@ -112,7 +123,7 @@ qt_feature("webengine-kerberos" PRIVATE
     LABEL "Kerberos Authentication"
     PURPOSE "Enables Kerberos Authentication Support"
     AUTODETECT WIN32
-    CONDITION NOT LINUX OR GSSAPI_FOUND
+    CONDITION NOT UNIX OR GSSAPI_FOUND
 )
 qt_feature("webengine-spellchecker" PUBLIC
     LABEL "Spellchecker"
@@ -122,7 +133,7 @@ qt_feature("webengine-native-spellchecke
     LABEL "Native Spellchecker"
     PURPOSE "Use the system's native spellchecking engine."
     AUTODETECT OFF
-    CONDITION QT_FEATURE_webengine_spellchecker AND NOT LINUX
+    CONDITION QT_FEATURE_webengine_spellchecker AND NOT UNIX
 )
 qt_feature("webengine-extensions" PUBLIC
     SECTION "WebEngine"
@@ -171,7 +182,7 @@ qt_feature("webengine-vaapi" PRIVATE
     PURPOSE "Enables support for VA-API hardware acceleration"
     AUTODETECT GBM_FOUND AND LIBVA_FOUND AND QT_FEATURE_vulkan
     # hardware accelerated encoding requires bundled libvpx
-    CONDITION LINUX AND NOT QT_FEATURE_webengine_system_libvpx
+    CONDITION UNIX AND NOT QT_FEATURE_webengine_system_libvpx
 )
 list(LENGTH CMAKE_OSX_ARCHITECTURES osx_arch_count)
 qt_feature("webenginedriver" PUBLIC
@@ -196,7 +207,7 @@ qt_configure_add_summary_entry(ARGS "web
 qt_configure_add_summary_entry(ARGS "webengine-spellchecker")
 qt_configure_add_summary_entry(
     ARGS "webengine-native-spellchecker"
-    CONDITION NOT LINUX
+    CONDITION NOT UNIX
 )
 qt_configure_add_summary_entry(ARGS "webengine-webrtc")
 qt_configure_add_summary_entry(ARGS "webengine-webrtc-pipewire")
@@ -214,15 +225,21 @@ qt_configure_add_summary_entry(
 )
 qt_configure_add_summary_entry(
     ARGS "webengine-vaapi"
-    CONDITION LINUX
+    CONDITION UNIX
 )
 qt_configure_add_summary_entry(
     ARGS "webengine-system-alsa"
-    CONDITION LINUX
+    CONDITION UNIX
 )
 qt_configure_add_summary_entry(
     ARGS "webengine-system-pulseaudio"
-    CONDITION LINUX
+    CONDITION UNIX
+)
+qt_configure_add_summary_entry(
+    ARGS "webengine-system-sndio"
+)
+qt_configure_add_summary_entry(
+    ARGS "webengine-system-audioio"
 )
 qt_configure_add_summary_entry(ARGS "webengine-v8-context-snapshot")
 qt_configure_add_summary_entry(ARGS "webenginedriver")
@@ -232,7 +249,7 @@ if(CMAKE_CROSSCOMPILING)
     qt_configure_add_report_entry(
         TYPE WARNING
         MESSAGE "Thumb instruction set is required to build ffmpeg for QtWebEngine."
-        CONDITION LINUX
+        CONDITION UNIX
             AND NOT QT_FEATURE_webengine_system_ffmpeg
             AND TEST_architecture_arch MATCHES arm
             AND NOT armThumb
@@ -251,5 +268,5 @@ qt_configure_add_report_entry(
 qt_configure_add_report_entry(
     TYPE WARNING
     MESSAGE "System GBM is disabled. The bundled minigbm supports Intel only, you might need to install libgbm to avoid rendering issues."
-    CONDITION LINUX AND NOT QT_FEATURE_webengine_system_gbm
+    CONDITION UNIX AND NOT QT_FEATURE_webengine_system_gbm
 )
