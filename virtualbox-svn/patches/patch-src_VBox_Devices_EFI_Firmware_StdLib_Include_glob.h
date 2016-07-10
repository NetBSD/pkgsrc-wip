$NetBSD$

--- src/VBox/Devices/EFI/Firmware/StdLib/Include/glob.h.orig	2016-03-04 19:27:22.000000000 +0000
+++ src/VBox/Devices/EFI/Firmware/StdLib/Include/glob.h
@@ -101,8 +101,8 @@ typedef struct {
 __BEGIN_DECLS
 #ifndef __LIBC12_SOURCE__
 int	glob(const char * __restrict, int,
-    int (*)(const char *, int), glob_t * __restrict)	 __RENAME(__glob30);
-void	globfree(glob_t *)				 __RENAME(__globfree30);
+    int (*)(const char *, int), glob_t * __restrict)	 ;//__RENAME(__glob30);
+void	globfree(glob_t *)				 ;//__RENAME(__globfree30);
 #endif
 __END_DECLS
 
