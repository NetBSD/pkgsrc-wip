$NetBSD: patch-app_app__base.gypi,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- app/app_base.gypi.orig	2011-04-13 08:01:07.000000000 +0000
+++ app/app_base.gypi
@@ -33,7 +33,7 @@
             'app_switches.cc',
         ],
         'conditions': [
-          ['OS!="linux" and OS!="freebsd" and OS!="openbsd"', {
+          ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd"', {
             'sources!': [
               '../ui/base/dragdrop/gtk_dnd_util.cc',
               '../ui/base/dragdrop/gtk_dnd_util.h',
@@ -283,7 +283,7 @@
         },
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             # font_gtk.cc uses fontconfig.
             # TODO(evanm): I think this is wrong; it should just use GTK.
@@ -335,7 +335,22 @@
             ['exclude', '^win/*'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
+          'sources!': [
+            'surface/transport_dib_linux.cc',
+          ],
+        }],
+        ['OS=="freebsd" or OS=="dragonfly"', {
+          'sources': [
+            'surface/transport_dib_freebsd.cc',
+          ],
+        }],
+        ['OS=="openbsd" or OS=="netbsd"', {
+          'sources': [
+            'surface/transport_dib_openbsd.cc',
+          ],
+        }],
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'sources': [
             'gfx/gl/gl_context_egl.cc',
             'gfx/gl/gl_context_egl.h',
@@ -363,11 +378,17 @@
             'link_settings': {
               'libraries': [
                 '-lX11',
-                '-ldl',
               ],
             },
           },
         }],
+        ['OS=="linux"', {
+          'link_settings': {
+            'libraries': [
+              '-ldl',
+            ],
+          },
+        }],
         ['OS=="mac"', {
           'link_settings': {
             'libraries': [
