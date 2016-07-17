$NetBSD$

--- chrome/chrome_exe.gypi.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/chrome_exe.gypi
@@ -182,7 +182,7 @@
                 '../build/linux/system.gyp:xext',
               ],
             }],
-            ['OS=="linux" and enable_plugins==1', {
+            ['(OS=="linux" or os_bsd==1) and enable_plugins==1', {
               'dependencies': [
                 '../pdf/pdf.gyp:pdf',
               ],
