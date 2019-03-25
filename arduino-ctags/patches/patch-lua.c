$NetBSD$

--- lua.c.orig	2019-03-25 18:42:04.919108182 +0000
+++ lua.c
@@ -37,7 +37,7 @@ static kindOption LuaKinds [] = {
 */
 
 /* for debugging purposes */
-static void __unused__ print_string (char *p, char *q)
+static void CTAGS_UNUSED print_string (char *p, char *q)
 {
 	for ( ; p != q; p++)
 		fprintf (errout, "%c", *p);
