$NetBSD$

* Add NetBSD support

--- node_modules/@parcel/watcher/binding.gyp.orig	2026-10-26 16:16:23.288470992 +0000
+++ node_modules/@parcel/watcher/binding.gyp
@@ -85,7 +85,7 @@
             }
           }
         }],
-        ['OS=="freebsd"', {
+        ['OS=="freebsd" or OS=="netbsd"', {
           "sources": [
             "src/watchman/BSER.cc",
             "src/watchman/WatchmanBackend.cc",
