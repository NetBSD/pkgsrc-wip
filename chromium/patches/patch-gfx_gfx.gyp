$NetBSD: patch-gfx_gfx.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- gfx/gfx.gyp.orig	2011-04-13 08:01:07.000000000 +0000
+++ gfx/gfx.gyp
@@ -65,7 +65,7 @@
             },
           }
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -162,7 +162,7 @@
             '<(DEPTH)/third_party/wtl/include',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             # font_gtk.cc uses fontconfig.
             # TODO(evanm): I think this is wrong; it should just use GTK.
