$NetBSD: patch-deps_uv_common.gypi,v 1.3 2012/08/21 09:42:21 fhajny Exp $

Add support for NetBSD.
--- deps/uv/common.gypi.orig	2012-08-15 22:52:57.000000000 +0000
+++ deps/uv/common.gypi
@@ -118,7 +118,7 @@
           '_CRT_NONSTDC_NO_DEPRECATE',
         ],
       }],
-      [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+      [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris" or OS=="netbsd"', {
         'cflags': [ '-Wall' ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions' ],
         'conditions': [
