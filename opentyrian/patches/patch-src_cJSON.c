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
@@ -316,7 +316,9 @@ static const char *parse_string(cJSON *i
 					
 					switch (len) {
 						case 3: *--ptr2 =((uc | 0x80) & 0xBF); uc >>= 6;
+							/* FALLTHROUGH */
 						case 2: *--ptr2 =((uc | 0x80) & 0xBF); uc >>= 6;
+							/* FALLTHROUGH */
 						case 1: *--ptr2 =(uc | firstByteMark[len]);
 					}
 					ptr2+=len;ptr+=4;
