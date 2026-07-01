$NetBSD$

Prevent undefined behaviour of isalnum(), tolower() and isspace().

--- src/pager/help.c.orig	2025-12-09 03:51:38.000000000 +0000
+++ src/pager/help.c
@@ -136,8 +136,8 @@ static char *AnchorName(const char *line
 
 	result = checked_strdup(line);
 	for (p = result, q = result; *p != '\0'; ++p) {
-		if (isalnum(*p)) {
-			*q = tolower(*p);
+		if (isalnum((unsigned char) *p)) {
+			*q = tolower((unsigned char) *p);
 			++q;
 		} else if (*p == ' ' || *p == '-') {
 			*q = '-';
@@ -431,7 +431,7 @@ static const char *DrawBoldText(WINDOW *
 static bool IsHorizRule(const char *s)
 {
 	while (*s != '\0') {
-		if (!isspace(*s) && *s != '-') {
+		if (!isspace((unsigned char) *s) && *s != '-') {
 			return false;
 		}
 		++s;
@@ -442,10 +442,10 @@ static bool IsHorizRule(const char *s)
 
 static bool IsBulletPoint(const char *s)
 {
-	while (*s != '\0' && isspace(*s)) {
+	while (*s != '\0' && isspace((unsigned char) *s)) {
 		++s;
 	}
-	return s[0] == '*' && isspace(s[1]);
+	return s[0] == '*' && isspace((unsigned char) s[1]);
 }
 
 static void DrawHelpLine(WINDOW *win, unsigned int lineno, void *user_data)
@@ -482,7 +482,7 @@ static void DrawHelpLine(WINDOW *win, un
 	p = line;
 
 	if (IsBulletPoint(line)) {
-		while (isspace(*p) || (p[0] == '*' && isspace(p[1]))) {
+		while (isspace((unsigned char) *p) || (p[0] == '*' && isspace((unsigned char) p[1]))) {
 			waddch(win, *p == '*' ? ACS_BULLET : ' ');
 			++p;
 		}
