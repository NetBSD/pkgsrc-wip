$NetBSD: patch-Source_JavaScriptCore_Target.pri,v 1.1 2015/02/23 16:11:06 leot1990 Exp $

* Libtoolized
* Build as shared library
* Install libJavaScriptCore library
* Make conditionals for Unix

--- src/qt/qtwebkit/Source/JavaScriptCore/Target.pri.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/JavaScriptCore/Target.pri
@@ -14,6 +14,8 @@ QT += core
 QT -= gui
 
 CONFIG += staticlib optimize_full
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 # Rules when JIT enabled (not disabled)
 !contains(DEFINES, ENABLE_JIT=0) {
@@ -326,7 +328,7 @@ SOURCES += \
     tools/CodeProfiling.cpp \
     yarr/YarrJIT.cpp \
 
-linux-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
+unix-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
     SOURCES += \
         disassembler/UDis86Disassembler.cpp \
         disassembler/udis86/udis86.c \
