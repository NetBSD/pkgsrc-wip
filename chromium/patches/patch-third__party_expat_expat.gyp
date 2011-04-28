$NetBSD: patch-third__party_expat_expat.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/expat/expat.gyp.orig	2011-04-13 08:01:18.000000000 +0000
+++ third_party/expat/expat.gyp
@@ -15,7 +15,7 @@
     ]
   },
   'conditions': [
-    ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
       # On Linux, we implicitly already depend on expat via fontconfig;
       # let's not pull it in twice.
       'targets': [
@@ -59,7 +59,7 @@
                 'COMPILED_FROM_DSP',
               ],
             }],
-            ['OS=="mac" or OS=="freebsd" or OS=="openbsd"', {
+            ['OS=="mac" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
               'defines': [
                 'HAVE_EXPAT_CONFIG_H',
               ],
