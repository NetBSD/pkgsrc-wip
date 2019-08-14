$NetBSD$

wine-4.13 doesn't throw page_fault and hence the exception handler isn't used

--- dlls/ntdll/loader.c.orig	2019-08-13 22:46:25.481501462 +0000
+++ dlls/ntdll/loader.c
@@ -3512,6 +3512,9 @@ PIMAGE_NT_HEADERS WINAPI RtlImageNtHeade
 {
     IMAGE_NT_HEADERS *ret;
 
+    if (!hModule)
+	    return NULL;
+    
     __TRY
     {
         IMAGE_DOS_HEADER *dos = (IMAGE_DOS_HEADER *)hModule;
