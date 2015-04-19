$NetBSD: patch-src_prop__object.c,v 1.1 2015/04/19 17:56:54 realzhtw Exp $

--- src/prop_object.c.orig	2015-04-15 21:41:29.000000000 +0000
+++ src/prop_object.c
@@ -834,7 +834,7 @@ _prop_object_externalize_write_file(cons
 		return (false);
 	}
 #else
-	otname = strncat(tname, "/.plistXXXXXX", sizeof(tname));
+	otname = strncat(tname, "/.plistXXXXXX", sizeof(tname) - 1);
 
 	if (sizeof(*otname) >= sizeof(tname)) {
 		errno = ENAMETOOLONG;
