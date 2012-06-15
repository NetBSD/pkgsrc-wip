$NetBSD: patch-common.gypi,v 1.2 2012/06/15 11:33:29 fhajny Exp $

Add support for NetBSD.
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
