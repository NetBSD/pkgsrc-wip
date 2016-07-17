$NetBSD$

--- third_party/libXNVCtrl/libXNVCtrl.gyp.orig	2016-06-24 01:02:48.000000000 +0000
+++ third_party/libXNVCtrl/libXNVCtrl.gyp
@@ -13,6 +13,9 @@
         'NVCtrlLib.h',
         'nv_control.h',
       ],
+      'include_dirs': [
+        '<(prefix_dir)/include',
+      ],
     },
   ],
 }
