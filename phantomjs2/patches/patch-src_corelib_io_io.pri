$NetBSD: patch-src_corelib_io_io.pri,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Add NetBSD support
* Add DragonFly support

--- src/qt/qtbase/src/corelib/io/io.pri.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtbase/src/corelib/io/io.pri
@@ -160,7 +160,7 @@ win32 {
         }
 
         !nacl {
-            freebsd-*|mac|darwin-*|openbsd-*:{
+            freebsd-*|mac|darwin-*|openbsd-*|netbsd-*|dragonfly-*:{
                 SOURCES += io/qfilesystemwatcher_kqueue.cpp
                 HEADERS += io/qfilesystemwatcher_kqueue_p.h
             }
