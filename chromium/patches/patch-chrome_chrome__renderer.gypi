$NetBSD: patch-chrome_chrome__renderer.gypi,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/chrome_renderer.gypi.orig	2011-04-13 08:01:59.000000000 +0000
+++ chrome/chrome_renderer.gypi
@@ -294,7 +294,15 @@
           ],
         }],
         # BSD-specific rules.
-        ['OS=="openbsd" or OS=="freebsd"', {
+        ['OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
+          'conditions': [
+            [ 'linux_use_tcmalloc==1', {
+                'dependencies': [
+                  '../base/allocator/allocator.gyp:allocator',
+                ],
+              },
+            ],
+          ],
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
