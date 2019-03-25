$NetBSD$

--- python.c.orig	2019-03-25 18:42:04.934404064 +0000
+++ python.c
@@ -135,7 +135,7 @@ static boolean isIdentifierCharacter (in
  * extract all relevant information and create a tag.
  */
 static void makeFunctionTag (vString *const function,
-	vString *const parent, int is_class_parent, const char *arglist __unused__)
+	vString *const parent, int is_class_parent, const char *arglist CTAGS_UNUSED)
 {
 	tagEntryInfo tag;
 	initTagEntry (&tag, vStringValue (function));
