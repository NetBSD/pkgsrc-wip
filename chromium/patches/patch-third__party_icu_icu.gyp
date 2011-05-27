$NetBSD: patch-third__party_icu_icu.gyp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/icu/icu.gyp.orig	2011-05-24 08:20:20.000000000 +0000
+++ third_party/icu/icu.gyp
@@ -54,7 +54,7 @@
             }, {  # else: OS != "win"
               'sources!': ['windows/icudt46.dll'],
             }],
-            [ 'OS != "linux" or chromeos == 1', {
+            [ '(OS != "linux" and OS != "dragonfly" and OS != "freebsd" and OS != "netbsd" and OS != "openbsd") or chromeos == 1', {
               'sources!': ['linux/icudt46l_dat.S'],
             }],
             [ 'OS != "mac"', {
@@ -264,7 +264,7 @@
             ],
           },
           'conditions': [
-            [ 'OS=="linux"', {
+            [ 'OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
               # Since ICU wants to internally use its own deprecated APIs, don't
               # complain about it.
               'cflags': [
@@ -479,7 +479,7 @@
                 'source/stubdata/stubdata.c',
               ],
             }],
-            [ 'OS == "linux"', {
+            [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
               'cflags': [
                 # Since ICU wants to internally use its own deprecated APIs,
                 # don't complain about it.
