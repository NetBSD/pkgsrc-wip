$NetBSD: patch-third__party_ffmpeg_ffmpeg.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/ffmpeg/ffmpeg.gyp.orig	2011-04-13 08:02:52.000000000 +0000
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
@@ -326,7 +326,7 @@
                 }],
               ],
             }],
-            ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
               'defines': [
                 '_ISOC99_SOURCE',
                 '_LARGEFILE_SOURCE',
@@ -492,7 +492,7 @@
           'rules': [
             {
               'conditions': [
-                ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+                ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
                   'variables': {
                     'obj_format': 'elf',
                   },
@@ -620,7 +620,7 @@
             'ffmpegsumo',
           ],
           'conditions': [
-            ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
               'copies': [
                 {
                   # On Make and Scons builds, the library does not end up in
