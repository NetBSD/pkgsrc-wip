$NetBSD$

Prevent undefined behaviour of tolower().

--- src/fs/file_set.c.orig	2025-12-09 03:51:38.000000000 +0000
+++ src/fs/file_set.c
@@ -73,7 +73,7 @@ static bool GlobMatch(const char *patter
 	case '?':
 		return *s != '\0' && GlobMatch(pattern + 1, s + 1);
 	default:
-		return tolower(*s) == tolower(*pattern) &&
+		return tolower((unsigned char) *s) == tolower((unsigned char) *pattern) &&
 		       GlobMatch(pattern + 1, s + 1);
 	}
 }
