$NetBSD: patch-Source_WTF_wtf_InlineASM.h,v 1.1 2015/02/23 16:11:06 leot1990 Exp $

* Add NetBSD support
* Add Solaris/SunOS support

--- src/qt/qtwebkit/Source/WTF/wtf/InlineASM.h.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WTF/wtf/InlineASM.h
@@ -42,7 +42,7 @@
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if (OS(LINUX) || OS(FREEBSD)) && CPU(X86_64)
+#if (OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(SOLARIS)) && CPU(X86_64) || (OS(SOLARIS) && CPU(X86))
 #define GLOBAL_REFERENCE(name) #name "@plt"
 #elif CPU(X86) && COMPILER(MINGW)
 #define GLOBAL_REFERENCE(name) "@" #name "@4"
