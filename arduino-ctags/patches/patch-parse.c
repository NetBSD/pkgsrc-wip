$NetBSD$

--- parse.c.orig	2019-03-25 18:42:04.929085191 +0000
+++ parse.c
@@ -376,7 +376,7 @@ extern void freeParserResources (void)
 */
 
 extern void processLanguageDefineOption (
-		const char *const option, const char *const parameter __unused__)
+		const char *const option, const char *const parameter CTAGS_UNUSED)
 {
 #ifdef HAVE_REGEX
 	if (parameter [0] == '\0')
