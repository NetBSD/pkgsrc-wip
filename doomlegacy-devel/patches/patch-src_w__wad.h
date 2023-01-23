$NetBSD$

Add support for UMAPINFO.

--- src/w_wad.h.orig	2023-01-10 10:38:38.000000000 +0000
+++ src/w_wad.h
@@ -308,8 +308,9 @@ typedef struct {
   int         firstlump;
   int         numlumps;
 } lumplist_t;
-                    
+
 void    W_Load_DehackedLumps( int wadnum );
+void    W_Load_UMapInfoLumps( int wadnum );
 
 
 
