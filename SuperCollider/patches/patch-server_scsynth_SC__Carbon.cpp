$NetBSD: patch-server_scsynth_SC__Carbon.cpp,v 1.1 2014/09/06 22:22:37 thomasklausner Exp $

Add NetBSD support.

--- server/scsynth/SC_Carbon.cpp.orig	2013-11-27 12:54:02.000000000 +0000
+++ server/scsynth/SC_Carbon.cpp
@@ -128,7 +128,7 @@ bool sc_HasVectorUnit()
 void sc_SetDenormalFlags()
 {
 }
-#elif (defined(__linux__) || defined(__FreeBSD__)) && defined(__SSE__)
+#elif (defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)) && defined(__SSE__)
 # include <xmmintrin.h>
 
 // cpuid function that works with -fPIC from `minor' at http://red-bean.com
