$NetBSD: patch-third__party_sqlite_sqlite.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/sqlite/sqlite.gyp.orig	2011-04-13 08:01:30.000000000 +0000
+++ third_party/sqlite/sqlite.gyp
@@ -31,7 +31,7 @@
             ],
           },
         }],
-        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd") and use_system_sqlite', {
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and use_system_sqlite', {
           'type': 'settings',
           'direct_dependent_settings': {
             'cflags': [
@@ -229,7 +229,7 @@
     },
   ],
   'conditions': [
-    ['(OS=="linux" or OS=="freebsd" or OS=="openbsd") and not use_system_sqlite', {
+    ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and not use_system_sqlite', {
       'targets': [
         {
           'target_name': 'sqlite_shell',
