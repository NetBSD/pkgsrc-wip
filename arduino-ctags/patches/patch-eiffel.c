$NetBSD$

--- eiffel.c.orig	2019-03-25 18:42:04.901095628 +0000
+++ eiffel.c
@@ -807,7 +807,7 @@ static void findKeyword (tokenInfo *cons
 
 static boolean parseType (tokenInfo *const token);
 
-static void parseGeneric (tokenInfo *const token, boolean declaration __unused__)
+static void parseGeneric (tokenInfo *const token, boolean declaration CTAGS_UNUSED)
 {
 	unsigned int depth = 0;
 #ifdef TYPE_REFERENCE_TOOL
