$NetBSD$

--- third_party/sqlite/sqlite.gyp.orig	2016-06-24 01:02:49.000000000 +0000
+++ third_party/sqlite/sqlite.gyp
@@ -123,6 +123,8 @@
           },
           'include_dirs': [
             'amalgamation',
+            # FreeBSD ...
+            '<(prefix_dir)/include',
           ],
           'dependencies': [
             '../icu/icu.gyp:icui18n',
