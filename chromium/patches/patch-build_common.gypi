$NetBSD: patch-build_common.gypi,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- build/common.gypi.orig	2011-04-13 08:01:33.000000000 +0000
+++ build/common.gypi
@@ -38,7 +38,7 @@
 
         # Compute the architecture that we're building on.
         'conditions': [
-          [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+          [ 'OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
             # This handles the Linux platforms we generally deal with. Anything
             # else gets passed through, which probably won't work very well; such
             # hosts should pass an explicit target_arch to gyp.
@@ -355,7 +355,7 @@
     'use_harfbuzz_ng%': 0,
 
     'conditions': [
-      ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
         # This will set gcc_version to XY if you are running gcc X.Y.*.
         # This is used to tweak build flags for gcc 4.4.
         'gcc_version%': '<!(python <(DEPTH)/build/compiler_version.py)',
@@ -638,7 +638,7 @@
     'target_conditions': [
       ['chromium_code==0', {
         'conditions': [
-          [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+          [ 'OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
             'cflags!': [
               '-Wall',
               '-Wextra',
@@ -684,14 +684,14 @@
                           ['exclude', '(^|/)(cocoa|mac)/'],
                           ['exclude', '\\.mm?$' ] ],
           }],
-          ['OS!="linux" and OS!="freebsd" and OS!="openbsd"', {
+          ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd"', {
             'sources/': [
               ['exclude', '_(chromeos|gtk|x|x11|xdg)(_unittest)?\\.(h|cc)$'],
               ['exclude', '(^|/)gtk/'],
               ['exclude', '(^|/)(gtk|x11)_[^/]*\\.(h|cc)$'],
             ],
           }],
-          ['OS!="linux"', {
+          ['OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd"', {
             'sources/': [
               ['exclude', '_linux(_unittest)?\\.(h|cc)$'],
               ['exclude', '(^|/)linux/'],
@@ -910,7 +910,7 @@
     },
   },
   'conditions': [
-    ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
       'target_defaults': {
         # Enable -Werror by default, but put it in a variable so it can
         # be disabled in ~/.gyp/include.gypi on the valgrind builders.
@@ -923,7 +923,9 @@
           # aliasing issues have been fixed.
           'no_strict_aliasing%': 1,
           'conditions': [['OS=="linux"', {'werror%': '-Werror',}],
+                         ['OS=="dragonfly"', {'werror%': '',}],
                          ['OS=="freebsd"', {'werror%': '',}],
+                         ['OS=="netbsd"', {'werror%': '',}],
                          ['OS=="openbsd"', {'werror%': '',}],
           ],
         },
