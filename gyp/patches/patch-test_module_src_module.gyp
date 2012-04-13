$NetBSD: patch-test_module_src_module.gyp,v 1.1 2012/04/13 22:38:16 ryo-on Exp $

--- test/module/src/module.gyp.orig	2012-04-13 19:31:55.000000000 +0000
+++ test/module/src/module.gyp
@@ -17,6 +17,11 @@
         'cflags': ['-fPIC'],
         'libraries': ['-ldl'],
       }],
+      ['OS=="netbsd"', {
+        'defines': ['PLATFORM_LINUX'],
+        # Support 64-bit shared libs (also works fine for 32-bit).
+        'cflags': ['-fPIC'],
+      }],
     ],
   },
   'targets': [
