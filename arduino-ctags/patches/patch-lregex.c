$NetBSD$

--- lregex.c.orig	2019-03-25 18:42:04.917758680 +0000
+++ lregex.c
@@ -538,11 +538,11 @@ extern void findRegexTags (void)
 #endif  /* HAVE_REGEX */
 
 extern void addTagRegex (
-		const langType language __unused__,
-		const char* const regex __unused__,
-		const char* const name __unused__,
-		const char* const kinds __unused__,
-		const char* const flags __unused__)
+		const langType language CTAGS_UNUSED,
+		const char* const regex CTAGS_UNUSED,
+		const char* const name CTAGS_UNUSED,
+		const char* const kinds CTAGS_UNUSED,
+		const char* const flags CTAGS_UNUSED)
 {
 #ifdef HAVE_REGEX
 	Assert (regex != NULL);
@@ -564,10 +564,10 @@ extern void addTagRegex (
 }
 
 extern void addCallbackRegex (
-		const langType language __unused__,
-		const char* const regex __unused__,
-		const char* const flags __unused__,
-		const regexCallback callback __unused__)
+		const langType language CTAGS_UNUSED,
+		const char* const regex CTAGS_UNUSED,
+		const char* const flags CTAGS_UNUSED,
+		const regexCallback callback CTAGS_UNUSED)
 {
 #ifdef HAVE_REGEX
 	Assert (regex != NULL);
@@ -581,7 +581,7 @@ extern void addCallbackRegex (
 }
 
 extern void addLanguageRegex (
-		const langType language __unused__, const char* const regex __unused__)
+		const langType language CTAGS_UNUSED, const char* const regex CTAGS_UNUSED)
 {
 #ifdef HAVE_REGEX
 	if (! regexBroken)
@@ -602,7 +602,7 @@ extern void addLanguageRegex (
 */
 
 extern boolean processRegexOption (const char *const option,
-								   const char *const parameter __unused__)
+								   const char *const parameter CTAGS_UNUSED)
 {
 	boolean handled = FALSE;
 	const char* const dash = strchr (option, '-');
@@ -624,7 +624,7 @@ extern boolean processRegexOption (const
 	return handled;
 }
 
-extern void disableRegexKinds (const langType language __unused__)
+extern void disableRegexKinds (const langType language CTAGS_UNUSED)
 {
 #ifdef HAVE_REGEX
 	if (language <= SetUpper  &&  Sets [language].count > 0)
@@ -639,8 +639,8 @@ extern void disableRegexKinds (const lan
 }
 
 extern boolean enableRegexKind (
-		const langType language __unused__,
-		const int kind __unused__, const boolean mode __unused__)
+		const langType language CTAGS_UNUSED,
+		const int kind CTAGS_UNUSED, const boolean mode CTAGS_UNUSED)
 {
 	boolean result = FALSE;
 #ifdef HAVE_REGEX
@@ -660,7 +660,7 @@ extern boolean enableRegexKind (
 	return result;
 }
 
-extern void printRegexKinds (const langType language __unused__, boolean indent __unused__)
+extern void printRegexKinds (const langType language CTAGS_UNUSED, boolean indent CTAGS_UNUSED)
 {
 #ifdef HAVE_REGEX
 	if (language <= SetUpper  &&  Sets [language].count > 0)
