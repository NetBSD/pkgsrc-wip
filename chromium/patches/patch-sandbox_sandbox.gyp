$NetBSD: patch-sandbox_sandbox.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- sandbox/sandbox.gyp.orig	2011-04-13 08:01:32.000000000 +0000
+++ sandbox/sandbox.gyp
@@ -126,7 +126,7 @@
     ],
   },
   'conditions': [
-    [ 'OS=="freebsd" or OS=="openbsd"', {
+    [ 'OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
       # GYP requires that each file have at least one target defined.
       'targets': [
         {
