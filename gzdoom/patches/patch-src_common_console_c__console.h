$NetBSD$

--- src/common/console/c_console.h.orig	2022-12-04 14:35:20.000000000 +0000
+++ src/common/console/c_console.h
@@ -68,6 +68,8 @@ void AddToConsole (int printlevel, const
 int PrintString (int printlevel, const char *string);
 int PrintStringHigh (const char *string);
 int VPrintf (int printlevel, const char *format, va_list parms) GCCFORMAT(2);
+int Printf (int printlevel, const char *format, ...);
+int Printf (const char *format, ...);
 
 void C_DrawConsole ();
 void C_ToggleConsole (void);
