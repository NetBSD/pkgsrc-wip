$NetBSD: patch-third__party_libjingle_libjingle.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/libjingle/libjingle.gyp.orig	2011-04-13 08:01:20.000000000 +0000
+++ third_party/libjingle/libjingle.gyp
@@ -72,12 +72,12 @@
             'OSX',
           ],
         }],
-        ['OS=="linux" or OS=="mac" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="mac"', {
           'defines': [
             'POSIX',
           ],
         }],
-        ['OS=="openbsd" or OS=="freebsd"', {
+        ['OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'defines': [
             'BSD',
           ],
@@ -116,12 +116,12 @@
           'OSX',
         ],
       }],
-      ['OS=="linux" or OS=="mac" or OS=="freebsd" or OS=="openbsd"', {
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="mac"', {
         'defines': [
           'POSIX',
         ],
       }],
-      ['OS=="openbsd" or OS=="freebsd"', {
+      ['OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
         'defines': [
           'BSD',
         ],
@@ -328,7 +328,7 @@
             'source/talk/base/winping.h',
           ],
         }],
-        ['OS=="linux" or OS=="mac" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="mac"', {
           'sources': [
             'source/talk/base/sslstreamadapter.cc',
             'source/talk/base/sslstreamadapter.h',
