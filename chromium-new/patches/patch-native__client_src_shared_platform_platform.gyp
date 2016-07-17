$NetBSD$

--- native_client/src/shared/platform/platform.gyp.orig	2016-06-24 01:03:26.000000000 +0000
+++ native_client/src/shared/platform/platform.gyp
@@ -36,7 +36,7 @@
       'refcount_base.cc',
     ],
     'conditions': [
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or OS=="freebsd"', {
         'platform_sources': [
           'linux/nacl_clock.c',
           'linux/nacl_host_dir.c',
