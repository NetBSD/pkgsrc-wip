$NetBSD$

Build this file unconditionally, and gross hack to add symbols referenced from the included
binary blob libraries.

--- src/linux_cmn.c.orig	2020-10-02 00:24:42.000000000 +0000
+++ src/linux_cmn.c
@@ -28,7 +28,7 @@
 /*                                                                                      */
 /*******************************************|********************************************/
 
-#if defined (unix) || (__unix)
+#if defined (unix) || (__unix__)
 /*------------------------------------  Includes   -------------------------------------*/
 /*******************************************|********************************************/
 #include "epson-escpr-def.h"
@@ -312,3 +312,13 @@ void TermMutex(void)
 /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
 /***** End of File *** End of File *** End of File *** End of File *** End of File ******/
 /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
+
+void __assert_fail(const char *__assertion, const char *__file, unsigned int __line, const char *__function) {
+	fprintf(stderr, "assertion \"%s\" failed: file \"%s\", line %d, function \"%s\"\n",
+		__assertion, __file, __line, __function);
+	abort();
+}
+
+#undef stdout
+extern FILE *stdout;
+FILE *stdout = &__sF[1];
