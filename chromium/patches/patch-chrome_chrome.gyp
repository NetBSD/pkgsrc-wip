$NetBSD: patch-chrome_chrome.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/chrome.gyp.orig	2011-04-13 08:01:59.000000000 +0000
+++ chrome/chrome.gyp
@@ -82,7 +82,7 @@
         'platform_locale_settings_grd':
             'app/resources/locale_settings_win.grd',
       },],
-      ['OS=="linux"', {
+      ['OS=="linux"or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
         'nacl_defines': [
           'NACL_WINDOWS=0',
           'NACL_LINUX=1',
@@ -537,7 +537,7 @@
         'browser/debugger/inspectable_tab_proxy.h',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -611,7 +611,7 @@
             'plugin/command_buffer_stub_win.cc',
            ],
         },],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -635,7 +635,7 @@
         '..',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -758,7 +758,7 @@
             'gpu/media/mft_angle_video_device.h',
           ],
         }],
-        ['OS=="linux" and target_arch!="arm"', {
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and target_arch!="arm"', {
           'sources': [
             'gpu/x_util.cc',
             'gpu/x_util.h',
@@ -853,7 +853,7 @@
         'sync_notifier',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             '../build/linux/system.gyp:nss'
           ],
@@ -1017,7 +1017,7 @@
             'browser/sync/util/data_encryption.h',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss'
@@ -1140,7 +1140,7 @@
             'service/cloud_print/print_system_win.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -1810,7 +1810,7 @@
         },
       ]},  # 'targets'
     ],  # OS=="win"
-    ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
       'targets': [{
         'target_name': 'packed_resources',
         'type': 'none',
