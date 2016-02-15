$NetBSD$

--- src/pal/src/misc/dbgmsg.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/misc/dbgmsg.cpp
@@ -475,7 +475,7 @@ Notes :
 int DBG_printf_gcc(DBG_CHANNEL_ID channel, DBG_LEVEL_ID level, BOOL bHeader,
                    LPCSTR function, LPCSTR file, INT line, LPCSTR format, ...)
 {
-    CHAR *buffer = (CHAR*)alloca(DBG_BUFFER_SIZE);
+    CHAR *buffer = (CHAR*)Alloca(DBG_BUFFER_SIZE);
     CHAR indent[MAX_NESTING+1];
     LPSTR buffer_ptr;
     INT output_size;
@@ -593,7 +593,7 @@ Notes :
 int DBG_printf_c99(DBG_CHANNEL_ID channel, DBG_LEVEL_ID level, BOOL bHeader,
                    LPSTR file, INT line, LPSTR format, ...)
 {
-    CHAR *buffer = (CHAR*)alloca(DBG_BUFFER_SIZE);
+    CHAR *buffer = (CHAR*)Alloca(DBG_BUFFER_SIZE);
     CHAR indent[MAX_NESTING+1];
     LPSTR buffer_ptr;
     INT output_size;
@@ -941,7 +941,7 @@ void PAL_DisplayDialogFormatted(const ch
     va_start(args, szTextFormat);
 
     const int cchBuffer = 4096;
-    char *szBuffer = (char*)alloca(cchBuffer);
+    char *szBuffer = (char*)Alloca(cchBuffer);
     PAL__vsnprintf(szBuffer, cchBuffer, szTextFormat, args);
     PAL_DisplayDialog(szTitle, szBuffer);
 
