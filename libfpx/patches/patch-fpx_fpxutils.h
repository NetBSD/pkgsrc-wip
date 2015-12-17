$NetBSD$
* __unix is not defined on NetBSD, _UNIX is always defined by the build system
--- fpx/fpxutils.h.orig	2013-09-02 15:45:00.000000000 +0000
+++ fpx/fpxutils.h
@@ -471,7 +471,7 @@
   #define DefaultPaletteSize  256     // Default size of Palette
   
 // Define window DIB structures  
-#if defined(macintosh) || defined(__unix) 
+#if defined(macintosh) || defined(_UNIX) 
 
   // Bitmap information header
   typedef struct tagBITMAPINFOHEADER
