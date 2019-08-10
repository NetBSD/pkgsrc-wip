$NetBSD$

--- src/scanner.c.orig	2019-08-10 13:45:51.656004068 +0000
+++ src/scanner.c
@@ -204,6 +204,7 @@ enum arg_type {
 	INT,
 	UNSIGNED,
 	FIXED,
+	SIZE_T,
 	STRING,
 	OBJECT,
 	ARRAY,
@@ -456,6 +457,8 @@ set_arg_type(struct arg *arg, const char
 {
 	if (strcmp(type, "int") == 0)
 		arg->type = INT;
+	else if (strcmp(type, "size_t") == 0)
+		arg->type = SIZE_T;
 	else if (strcmp(type, "uint") == 0)
 		arg->type = UNSIGNED;
 	else if (strcmp(type, "fixed") == 0)
