$NetBSD$

--- third_party/khronos/khronos.gyp.orig	2016-06-24 01:02:48.000000000 +0000
+++ third_party/khronos/khronos.gyp
@@ -11,6 +11,7 @@
         'include_dirs': [
           '.',
           '../../gpu',  # Contains GLES2/gl2chromium.h
+          '<(prefix_dir)/include',
         ],
       },
     },
