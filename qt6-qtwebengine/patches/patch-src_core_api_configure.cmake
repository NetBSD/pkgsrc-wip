$NetBSD$

--- src/core/api/configure.cmake.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/core/api/configure.cmake
@@ -11,6 +11,7 @@ if(NOT QT_CONFIGURE_RUNNING)
         pkg_check_modules(ALSA alsa IMPORTED_TARGET)
         pkg_check_modules(PULSEAUDIO libpulse>=0.9.10 libpulse-mainloop-glib)
         pkg_check_modules(XDAMAGE xdamage)
+        pkg_check_modules(SNDIO sndio)
         pkg_check_modules(POPPLER_CPP poppler-cpp IMPORTED_TARGET)
         pkg_check_modules(GBM gbm)
         pkg_check_modules(LIBVA libva>=1.14)
@@ -87,6 +88,11 @@ qt_feature("webengine-printing-and-pdf" 
     AUTODETECT NOT QT_FEATURE_webengine_embedded_build
     CONDITION TARGET Qt::PrintSupport AND QT_FEATURE_printer
 )
+qt_feature("webengine-system-sndio" PRIVATE
+    LABEL "Use sndio"
+    AUTODETECT UNIX
+    CONDITION SNDIO_FOUND
+)
 qt_feature("webengine-pepper-plugins" PRIVATE
     LABEL "Pepper Plugins"
     PURPOSE "Enables use of Pepper plugins."
@@ -219,7 +225,10 @@ qt_configure_add_summary_entry(
 )
 qt_configure_add_summary_entry(
     ARGS "webengine-system-pulseaudio"
-    CONDITION LINUX
+    CONDITION UNIX
+)
+qt_configure_add_summary_entry(
+    ARGS "webengine-system-sndio"
 )
 qt_configure_add_summary_entry(ARGS "webengine-v8-context-snapshot")
 qt_configure_add_summary_entry(ARGS "webenginedriver")
