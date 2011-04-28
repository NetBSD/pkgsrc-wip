$NetBSD: patch-skia_skia.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- skia/skia.gyp.orig	2011-04-13 08:01:18.000000000 +0000
+++ skia/skia.gyp
@@ -668,7 +668,7 @@
             ['exclude', '_mac\\.(cc|cpp|mm?)$'],
             ['exclude', '/mac/'] ],
         }],
-        [ 'OS != "linux" and OS != "freebsd" and OS != "openbsd" and OS != "solaris"', {
+        [ 'OS != "linux" and OS != "dragonfly" and OS != "freebsd" and OS != "netbsd" and OS != "openbsd" and OS != "solaris"', {
           'sources/': [ ['exclude', '_(linux|gtk)\\.(cc|cpp)$'] ],
           'sources!': [
             '../third_party/skia/src/ports/SkFontHost_FreeType.cpp',
@@ -704,7 +704,7 @@
             'SK_RESTRICT=',
           ],
         }],
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd" or OS == "solaris"', {
           'dependencies': [
             '../build/linux/system.gyp:gdk',
             '../build/linux/system.gyp:fontconfig',
@@ -808,7 +808,7 @@
         '../third_party/skia/src/core',
       ],
       'conditions': [
-        [ '(OS == "linux" or OS == "freebsd" or OS == "openbsd") and target_arch != "arm"', {
+        [ '(OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd") and target_arch != "arm"', {
           'cflags': [
             '-msse2',
           ],
