$NetBSD: patch-src__sphinxstd.cpp,v 1.1 2012/01/31 12:56:40 fhajny Exp $

NetBSD doesn't expose PTHREAD_STACK_MIN
--- src/sphinxstd.cpp.orig	2011-11-13 12:36:32.000000000 +0000
+++ src/sphinxstd.cpp
@@ -1045,7 +1045,7 @@ void * sphMyStack ()
 
 int sphMyStackSize ()
 {
-#if USE_WINDOWS
+#if USE_WINDOWS || !defined(PTHREAD_STACK_MIN)
 	return g_iThreadStackSize;
 #else
 	return PTHREAD_STACK_MIN + g_iThreadStackSize;
