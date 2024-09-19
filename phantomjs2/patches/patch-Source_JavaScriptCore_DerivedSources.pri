$NetBSD: patch-Source_JavaScriptCore_DerivedSources.pri,v 1.1 2015/02/23 16:11:06 leot1990 Exp $

* Make conditional for Unix

--- src/qt/qtwebkit/Source/JavaScriptCore/DerivedSources.pri.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/JavaScriptCore/DerivedSources.pri
@@ -108,7 +108,7 @@ llint.depends = $$LLINT_DEPENDENCY
 llint.commands = ruby $$llint.script $$LLINT_ASSEMBLER ${QMAKE_FILE_IN} ${QMAKE_FILE_OUT}
 GENERATORS += llint
 
-linux-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
+unix-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
     # GENERATOR: disassembler
     disassembler.output = udis86_itab.c
     disassembler.input = DISASSEMBLER_FILES
