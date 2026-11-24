$NetBSD$

* Add NetBSD support

--- node_modules/.pnpm/native-keymap@3.3.9/node_modules/native-keymap/binding.gyp.orig	2026-11-24 11:15:53.257605229 +0000
+++ node_modules/.pnpm/native-keymap@3.3.9/node_modules/native-keymap/binding.gyp
@@ -60,6 +60,20 @@
             ]
           }
         }],
+        ['OS=="netbsd"', {
+          "sources": [
+            "deps/chromium/x/keysym_to_unicode.cc",
+            "src/keyboard_x.cc"
+          ],
+          "include_dirs": [
+            "<!@(${PKG_CONFIG:-pkg-config} x11 xkbfile --cflags | sed -n 's/.*-I\([^ ]*\).*/\1/p')"
+          ],
+          "link_settings": {
+            "libraries": [
+              "<!@(${PKG_CONFIG:-pkg-config} x11 xkbfile --libs)"
+            ]
+          }
+        }],
         ['OS=="win"', {
           "sources": [
             "src/keyboard_win.cc"
