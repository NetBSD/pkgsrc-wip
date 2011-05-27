$NetBSD: patch-build_common.gypi,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- build/common.gypi.orig	2011-05-24 08:01:32.000000000 +0000
+++ build/common.gypi
@@ -42,7 +42,7 @@
 
         # Compute the architecture that we're building on.
         'conditions': [
-          [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+          [ 'OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
             # This handles the Linux platforms we generally deal with. Anything
             # else gets passed through, which probably won't work very well; such
             # hosts should pass an explicit target_arch to gyp.
@@ -389,7 +389,7 @@
     'icu_src_dir': '../third_party/icu',
 
     'conditions': [
-      ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
         # This will set gcc_version to XY if you are running gcc X.Y.*.
         # This is used to tweak build flags for gcc 4.4.
         'gcc_version%': '<!(python <(DEPTH)/build/compiler_version.py)',
@@ -690,7 +690,7 @@
     'target_conditions': [
       ['chromium_code==0', {
         'conditions': [
-          [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+          [ 'OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
             # We don't want to get warnings from third-party code,
             # so remove any existing warning-enabling flags like -Wall.
             'cflags!': [
@@ -745,14 +745,14 @@
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
@@ -971,7 +971,7 @@
     },
   },
   'conditions': [
-    ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+    ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
       'target_defaults': {
         # Enable -Werror by default, but put it in a variable so it can
         # be disabled in ~/.gyp/include.gypi on the valgrind builders.
@@ -984,7 +984,9 @@
           # aliasing issues have been fixed.
           'no_strict_aliasing%': 1,
           'conditions': [['OS=="linux"', {'werror%': '-Werror',}],
+                         ['OS=="dragonfly"', {'werror%': '',}],
                          ['OS=="freebsd"', {'werror%': '',}],
+                         ['OS=="netbsd"', {'werror%': '',}],
                          ['OS=="openbsd"', {'werror%': '',}],
           ],
         },
@@ -1053,7 +1055,7 @@
               # Specifically tell the linker to perform optimizations.
               # See http://lwn.net/Articles/192624/ .
               '-Wl,-O1',
-              '-Wl,--as-needed',
+              #'-Wl,--as-needed',
             ],
             'conditions' : [
               ['no_gc_sections==0', {
