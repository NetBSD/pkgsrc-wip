$NetBSD: patch-src_mongoose_mongoose.pri,v 1.1 2013/06/18 11:02:23 fhajny Exp $

SunOS needs C99.
--- src/mongoose/mongoose.pri.orig	2013-06-03 23:11:50.000000000 +0000
+++ src/mongoose/mongoose.pri
@@ -5,3 +5,4 @@ SOURCES += mongoose.c
 HEADERS += mongoose.h
 linux*:LIBS += -ldl
 win32:LIBS += -lWs2_32
+solaris*:QMAKE_CFLAGS_RELEASE += --std=c99
