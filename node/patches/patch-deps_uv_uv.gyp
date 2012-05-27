diff --git a/deps/uv/uv.gyp b/deps/uv/uv.gyp
index f53e18e..ff5a55b 100644
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
