$NetBSD: patch-v8_tools_gyp_v8.gyp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- v8/tools/gyp/v8.gyp.orig	2011-05-24 08:20:55.000000000 +0000
+++ v8/tools/gyp/v8.gyp
@@ -109,7 +109,7 @@
           },
           'Release': {
             'conditions': [
-              ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+              ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
                 'cflags!': [
                   '-O2',
                   '-Os',
@@ -718,6 +718,13 @@
                 ],
               }
             ],
+            ['OS=="dragonfly"', {
+                'sources': [
+                  '../../src/platform-dragonfly.cc',
+                  '../../src/platform-posix.cc'
+                ],
+              }
+            ],
             ['OS=="freebsd"', {
                 'link_settings': {
                   'libraries': [
@@ -729,6 +736,12 @@
                 ],
               }
             ],
+            ['OS=="netbsd"', {
+                'sources': [
+                  '../../src/platform-netbsd.cc',
+                  '../../src/platform-posix.cc'
+                ],
+            }],
             ['OS=="openbsd"', {
                 'link_settings': {
                   'libraries': [
