$NetBSD: patch-printing_printing.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- printing/printing.gyp.orig	2011-04-13 08:01:08.000000000 +0000
+++ printing/printing.gyp
@@ -83,7 +83,7 @@
         ],
       },
       'conditions': [
-        ['OS!="linux" and OS!="freebsd" and OS!="openbsd"',{
+        ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd"',{
             'sources/': [['exclude', '_cairo\\.cc$']]
         }],
         ['OS!="mac"', {'sources/': [['exclude', '_mac\\.(cc|mm?)$']]}],
@@ -91,7 +91,7 @@
           }, {  # else: OS=="win"
             'sources/': [['exclude', '_posix\\.cc$']]
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             # For FT_Init_FreeType and friends.
             '../build/linux/system.gyp:freetype2',
@@ -165,19 +165,17 @@
         'units_unittest.cc',
       ],
       'conditions': [
-        ['OS!="linux"', {'sources/': [['exclude', '_cairo_unittest\\.cc$']]}],
+        ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd"', {'sources/': [['exclude', '_cairo_unittest\\.cc$']]}],
         ['OS!="mac"', {'sources/': [['exclude', '_mac_unittest\\.(cc|mm?)$']]}],
         ['OS!="win"', {'sources/': [['exclude', '_win_unittest\\.cc$']]
           }, {  # else: OS=="win"
             'sources/': [['exclude', '_cairo_unittest\\.cc$']]
           }
         ],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
             'dependencies': [
               '../build/linux/system.gyp:gtk',
            ],
-        }],
-        ['OS=="linux"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
