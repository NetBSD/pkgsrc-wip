$NetBSD: patch-third__party_qcms_qcms.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/qcms/qcms.gyp.orig	2011-04-13 08:01:31.000000000 +0000
+++ third_party/qcms/qcms.gyp
@@ -23,7 +23,7 @@
         ],
       },
       'conditions': [
-        ['OS=="linux" and (branding=="Chrome" or disable_sse2==1)', {
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and (branding=="Chrome" or disable_sse2==1)', {
           'sources/': [
             ['exclude', 'transform-sse1.c'],
             ['exclude', 'transform-sse2.c'],
