$NetBSD: patch-third__party_mesa_mesa.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/mesa/mesa.gyp.orig	2011-04-13 08:01:28.000000000 +0000
+++ third_party/mesa/mesa.gyp
@@ -19,7 +19,7 @@
           'HAVE_STRNLEN',
         ],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
         'cflags': [
           '-fPIC',
         ],
