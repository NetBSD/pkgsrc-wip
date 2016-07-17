$NetBSD$

--- third_party/ffmpeg/ffmpeg.gyp.orig	2016-06-24 01:03:39.000000000 +0000
+++ third_party/ffmpeg/ffmpeg.gyp
@@ -259,6 +259,15 @@
               'cflags!': [
                 '-fno-omit-frame-pointer',
               ],
+              # "Tomek" from freebsd-chromium@ figured this out, rene is
+              # puzzled why this is needed. Fixes runtime on FreeBSD < 10
+              'cflags_c': [
+                '-fomit-frame-pointer',
+              ],
+              'cflags_cc': [
+                '-fomit-frame-pointer',
+              ],
+              # back to upstream code
               'debug_extra_cflags!': [
                 '-fno-omit-frame-pointer',
               ],
