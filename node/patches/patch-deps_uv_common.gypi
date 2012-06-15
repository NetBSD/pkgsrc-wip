$NetBSD: patch-deps_uv_common.gypi,v 1.2 2012/06/15 11:33:29 fhajny Exp $

Add support for NetBSD.
--- deps/uv/common.gypi
+++ deps/uv/common.gypi
@@ -113,11 +113,12 @@
           '_CRT_NONSTDC_NO_DEPRECATE',
         ],
       }],
-      [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+      [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris" or OS=="netbsd"', {
         'variables': {
           'gcc_version%': '<!(python build/gcc_version.py)>)',
         },
-        'cflags': [ '-Wall' ],
+        'cflags': [ '-Wall -pthread' ],
+        'ldflags': [ '-pthread' ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'conditions': [
           [ 'host_arch != target_arch and target_arch=="ia32"', {
