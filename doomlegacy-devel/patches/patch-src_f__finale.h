$NetBSD$

Add support for UMAPINFO.

--- src/f_finale.h.orig	2023-01-10 10:38:38.000000000 +0000
+++ src/f_finale.h
@@ -48,7 +48,8 @@ void F_Ticker (void);
 void F_Drawer (void);
 
 
-void F_StartFinale (void);
+// 2023-02-04: Added parameter for UMAPINFO support
+void F_StartFinale (boolean secretexit);
 
 
 #endif
