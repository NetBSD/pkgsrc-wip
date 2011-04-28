$NetBSD: patch-ppapi_proxy_serialized__structs.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- ppapi/proxy/serialized_structs.h.orig	2011-04-13 08:01:10.000000000 +0000
+++ ppapi/proxy/serialized_structs.h
@@ -102,7 +102,7 @@ struct PPBFlash_DrawGlyphs_Params {
 
 #if defined(OS_WIN)
 typedef HANDLE ImageHandle;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
 typedef base::SharedMemoryHandle ImageHandle;
 #else
 // On X Windows this is a SysV shared memory key.
