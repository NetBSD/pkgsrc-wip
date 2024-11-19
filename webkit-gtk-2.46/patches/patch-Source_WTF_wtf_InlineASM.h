$NetBSD$

--- Source/WTF/wtf/InlineASM.h.orig	2024-08-19 06:28:38.531298000 +0000
+++ Source/WTF/wtf/InlineASM.h
@@ -43,7 +43,7 @@
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if (OS(LINUX) || OS(FREEBSD) || OS(QNX)) && CPU(X86_64)
+#if (OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(QNX)) && CPU(X86_64)
 #define GLOBAL_REFERENCE(name) #name "@plt"
 #elif OS(LINUX) && CPU(X86) && defined(__PIC__)
 #define GLOBAL_REFERENCE(name) SYMBOL_STRING(name) "@plt"
