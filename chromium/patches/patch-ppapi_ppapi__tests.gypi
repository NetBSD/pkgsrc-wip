$NetBSD: patch-ppapi_ppapi__tests.gypi,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- ppapi/ppapi_tests.gypi.orig	2011-04-13 08:01:10.000000000 +0000
+++ ppapi/ppapi_tests.gypi
@@ -31,7 +31,7 @@
             ],
           },
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'product_name': 'ppapi_example',
           'type': 'shared_library',
           'cflags': ['-fvisibility=hidden'],
