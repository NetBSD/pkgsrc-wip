$NetBSD: patch-v8_src_d8.gyp,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- v8/src/d8.gyp.orig	2011-05-24 08:20:55.000000000 +0000
+++ v8/src/d8.gyp
@@ -46,7 +46,7 @@
         '<(SHARED_INTERMEDIATE_DIR)/d8-js.cc',
       ],
       'conditions': [
-        [ 'OS=="linux" or OS=="mac" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        [ 'OS=="linux" or OS=="mac" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'sources': [ 'd8-posix.cc', ]
         }],
       ],
