$NetBSD: patch-src_fingerprint.h,v 1.1 2011/02/17 13:19:17 ftigeot Exp $

--- src/fingerprint.h.orig	2003-05-19 12:16:31 +0000
+++ src/fingerprint.h
@@ -41,7 +41,13 @@ extern int fp_Create( void *handle, cons
 extern int fp_Read( void *handle, const char *fname, int maxngrams );
 extern sint4 fp_Compare( void *cat, void *unknown, int cutoff );
 extern void fp_Show( void *handle );
+#ifdef __cplusplus
+extern "C" {
+#endif
 extern const char *fp_Name( void *handle );
+#ifdef __cplusplus
+}
+#endif
 extern void fp_Print( void *handle, FILE *fp );
 
 #endif
