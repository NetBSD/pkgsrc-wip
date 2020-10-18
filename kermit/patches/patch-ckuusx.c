$NetBSD: patch-am,v 1.1 2011/05/14 19:27:53 hans Exp $

--- ckuusx.c.orig	2020-09-19 19:52:28.000000000 +0000
+++ ckuusx.c
@@ -79,9 +79,6 @@ char * tgoto (const char *, int, int);
 _PROTOTYP(char * os2_gethostname, (void));
 #define getpid _getpid
 #endif /* OS2 */
-#ifdef BSD44
-#include <errno.h>
-#endif /* BSD44 */
 
 extern xx_strp xxstring;
 
