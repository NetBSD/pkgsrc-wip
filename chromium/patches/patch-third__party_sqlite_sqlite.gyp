$NetBSD: patch-third__party_sqlite_sqlite.gyp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/sqlite/sqlite.gyp.orig	2011-05-24 08:01:29.000000000 +0000
+++ third_party/sqlite/sqlite.gyp
@@ -41,7 +41,7 @@
             ],
           },
         }],
-        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd") and use_system_sqlite', {
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and use_system_sqlite', {
           'type': 'settings',
           'direct_dependent_settings': {
             'cflags': [
@@ -233,7 +233,7 @@
             }, {  # else: OS!="win"
               'sources/': [['exclude', '_(w32|win)\\.cc?$']],
             }],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
               'cflags': [
                 # SQLite doesn't believe in compiler warnings,
                 # preferring testing.
@@ -248,7 +248,7 @@
     },
   ],
   'conditions': [
-    ['(OS=="linux" or OS=="freebsd" or OS=="openbsd") and not use_system_sqlite', {
+    ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and not use_system_sqlite', {
       'targets': [
         {
           'target_name': 'sqlite_shell',
