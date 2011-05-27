$NetBSD: patch-chrome_chrome.gyp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/chrome.gyp.orig	2011-05-24 08:01:58.000000000 +0000
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
@@ -601,7 +601,7 @@
             '<(DEPTH)/third_party/wtl/include',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -625,7 +625,7 @@
         '..',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -748,7 +748,7 @@
             'gpu/media/mft_angle_video_device.h',
           ],
         }],
-        ['OS=="linux" and target_arch!="arm"', {
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and target_arch!="arm"', {
           'sources': [
             'gpu/x_util.cc',
             'gpu/x_util.h',
@@ -842,7 +842,7 @@
         'sync_notifier',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             '../build/linux/system.gyp:nss'
           ],
@@ -1027,7 +1027,7 @@
             'browser/sync/util/data_encryption.h',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss'
@@ -1150,7 +1150,7 @@
             'service/cloud_print/print_system_win.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -1824,7 +1824,7 @@
         },
       ]},  # 'targets'
     ],  # OS=="win"
-    ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
       'targets': [{
         'target_name': 'packed_resources',
         'type': 'none',
