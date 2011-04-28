$NetBSD: patch-third__party_npapi_npapi.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/npapi/npapi.gyp.orig	2011-04-13 08:01:21.000000000 +0000
+++ third_party/npapi/npapi.gyp
@@ -26,7 +26,7 @@
         'bindings/npruntime.h',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'sources': [
             'bindings/npapi_x11.h',
           ],
