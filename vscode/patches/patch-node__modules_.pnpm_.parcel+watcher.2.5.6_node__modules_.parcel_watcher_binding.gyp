$NetBSD$

* Add NetBSD support

--- node_modules/.pnpm/@parcel+watcher@2.5.6/node_modules/@parcel/watcher/binding.gyp.orig	2026-11-24 11:16:03.563598750 +0000
+++ node_modules/.pnpm/@parcel+watcher@2.5.6/node_modules/@parcel/watcher/binding.gyp
@@ -85,7 +85,7 @@
             }
           }
         }],
-        ['OS=="freebsd"', {
+        ['OS=="freebsd" or OS=="netbsd"', {
           "sources": [
             "src/watchman/BSER.cc",
             "src/watchman/WatchmanBackend.cc",
