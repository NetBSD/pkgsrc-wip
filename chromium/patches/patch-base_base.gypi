$NetBSD: patch-base_base.gypi,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/base.gypi.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/base.gypi
@@ -159,6 +159,8 @@
           'process_util.h',
           'process_util_linux.cc',
           'process_util_mac.mm',
+          'process_util_netbsd.cc',
+          'process_util_openbsd.cc',
           'process_util_posix.cc',
           'process_util_win.cc',
           'process_win.cc',
@@ -229,6 +231,7 @@
           'sys_info_freebsd.cc',
           'sys_info_linux.cc',
           'sys_info_mac.cc',
+          'sys_info_netbsd.cc',
           'sys_info_openbsd.cc',
           'sys_info_posix.cc',
           'sys_info_win.cc',
@@ -333,7 +336,7 @@
           '$(SDKROOT)/System/Library/Frameworks/ApplicationServices.framework/Frameworks',
         ],
         'conditions': [
-          [ 'OS != "linux" and OS != "freebsd" and OS != "openbsd" and OS != "solaris"', {
+          [ 'OS != "linux" and OS != "dragonfly" and OS != "freebsd" and OS != "netbsd" and OS != "openbsd" and OS != "solaris"', {
               'sources/': [
                 ['exclude', '^nix/'],
               ],
@@ -342,8 +345,6 @@
                 'message_pump_glib.cc',
                 'message_pump_glib_x.cc',
               ],
-          }],
-          [ 'OS != "linux"', {
               'sources!': [
                 # Not automatically excluded by the *linux.cc rules.
                 'gtk_util.cc',
@@ -359,10 +360,21 @@
           }],
           # For now, just test the *BSD platforms enough to exclude them.
           # Subsequent changes will include them further.
-          [ 'OS != "freebsd"', {
+          [ 'OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
+              'sources!': [
+                'file_util_linux.cc',
+                'process_linux.cc',
+                'process_util_linux.cc',
+              ],
+          }],
+          [ 'OS != "freebsd" and OS != "dragonfly"', {
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
@@ -410,7 +422,7 @@
         ],
       },
       'conditions': [
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd" or OS == "solaris"', {
           'conditions': [
             [ 'chromeos==1', {
                 'sources/': [ ['include', '_chromeos\\.cc$'] ]
@@ -432,9 +444,15 @@
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
@@ -675,7 +693,7 @@
         },
       ],
     }],
-    [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+    [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd" or OS == "solaris"', {
       'targets': [
         {
           'target_name': 'symbolize',
