$NetBSD: patch-src_cJSON.c,v 1.1 2015/08/19 19:36:56 yhardy Exp $

Fix isspace() usage on NetBSD (compiled with -Werror).

--- src/cJSON.c.orig	2013-09-07 22:14:32.000000000 +0000
+++ src/cJSON.c
@@ -131,7 +131,7 @@ static inline const char *parse_object( 
 static inline const char *skip_space( const char *str )
 {
 	if (str != NULL)
-		while (isspace(*str))
+		while (isspace((int)*str))
 			++str;
 	return str;
 }
