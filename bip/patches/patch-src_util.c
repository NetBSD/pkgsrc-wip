$NetBSD$

Fix ctype(3) usage.

--- src/util.c.orig	2012-01-25 10:23:16.000000000 +0000
+++ src/util.c
@@ -88,11 +88,11 @@ char *bip_strdup(const char *str)
 int is_valid_nick(char *str)
 {
 	char *tmp;
-	if (!str || !isalpha(*str))
+	if (!str || !isalpha((unsigned char)*str))
 		return 0;
 
 	tmp = str;
-	while (*tmp != '\0' && (isalnum(*tmp) || *tmp == '-' || *tmp == '[' ||
+	while (*tmp != '\0' && (isalnum((unsigned char)*tmp) || *tmp == '-' || *tmp == '[' ||
 			*tmp == ']' || *tmp == '\\' || *tmp == '`' ||
 			*tmp == '^' || *tmp == '{' || *tmp == '}' ||
 			*tmp == '|' || *tmp == '_' ))
@@ -559,7 +559,7 @@ static unsigned char hash_func(const cha
 	unsigned long hash = 5381; /* 5381 & 0xff makes more sense */
 
 	while ((c = *pkey++))
-		hash = ((hash << 5) + hash) ^ toupper(c);
+		hash = ((hash << 5) + hash) ^ toupper((unsigned char)c);
 	return (unsigned char)hash;
 }
 
@@ -738,7 +738,7 @@ char *bip_strmaydup(char *s)
 void strucase(char *s)
 {
 	while (*s) {
-		*s = toupper(*s);
+		*s = toupper((unsigned char)*s);
 		s++;
 	}
 }
