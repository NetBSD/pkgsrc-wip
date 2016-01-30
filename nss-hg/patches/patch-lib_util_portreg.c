$NetBSD$

Missing ctype(3) casts.

--- lib/util/portreg.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/util/portreg.c
@@ -277,7 +277,7 @@ _shexp_match(const char *str, const char
 		    if (exp[y] == '\\')
 			++y;
 		    if(case_insensitive) {
-			matched |= (toupper(str[x]) == toupper(exp[y]));
+			matched |= (toupper((unsigned char)str[x]) == toupper((unsigned char)exp[y]));
 		    } else {
 			matched |= (str[x] == exp[y]);
 		    }
@@ -302,7 +302,7 @@ _shexp_match(const char *str, const char
 	    /* fall through */
 	default:
 	    if(case_insensitive) {
-		if(toupper(str[x]) != toupper(exp[y]))
+		if(toupper((unsigned char)str[x]) != toupper((unsigned char)exp[y]))
 		    return NOMATCH;
 	    } else {
 		if(str[x] != exp[y])
