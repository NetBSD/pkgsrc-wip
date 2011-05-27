$NetBSD: patch-content_content__browser.gypi,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- content/content_browser.gypi.orig	2011-05-24 08:01:07.000000000 +0000
+++ content/content_browser.gypi
@@ -324,7 +324,7 @@
         ['OS=="win"', {
           'msvs_guid': '639DB58D-32C2-435A-A711-65A12F62E442',
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:dbus-glib',
             # For FcLangSetAdd call in render_sandbox_host_linux.cc
@@ -340,6 +340,12 @@
             'browser/certificate_manager_model.h',
           ],
         }],
+        ['OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
+          'sources!': [
+            'browser/geolocation/gateway_data_provider_linux.cc',
+            'browser/geolocation/gateway_data_provider_linux.h',
+          ],
+        }],
         ['OS=="linux" and chromeos==1', {
           'sources/': [
             ['exclude', '^browser/geolocation/wifi_data_provider_linux.cc'],
