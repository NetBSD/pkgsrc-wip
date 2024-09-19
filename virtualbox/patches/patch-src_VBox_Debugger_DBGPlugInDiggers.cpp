$NetBSD$

--- src/VBox/Debugger/DBGPlugInDiggers.cpp.orig	2016-03-04 19:25:46.000000000 +0000
+++ src/VBox/Debugger/DBGPlugInDiggers.cpp
@@ -33,6 +33,7 @@ DECLEXPORT(int) DbgPlugInEntry(DBGFPLUGI
     {
         &g_DBGDiggerDarwin,
         //&g_DBGDiggerFreeBSD,
+        //&g_DBGDiggerNetBSD,
         &g_DBGDiggerLinux,
         &g_DBGDiggerOS2,
         &g_DBGDiggerSolaris,
@@ -74,4 +75,3 @@ DECLEXPORT(int) DbgPlugInEntry(DBGFPLUGI
             return VERR_NOT_SUPPORTED;
     }
 }
-
