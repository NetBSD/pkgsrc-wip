$NetBSD$

* use the compiler provided version of alloca(3)

--- deps/sqlcipher/sqlcipher.gyp.orig	2026-08-20 17:23:05.000000000 +0000
+++ deps/sqlcipher/sqlcipher.gyp
@@ -17,7 +17,7 @@
           '.',
         ],
       },
-      'cflags': ['-std=c99', '-w'],
+      'cflags': ['-std=gnu99', '-w'],
       'xcode_settings': {
         'OTHER_CFLAGS': ['-std=c99'],
         'WARNING_CFLAGS': ['-w'],
