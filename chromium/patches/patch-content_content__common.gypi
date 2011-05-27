$NetBSD: patch-content_content__common.gypi,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- content/content_common.gypi.orig	2011-05-24 08:01:07.000000000 +0000
+++ content/content_common.gypi
@@ -76,7 +76,7 @@
             'common/file_path_watcher/file_path_watcher_inotify.cc',
           ],
         }],
-        ['OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'sources': [
             'common/file_path_watcher/file_path_watcher_stub.cc',
           ],
