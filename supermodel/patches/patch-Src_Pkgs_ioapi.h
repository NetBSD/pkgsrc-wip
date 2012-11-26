$NetBSD: patch-Src_Pkgs_ioapi.h,v 1.1 2012/11/26 19:46:21 othyro Exp $

Fix implicit declaration of fopen64, ftello64, and fseeko64.

--- Src/Pkgs/ioapi.h.orig	2011-04-23 18:14:02.000000000 +0000
+++ Src/Pkgs/ioapi.h
@@ -58,6 +58,10 @@
   #define ftello64 ftell
   #define fseeko64 fseek
  #endif
+#else
+ #define fopen64 fopen
+ #define ftello64 ftello
+ #define fseeko64 fseeko
 #endif
 #endif
 
