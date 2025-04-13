$NetBSD$

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches
  - add sndio

--- src/core/api/qt_cmdline.cmake.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/core/api/qt_cmdline.cmake
@@ -28,7 +28,7 @@ function(qt_commandline_jumbo arg val ne
 endfunction()
 
 set(systemLibs alsa ffmpeg freetype harfbuzz icu lcms2 libevent libjpeg
-    libpng libvpx libxml libwebp minizip opus pulseaudio re2 snappy zlib)
+    libpng libvpx libxml libwebp minizip opus pulseaudio re2 snappy sndio zlib)
 foreach(slib ${systemLibs})
     qt_commandline_option(webengine-${slib} TYPE enum NAME webengine-system-${slib} VALUES yes no system)
 endforeach()
