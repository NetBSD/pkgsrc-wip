$NetBSD$

Add support for UMAPINFO.

--- src/d_main.c.orig	2023-03-19 11:31:58.068883902 +0000
+++ src/d_main.c
@@ -3570,6 +3570,10 @@ void D_Quit_Save ( quit_severity_e sever
 void I_Quit (void)
 {
     D_Quit_Save( QUIT_normal );
+
+    // [MB] 2023-03-19: Support for UMAPINFO added
+    UMI_DestroyUMapInfo();
+
     I_Quit_System();  // No Return
 }
 
