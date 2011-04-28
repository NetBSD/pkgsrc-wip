$NetBSD: patch-third__party_icu_icu.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/icu/icu.gyp.orig	2011-04-13 08:13:59.000000000 +0000
+++ third_party/icu/icu.gyp
@@ -54,7 +54,7 @@
             }, {  # else: OS != "win"
               'sources!': ['icudt42.dll'],
             }],
-            [ 'OS != "linux" or chromeos == 1', {
+            [ '(OS != "linux" and OS != "dragonfly" and OS != "freebsd" and OS != "netbsd" and OS != "openbsd") or chromeos == 1', {
               'sources!': ['linux/icudt42l_dat.S'],
             }],
             [ 'OS != "mac"', {
@@ -232,7 +232,7 @@
             ],
           },
           'conditions': [
-            [ 'OS=="linux"', {
+            [ 'OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
               # Since ICU wants to internally use its own deprecated APIs, don't
               # complain about it.
               'cflags': [
