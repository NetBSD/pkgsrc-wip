$NetBSD$

--- routines.h.orig	2019-03-27 16:23:18.950796458 +0000
+++ routines.h
@@ -85,7 +85,7 @@ extern void freeRoutineResources (void);
 extern void setExecutableName (const char *const path);
 extern const char *getExecutableName (void);
 extern const char *getExecutablePath (void);
-extern void error (const errorSelection selection, const char *const format, ...) __printf__ (2, 3);
+extern void error (const errorSelection selection, const char *const format, ...) CTAGS_PRINTF (2, 3);
 
 /* Memory allocation functions */
 #ifdef NEED_PROTO_MALLOC
