$NetBSD: patch-base_allocator_allocator.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/allocator/allocator.gyp.orig	2011-04-13 08:01:33.000000000 +0000
+++ base/allocator/allocator.gyp
@@ -309,7 +309,7 @@
             '<(tcmalloc_dir)/src/debugallocation.cc',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'sources!': [
             '<(tcmalloc_dir)/src/system-alloc.h',
             '<(tcmalloc_dir)/src/windows/port.cc',
