$NetBSD$

--- options.h.orig	2019-03-27 16:23:18.943625075 +0000
+++ options.h
@@ -123,7 +123,7 @@ extern CONST_OPTION optionValues		Option
 /*
 *   FUNCTION PROTOTYPES
 */
-extern void verbose (const char *const format, ...) __printf__ (1, 2);
+extern void verbose (const char *const format, ...) CTAGS_PRINTF (1, 2);
 extern void freeList (stringList** const pString);
 extern void setDefaultTagFileName (void);
 extern void checkOptions (void);
