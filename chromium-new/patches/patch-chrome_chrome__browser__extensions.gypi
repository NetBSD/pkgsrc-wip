$NetBSD$

--- chrome/chrome_browser_extensions.gypi.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/chrome_browser_extensions.gypi
@@ -1019,6 +1019,11 @@
             '<@(chrome_browser_extensions_task_manager_enabled_sources)',
           ],
         }],
+        ['os_bsd==1', {
+          'sources/': [
+            ['exclude', '^browser/extensions/api/image_writer_private/removable_storage_provider_linux.cc'],
+          ],
+        }],
         ['chromeos==1', {
           'dependencies': [
             '../build/linux/system.gyp:dbus',
@@ -1061,7 +1066,7 @@
             '../ui/views/views.gyp:views',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['use_aura==1', {
               'dependencies': [
