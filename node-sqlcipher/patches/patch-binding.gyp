$NetBSD$

* Add NetBSD support

--- binding.gyp.orig	2026-08-20 17:23:05.000000000 +0000
+++ binding.gyp
@@ -10,7 +10,7 @@
       ],
       'sources': ['src/addon.cc'],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="netbsd"', {
           'ldflags': [
             '-Wl,-Bsymbolic',
             '-Wl,--exclude-libs,ALL',
