diff --git a/common.gypi b/common.gypi
index 8b3e7c2..8c2166c 100644
--- common.gypi
+++ common.gypi
@@ -136,7 +136,7 @@
           '_FILE_OFFSET_BITS=64',
         ],
       }],
-      [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+      [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris" or OS=="netbsd"', {
         'cflags': [ '-Wall', '-pthread', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'ldflags': [ '-pthread', ],
