$NetBSD$

--- ui/gl/gl.gyp.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/gl/gl.gyp
@@ -130,7 +130,7 @@
         'trace_util.h',
       ],
       'conditions': [
-        ['OS in ("win", "android", "linux")', {
+        ['OS in ("win", "android", "linux", "freebsd", "openbsd")', {
           'sources': [
             'egl_util.cc',
             'egl_util.h',
@@ -151,7 +151,7 @@
             '<(DEPTH)/third_party/khronos',
         ],
         }],
-        ['OS in ("android", "linux")', {
+        ['OS in ("android", "linux", "freebsd", "openbsd")', {
           'sources': [
             'gl_implementation_osmesa.cc',
             'gl_implementation_osmesa.h',
