$NetBSD: patch-chrome_chrome__common.gypi,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/chrome_common.gypi.orig	2011-04-13 08:01:59.000000000 +0000
+++ chrome/chrome_common.gypi
@@ -389,7 +389,7 @@
         'common/zip.h',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -405,7 +405,7 @@
             ],
           },
         },],
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd" or OS == "solaris"', {
           'include_dirs': [
             '<(SHARED_INTERMEDIATE_DIR)',
           ],
@@ -526,7 +526,7 @@
         '../third_party/icu/icu.gyp:icuuc',
       ],
       'conditions': [
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
             'conditions': [
               ['use_openssl==1', {
                  'dependencies': [
