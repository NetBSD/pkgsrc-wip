$NetBSD$

--- coregrind/vg_preloaded.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/vg_preloaded.c
@@ -210,6 +210,8 @@ void VG_REPLACE_FUNCTION_ZU(libSystemZdZ
     // but don't care if it's initialized
 }
 
+#elif defined(VGO_netbsd)
+#warning not implemented
 #elif defined(VGO_solaris)
 
 /* Declare the errno and environ symbols weakly in case the client is not
