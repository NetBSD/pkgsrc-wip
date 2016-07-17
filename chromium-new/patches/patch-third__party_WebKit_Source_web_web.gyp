$NetBSD$

--- third_party/WebKit/Source/web/web.gyp.orig	2016-06-24 01:02:47.000000000 +0000
+++ third_party/WebKit/Source/web/web.gyp
@@ -118,7 +118,7 @@
                         '../core/core.gyp:webcore',
                      ],
                 }],
-                ['OS == "linux"', {
+                ['OS == "linux" or os_bsd == 1', {
                     'dependencies': [
                         '<(DEPTH)/build/linux/system.gyp:fontconfig',
                     ],
