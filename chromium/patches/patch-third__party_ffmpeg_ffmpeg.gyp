$NetBSD: patch-third__party_ffmpeg_ffmpeg.gyp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/ffmpeg/ffmpeg.gyp.orig	2011-05-24 08:02:43.000000000 +0000
+++ third_party/ffmpeg/ffmpeg.gyp
@@ -23,7 +23,7 @@
 {
   'target_defaults': {
     'conditions': [
-      ['OS!="linux" and OS!="freebsd" and OS!="openbsd" and OS!="solaris"', {
+      ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd" and OS!="solaris"', {
         'sources/': [['exclude', '/linux/']]
       }],
       ['OS!="mac"', {'sources/': [['exclude', '/mac/']]}],
@@ -320,7 +320,7 @@
                 }],
               ],
             }],
-            ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
               'defines': [
                 '_ISOC99_SOURCE',
                 '_LARGEFILE_SOURCE',
@@ -501,7 +501,7 @@
             'ffmpegsumo',
           ],
           'conditions': [
-            ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
               'copies': [
                 {
                   # On Make and Scons builds, the library does not end up in
