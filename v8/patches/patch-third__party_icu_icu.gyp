$NetBSD: patch-third__party_icu_icu.gyp,v 1.1 2014/08/23 17:44:12 heidnes Exp $

Try to build with the pkgsrc version of icu,
the other path leads to file name clashes or version mismatches.

--- third_party/icu/icu.gyp.orig	2014-08-08 13:42:23.000000000 +0000
+++ third_party/icu/icu.gyp
@@ -7,7 +7,7 @@
     'icu.gypi',
   ],
   'variables': {
-    'use_system_icu%': 0,
+    'use_system_icu%': 1,
     'icu_use_data_file_flag%': 0,
     'want_separate_host_toolset%': 1,
   },
