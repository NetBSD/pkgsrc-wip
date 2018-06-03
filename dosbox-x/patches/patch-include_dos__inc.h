$NetBSD$

Use ftello and fseeko on NetBSD.

--- include/dos_inc.h.orig	2018-06-01 19:29:54.000000000 +0000
+++ include/dos_inc.h
@@ -295,6 +295,10 @@ static INLINE Bit16u DOS_PackDate(Bit16u
   #define ftello64 ftell
   #define fseeko64 fseek
  #endif
+#elif defined(__NetBSD__)
+ #define fopen64 fopen
+ #define ftello64 ftello
+ #define fseeko64 fseeko
 #endif
 
 /* Dos Error Codes */
