$NetBSD: patch-deps_uv_uv.gyp,v 1.2 2012/06/15 11:33:29 fhajny Exp $

Add support for NetBSD.
--- deps/uv/uv.gyp
+++ deps/uv/uv.gyp
@@ -279,6 +279,19 @@
             'EIO_CONFIG_H="config_openbsd.h"',
           ],
         }],
+        [ 'OS=="netbsd"', {
+          'include_dirs': [ 'src/ares/config_netbsd' ],
+          'sources': [ 'src/unix/netbsd.c' ],
+          'defines': [
+            'EV_CONFIG_H="config_netbsd.h"',
+            'EIO_CONFIG_H="config_netbsd.h"',
+          ],
+          'direct_dependent_settings': {
+            'libraries': [
+              '-lkvm',
+            ],
+          },
+        }],
         [ 'OS=="mac" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd"', {
           'sources': [ 'src/unix/kqueue.c' ],
         }],
