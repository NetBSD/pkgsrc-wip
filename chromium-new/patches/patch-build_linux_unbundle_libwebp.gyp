$NetBSD$

--- build/linux/unbundle/libwebp.gyp.orig	2016-06-24 01:02:09.000000000 +0000
+++ build/linux/unbundle/libwebp.gyp
@@ -14,13 +14,7 @@
       },
       'link_settings': {
         'libraries': [
-          # Check for presence of webpdemux library, use it if present.
-          '<!(python <(DEPTH)/tools/compile_test/compile_test.py '
-          '--code "int main() { return 0; }" '
-          '--run-linker '
-          '--on-success "-lwebp -lwebpdemux" '
-          '--on-failure "-lwebp" '
-          '-- -lwebpdemux)',
+          '-lwebp -lwebpdemux',
         ],
       },
     }
