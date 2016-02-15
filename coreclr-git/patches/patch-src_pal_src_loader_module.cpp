$NetBSD$

--- src/pal/src/loader/module.cpp.orig	2016-02-13 00:18:27.000000000 +0000
+++ src/pal/src/loader/module.cpp
@@ -315,7 +315,7 @@ GetProcAddress(
     if (pal_module && module->dl_handle == pal_module->dl_handle)
     {
         int iLen = 4 + strlen(lpProcName) + 1;
-        LPSTR lpPALProcName = (LPSTR) alloca(iLen);
+        LPSTR lpPALProcName = (LPSTR) Alloca(iLen);
 
         if (strcpy_s(lpPALProcName, iLen, "PAL_") != SAFECRT_SUCCESS)
         {
