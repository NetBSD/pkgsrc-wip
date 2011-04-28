$NetBSD: patch-ipc_ipc.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- ipc/ipc.gyp.orig	2011-04-13 08:01:34.000000000 +0000
+++ ipc/ipc.gyp
@@ -13,7 +13,7 @@
       ['exclude', '/win_[^/]*\\.cc$'],
     ],
     'conditions': [
-      ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {'sources/': [
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {'sources/': [
         ['include', '_posix(_unittest)?\\.cc$'],
       ]}],
       ['OS=="mac"', {'sources/': [
@@ -58,12 +58,10 @@
         'sync_socket_unittest.cc',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
-        }],
-        ['OS=="linux"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
