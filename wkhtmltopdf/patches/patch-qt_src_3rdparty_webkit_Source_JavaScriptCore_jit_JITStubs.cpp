$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_jit_JITStubs.cpp,v 1.1 2014/07/02 21:20:08 fhajny Exp $

Fix building on NetBSD/amd64 with GCC.

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/jit/JITStubs.cpp.orig	2014-06-07 00:54:21.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/jit/JITStubs.cpp
@@ -79,7 +79,7 @@ namespace JSC {
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if (OS(LINUX) || OS(FREEBSD)) && CPU(X86_64)
+#if (OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(SOLARIS)) && CPU(X86_64) || (OS(SOLARIS) && CPU(X86))
 #define SYMBOL_STRING_RELOCATION(name) #name "@plt"
 #elif OS(DARWIN) || (CPU(X86_64) && COMPILER(MINGW) && !GCC_VERSION_AT_LEAST(4, 5, 0))
 #define SYMBOL_STRING_RELOCATION(name) "_" #name
