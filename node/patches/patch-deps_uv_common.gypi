diff --git a/deps/uv/common.gypi b/deps/uv/common.gypi
index c2df528..5d9633a 100644
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
