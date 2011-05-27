$NetBSD: patch-ui_gfx_gfx.gyp,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- ui/gfx/gfx.gyp.orig	2011-05-24 08:01:59.000000000 +0000
+++ ui/gfx/gfx.gyp
@@ -66,7 +66,7 @@
             },
           }
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../../build/linux/system.gyp:gtk',
           ],
@@ -168,7 +168,7 @@
             '<(DEPTH)/third_party/wtl/include',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             # font_gtk.cc uses fontconfig.
             # TODO(evanm): I think this is wrong; it should just use GTK.
