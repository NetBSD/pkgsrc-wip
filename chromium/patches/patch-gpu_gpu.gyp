$NetBSD: patch-gpu_gpu.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- gpu/gpu.gyp.orig	2011-04-13 08:01:09.000000000 +0000
+++ gpu/gpu.gyp
@@ -214,7 +214,7 @@
         'command_buffer/service/texture_manager.cc',
       ],
       'conditions': [
-        ['OS == "linux"', {
+        ['OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
