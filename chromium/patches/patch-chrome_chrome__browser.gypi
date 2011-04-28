$NetBSD: patch-chrome_chrome__browser.gypi,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/chrome_browser.gypi.orig	2011-04-13 08:01:59.000000000 +0000
+++ chrome/chrome_browser.gypi
@@ -3621,7 +3621,7 @@
             ['include', '^browser/chromeos/dom_ui/login/'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:dbus-glib',
             '../build/linux/system.gyp:gconf',
@@ -3633,13 +3633,12 @@
           ],
           'link_settings': {
             'libraries': [
-              # For dlsym() in 'browser/zygote_main_linux.cc'
-              '-ldl',
             ],
           },
           'sources!': [
             'browser/ui/views/extensions/extension_view.cc',
             'browser/ui/views/extensions/extension_view.h',
+            'browser/file_path_watcher/file_path_watcher_inotify.cc',
           ],
           'sources': [
             'browser/crash_handler_host_linux.h',
@@ -3694,10 +3693,24 @@
             'browser/certificate_manager_model.h',
             'browser/dom_ui/options/certificate_manager_handler.cc',
             'browser/dom_ui/options/certificate_manager_handler.h',
-            'browser/file_path_watcher/file_path_watcher_inotify.cc',
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
+        ['OS=="openbsd" or OS=="netbsd"', {
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
@@ -3705,8 +3718,14 @@
             '../build/linux/system.gyp:x11',
           ],
           'sources': [
+            #'browser/geolocation/gateway_data_provider_bsd.cc',
+            #'browser/geolocation/gateway_data_provider_bsd.h',
             'browser/file_path_watcher/file_path_watcher_stub.cc',
           ],
+          'sources!': [
+            'browser/geolocation/gateway_data_provider_linux.cc',
+            'browser/geolocation/gateway_data_provider_linux.h',
+          ],
         }],
         # Use system SSL settings on Mac and Windows.  Use preferences
         # for SSL settings on other platforms.
@@ -4294,7 +4313,7 @@
               ],
             }],
             # GTK build only
-            ['OS=="linux" and toolkit_views==0', {
+            ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and toolkit_views==0', {
               'sources/': [
                 ['include', '^browser/printing/print_dialog_gtk.cc'],
                 ['include', '^browser/printing/print_dialog_gtk.h'],
