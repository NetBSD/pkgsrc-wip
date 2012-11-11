$NetBSD: patch-source_mupen64plus-core_src_main_zip_ioapi.h,v 1.1 2012/11/11 02:32:10 othyro Exp $

Fixes implicit declaration of fopen64, ftello64, and fseeko64 warnings.

--- source/mupen64plus-core/src/main/zip/ioapi.h.orig	2012-03-10 18:31:29.000000000 +0000
+++ source/mupen64plus-core/src/main/zip/ioapi.h
@@ -58,6 +58,10 @@
   #define ftello64 ftell
   #define fseeko64 fseek
  #endif
+#else
+  #define fopen64 fopen
+  #define ftello64 ftello
+  #define fseeko64 fseeko
 #endif
 #endif
 
