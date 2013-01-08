$NetBSD: patch-src_AudioIO.cpp,v 1.1 2013/01/08 22:37:27 makoto Exp $

--- src/AudioIO.cpp.orig	2012-08-21 17:48:21.000000000 +0900
+++ src/AudioIO.cpp	2013-01-08 22:21:56.000000000 +0900
@@ -271,6 +271,10 @@ writing audio.
 #include <stdlib.h>
 #include <algorithm>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #ifdef __WXMSW__
 #include <malloc.h>
 #endif
