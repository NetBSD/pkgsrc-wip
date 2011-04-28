$NetBSD: patch-webkit_tools_test__shell_test__shell.gypi,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- webkit/tools/test_shell/test_shell.gypi.orig	2011-04-13 08:01:08.000000000 +0000
+++ webkit/tools/test_shell/test_shell.gypi
@@ -128,7 +128,7 @@
             'copy_npapi_test_plugin',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             'test_shell_resources',
             '<(DEPTH)/build/linux/system.gyp:gtk',
@@ -170,7 +170,7 @@
         'pak_path': '<(INTERMEDIATE_DIR)/repack/test_shell.pak',
       },
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'actions': [
             {
               'action_name': 'test_shell_repack',
@@ -274,7 +274,7 @@
             },
           },
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -455,7 +455,7 @@
             },
           },
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             'test_shell_pak',
             '<(DEPTH)/build/linux/system.gyp:gtk',
@@ -492,7 +492,7 @@
             '../../../skia/ext/vector_canvas_unittest.cc',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -609,13 +609,13 @@
                 ],
               },
             }],
-            ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
               'sources!': [
                 # Needs simple event record type porting
                 '../../plugins/npapi/test/plugin_windowless_test.cc',
               ],
             }],
-            ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris") and (target_arch=="x64" or target_arch=="arm")', {
+            ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris") and (target_arch=="x64" or target_arch=="arm")', {
               # Shared libraries need -fPIC on x86-64
               'cflags': ['-fPIC']
             }],
@@ -644,7 +644,7 @@
                 },
               ]
             }],
-            ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
               'copies': [
                 {
                   'destination': '<(PRODUCT_DIR)/plugins',
@@ -656,7 +656,7 @@
         },
       ],
     }],
-    ['OS=="linux"  or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+    ['OS=="linux"  or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
       'targets': [
         {
           'target_name': 'test_shell_resources',
