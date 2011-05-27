$NetBSD: patch-chrome_chrome__browser.gypi,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/chrome_browser.gypi.orig	2011-05-24 08:01:58.000000000 +0000
+++ chrome/chrome_browser.gypi
@@ -3455,7 +3455,7 @@
             ['exclude', '^browser/views/tab_contents/tab_contents_view_gtk.h'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:dbus-glib',
             '../build/linux/system.gyp:gconf',
@@ -3467,8 +3467,6 @@
           ],
           'link_settings': {
             'libraries': [
-              # For dlsym() in 'browser/zygote_main_linux.cc'
-              '-ldl',
             ],
           },
           'sources!': [
@@ -3527,7 +3525,22 @@
             'browser/ui/webui/options/certificate_manager_handler.h',
           ],
         }],
-        ['OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux"', {
+          'link_settings': {
+            'libraries': [
+              # For dlsym() in 'browser/zygote_main_linux.cc'
+              '-ldl',
+            ],
+          },
+        }],
+        ['OS=="netbsd" or OS=="openbsd"', {
+          'link_settings': {
+            'libraries': [
+              '-lkvm',
+            ],
+          },
+        }],
+        ['OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:gtkprint',
@@ -4118,7 +4131,7 @@
               ],
             }],
             # GTK build only
-            ['OS=="linux" and toolkit_views==0', {
+            ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and toolkit_views==0', {
               'sources/': [
                 ['include', '^browser/printing/print_dialog_gtk.cc'],
                 ['include', '^browser/printing/print_dialog_gtk.h'],
@@ -4196,7 +4209,7 @@
                 },
               ],
             }],
-            ['OS=="linux" and gcc_version==45', {
+            ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and gcc_version==45', {
               # Avoid gcc 4.5 miscompilation of template_url.cc
               # as per http://crbug.com/41887
               'cflags': [
