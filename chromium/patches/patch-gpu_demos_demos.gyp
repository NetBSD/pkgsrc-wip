$NetBSD: patch-gpu_demos_demos.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- gpu/demos/demos.gyp.orig	2011-04-13 08:01:09.000000000 +0000
+++ gpu/demos/demos.gyp
@@ -14,7 +14,7 @@
       # also be compiled with -fPIC flag. Setting GYP_DEFINES="linux_fpic=1"
       # compiles everything with -fPIC. Disable pepper demos on linux/x64
       # unless linux_fpic is 1.
-      ['OS=="linux" and (target_arch=="x64" or target_arch=="arm") and linux_fpic!=1', {
+      ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and (target_arch=="x64" or target_arch=="arm") and linux_fpic!=1', {
         'enable_pepper_demos%': 0,
       }, {
         'enable_pepper_demos%': 1,
@@ -51,7 +51,7 @@
         'framework/window.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': ['../../build/linux/system.gyp:gtk'],
         }],
       ],
@@ -171,7 +171,7 @@
           ],
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
             # -gstabs, used in the official builds, causes an ICE. Remove it.
             'cflags!': ['-gstabs'],
           }],
