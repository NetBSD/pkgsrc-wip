$NetBSD: patch-native__client_src_shared_platform_platform.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- native_client/src/shared/platform/platform.gyp.orig	2011-04-13 08:13:05.000000000 +0000
+++ native_client/src/shared/platform/platform.gyp
@@ -60,7 +60,7 @@
       'time.h',
     ],
     'conditions': [
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
         'platform_sources': [
           'linux/condition_variable.cc',
           'linux/lock.cc',
@@ -75,6 +75,11 @@
           'linux/time_linux.cc',
         ],
       }],
+      ['OS=="netbsd"', {
+        'platform_sources': [
+          'osx/strnlen_osx.c',
+        ],
+      }],
       ['OS=="mac"', {
         'platform_sources': [
           'linux/condition_variable.cc',
