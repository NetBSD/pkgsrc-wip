$NetBSD$

--- src/pal/src/include/pal/misc.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/include/pal/misc.h
@@ -48,6 +48,16 @@ Function :
 int __cdecl PAL_rand(void);
 
 /*++
+Function :
+
+    PAL_rand
+    
+    Calls rand and mitigates the difference between RAND_MAX 
+    on Windows and FreeBSD.
+--*/
+PAL_time_t __cdecl PAL_time(PAL_time_t*);
+
+/*++
 Function:
 TIMEInitialize
 
@@ -128,4 +138,3 @@ void MiscUnsetenv(const char *name);
 #endif // __cplusplus
 
 #endif /* __MISC_H_ */
-
