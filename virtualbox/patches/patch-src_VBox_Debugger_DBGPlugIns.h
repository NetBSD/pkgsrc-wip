$NetBSD$

--- src/VBox/Debugger/DBGPlugIns.h.orig	2016-03-04 19:25:46.000000000 +0000
+++ src/VBox/Debugger/DBGPlugIns.h
@@ -26,6 +26,7 @@
 RT_C_DECLS_BEGIN
 
 //extern const DBGFOSREG g_DBGDiggerFreeBSD;
+//extern const DBGFOSREG g_DBGDiggerNetBSD;
 extern const DBGFOSREG g_DBGDiggerDarwin;
 extern const DBGFOSREG g_DBGDiggerLinux;
 extern const DBGFOSREG g_DBGDiggerOS2;
@@ -35,4 +36,3 @@ extern const DBGFOSREG g_DBGDiggerWinNt;
 RT_C_DECLS_END
 
 #endif
-
