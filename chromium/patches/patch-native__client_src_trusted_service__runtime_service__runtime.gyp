$NetBSD: patch-native__client_src_trusted_service__runtime_service__runtime.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- native_client/src/trusted/service_runtime/service_runtime.gyp.orig	2011-04-13 08:13:10.000000000 +0000
+++ native_client/src/trusted/service_runtime/service_runtime.gyp
@@ -6,7 +6,7 @@
 {
   'variables': {
     'conditions': [
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
         'syscall_handler': [
           'linux/nacl_syscall_impl.c'
         ],
@@ -32,7 +32,7 @@
       'target_base': 'none',
     },
     'target_conditions': [
-      ['OS=="linux" or OS=="mac"', {
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="mac"', {
         'cflags': [
           '-fexceptions',
         ],
@@ -162,7 +162,7 @@
                 }],
               ],
             }],
-            ['OS=="linux" or OS=="mac" or OS=="FreeBSD"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="mac"', {
               'sources': [
                 'posix/nacl_signal.c',
                ],
