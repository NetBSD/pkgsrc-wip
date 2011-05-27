$NetBSD: patch-chrome_chrome__common.gypi,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/chrome_common.gypi.orig	2011-05-24 08:01:58.000000000 +0000
+++ chrome/chrome_common.gypi
@@ -156,6 +156,14 @@
           'common/win_safe_util.cc',
           'common/win_safe_util.h',
         ],
+        'conditions': [
+          ['OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
+            'sources!': [
+              'common/set_process_title_linux.cc',
+              'common/set_process_title_linux.h',
+            ],
+          }],
+        ],
       }],
     ],
   },
@@ -368,7 +376,7 @@
         'common/zip.h',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -384,7 +392,7 @@
             ],
           },
         },],
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd" or OS == "solaris"', {
           'include_dirs': [
             '<(SHARED_INTERMEDIATE_DIR)',
           ],
@@ -510,7 +518,7 @@
         '../third_party/icu/icu.gyp:icuuc',
       ],
       'conditions': [
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
             'conditions': [
               ['use_openssl==1', {
                  'dependencies': [
