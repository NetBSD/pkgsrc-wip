$NetBSD$

--- ui/views/controls/webview/webview.gyp.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/views/controls/webview/webview.gyp
@@ -42,7 +42,7 @@
         'webview_export.h',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="android"', {
+        ['OS=="linux" or OS=="android" or os_bsd==1', {
           'sources': [ 'unhandled_keyboard_event_handler_default.cc', ],
         }],
       ],
