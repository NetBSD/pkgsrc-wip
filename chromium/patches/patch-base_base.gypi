$NetBSD: patch-base_base.gypi,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- base/base.gypi.orig	2011-05-24 08:01:33.000000000 +0000
+++ base/base.gypi
@@ -167,8 +167,11 @@
           'process_posix.cc',
           'process_util.cc',
           'process_util.h',
+          'process_util_dragonfly.cc',
           'process_util_linux.cc',
           'process_util_mac.mm',
+          'process_util_netbsd.cc',
+          'process_util_openbsd.cc',
           'process_util_posix.cc',
           'process_util_win.cc',
           'process_win.cc',
@@ -236,9 +239,11 @@
           'synchronization/waitable_event_win.cc',
           'sys_info.h',
           'sys_info_chromeos.cc',
+          'sys_info_dragonfly.cc',
           'sys_info_freebsd.cc',
           'sys_info_linux.cc',
           'sys_info_mac.cc',
+          'sys_info_netbsd.cc',
           'sys_info_openbsd.cc',
           'sys_info_posix.cc',
           'sys_info_win.cc',
@@ -345,7 +350,7 @@
           '$(SDKROOT)/System/Library/Frameworks/ApplicationServices.framework/Frameworks',
         ],
         'conditions': [
-          [ 'OS != "linux" and OS != "freebsd" and OS != "openbsd" and OS != "solaris"', {
+          [ 'OS != "linux" and OS != "dragonfly" and OS != "freebsd" and OS != "netbsd" and OS != "openbsd" and OS != "solaris"', {
               'sources/': [
                 ['exclude', '^nix/'],
               ],
@@ -354,8 +359,6 @@
                 'message_pump_glib.cc',
                 'message_pump_glib_x.cc',
               ],
-          }],
-          [ 'OS != "linux"', {
               'sources!': [
                 # Not automatically excluded by the *linux.cc rules.
                 'gtk_util.cc',
@@ -371,10 +374,25 @@
           }],
           # For now, just test the *BSD platforms enough to exclude them.
           # Subsequent changes will include them further.
+          [ 'OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
+              'sources!': [
+                'file_util_linux.cc',
+                'process_linux.cc',
+                'process_util_linux.cc',
+              ],
+          }],
+          [ 'OS != "dragonfly"', {
+              'sources/': [ ['exclude', '_dragonfly\\.cc$'] ],
+            },
+          ],
           [ 'OS != "freebsd"', {
               'sources/': [ ['exclude', '_freebsd\\.cc$'] ],
             },
           ],
+          [ 'OS != "netbsd"', {
+              'sources/': [ ['exclude', '_netbsd\\.cc$'] ],
+            },
+          ],
           [ 'OS != "openbsd"', {
               'sources/': [ ['exclude', '_openbsd\\.cc$'] ],
             },
@@ -422,7 +440,7 @@
         ],
       },
       'conditions': [
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd" or OS == "solaris"', {
           'conditions': [
             [ 'chromeos==1', {
                 'sources/': [ ['include', '_chromeos\\.cc$'] ]
@@ -444,9 +462,15 @@
                   '../third_party/openssl/openssl.gyp:openssl',
                 ],
               }, {  # use_openssl==0
+                'sources': [
+                  'base/crypto/scoped_nss_types.h',
+                ],
                 'dependencies': [
                   '../build/linux/system.gyp:nss',
                 ],
+                'export_dependent_settings': [
+                  '../build/linux/system.gyp:nss',
+                ],
               }
             ],
           ],
@@ -691,7 +715,7 @@
         },
       ],
     }],
-    [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+    [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd" or OS == "solaris"', {
       'targets': [
         {
           'target_name': 'symbolize',
