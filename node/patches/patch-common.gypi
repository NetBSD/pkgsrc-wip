$NetBSD: patch-common.gypi,v 1.3 2012/07/24 13:40:35 fhajny Exp $

Add support for NetBSD.
--- common.gypi.orig	2012-07-19 17:01:56.000000000 +0000
+++ common.gypi
@@ -152,7 +152,7 @@
           '_FILE_OFFSET_BITS=64',
         ],
       }],
-      [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+      [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris" or OS=="netbsd"', {
         'cflags': [ '-Wall', '-pthread', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'ldflags': [ '-pthread', '-rdynamic' ],
