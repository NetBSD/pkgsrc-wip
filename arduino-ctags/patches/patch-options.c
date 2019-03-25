$NetBSD$

--- options.c.orig	2019-03-25 18:42:04.927352569 +0000
+++ options.c
@@ -731,7 +731,7 @@ static void processEtagsInclude (
 }
 
 static void processExcludeOption (
-		const char *const option __unused__, const char *const parameter)
+		const char *const option CTAGS_UNUSED, const char *const parameter)
 {
 	const char *const fileName = parameter + 1;
 	if (parameter [0] == '\0')
@@ -869,7 +869,7 @@ static void processFieldsOption (
 }
 
 static void processFilterTerminatorOption (
-		const char *const option __unused__, const char *const parameter)
+		const char *const option CTAGS_UNUSED, const char *const parameter)
 {
 	freeString (&Option.filterTerminator);
 	Option.filterTerminator = stringCopy (parameter);
@@ -932,8 +932,8 @@ static void printProgramIdentification (
 }
 
 static void processHelpOption (
-		const char *const option __unused__,
-		const char *const parameter __unused__)
+		const char *const option CTAGS_UNUSED,
+		const char *const parameter CTAGS_UNUSED)
 {
 	printProgramIdentification ();
 	putchar ('\n');
@@ -1141,8 +1141,8 @@ static void processLanguagesOption (
 }
 
 static void processLicenseOption (
-		const char *const option __unused__,
-		const char *const parameter __unused__)
+		const char *const option CTAGS_UNUSED,
+		const char *const parameter CTAGS_UNUSED)
 {
 	printProgramIdentification ();
 	puts ("");
@@ -1168,8 +1168,8 @@ static void processListKindsOption (
 }
 
 static void processListMapsOption (
-		const char *const __unused__ option,
-		const char *const __unused__ parameter)
+		const char *const CTAGS_UNUSED option,
+		const char *const CTAGS_UNUSED parameter)
 {
 	if (parameter [0] == '\0' || strcasecmp (parameter, "all") == 0)
 	    printLanguageMaps (LANG_AUTO);
@@ -1185,8 +1185,8 @@ static void processListMapsOption (
 }
 
 static void processListLanguagesOption (
-		const char *const option __unused__,
-		const char *const parameter __unused__)
+		const char *const option CTAGS_UNUSED,
+		const char *const parameter CTAGS_UNUSED)
 {
 	printLanguageList ();
 	exit (0);
@@ -1360,8 +1360,8 @@ static void processIgnoreOption (const c
 }
 
 static void processVersionOption (
-		const char *const option __unused__,
-		const char *const parameter __unused__)
+		const char *const option CTAGS_UNUSED,
+		const char *const parameter CTAGS_UNUSED)
 {
 	printProgramIdentification ();
 	exit (0);
