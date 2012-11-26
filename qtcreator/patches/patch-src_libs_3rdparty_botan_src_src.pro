$NetBSD: patch-src_libs_3rdparty_botan_src_src.pro,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Build similar to Linux and FreeBSD, using the netbsd* qmake makespec
that is defined for all pkgsrc targets.

--- src/libs/3rdparty/botan/src/src.pro.orig	2012-08-08 13:47:06.000000000 +0000
+++ src/libs/3rdparty/botan/src/src.pro
@@ -282,7 +282,7 @@ unix {
            timer/gettimeofday/tm_unix.h
 }
 
-linux*-g++*|freebsd*-g++* {
+linux*-g++*|freebsd*-g++*|netbsd*-g++* {
     HEADERS += timer/posix_rt/tm_posix.h
 }
 
@@ -566,7 +566,7 @@ unix {
            timer/gettimeofday/tm_unix.cpp
 }
 
-linux*|freebsd* {
+linux*|freebsd*|netbsd* {
     SOURCES += timer/posix_rt/tm_posix.cpp
 
     LIBS += -lrt
