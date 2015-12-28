$NetBSD$

--- fpx/fpxlibio.cpp.orig	2015-12-28 09:48:01.000000000 +0000
+++ fpx/fpxlibio.cpp
@@ -66,7 +66,7 @@
 #ifndef FlashPixJPEG_h
   #include "fpxjpeg.h"
 #endif
-#if defined(__unix) // for CoFileTimeNow
+#if defined(_UNIX) // for CoFileTimeNow
   #include "time.hxx"
 #endif
 
