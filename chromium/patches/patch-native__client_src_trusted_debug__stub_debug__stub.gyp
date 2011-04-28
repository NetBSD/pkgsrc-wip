$NetBSD: patch-native__client_src_trusted_debug__stub_debug__stub.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- native_client/src/trusted/debug_stub/debug_stub.gyp.orig	2011-04-13 08:13:06.000000000 +0000
+++ native_client/src/trusted/debug_stub/debug_stub.gyp
@@ -16,7 +16,7 @@
       'transport_common.cc',
     ],
     'conditions': [
-      ['OS=="linux" or OS=="mac"', {
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="mac"', {
         'platform_sources': [
           'posix/debug_stub_posix.cc',
           'posix/mutex_impl.cc',
@@ -40,7 +40,7 @@
       'target_base': 'none',
     },
     'target_conditions': [
-      ['OS=="linux" or OS=="mac"', {
+      ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="mac"', {
         'cflags': [
           '-Wno-long-long',
         ],
