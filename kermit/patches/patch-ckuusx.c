$NetBSD: patch-am,v 1.1 2011/05/14 19:27:53 hans Exp $

This patch needs an explanation, and perhaps trying to build without it.

Not yet submitted upstream.

--- ckuusx.c.orig	2022-09-26 17:53:45.000000000 +0000
+++ ckuusx.c
@@ -99,10 +99,6 @@ _PROTOTYP(int ck_tn_encrypting, (void));
 _PROTOTYP(int ck_tn_decrypting, (void));
 #endif /* CK_ENCRYPTION */
 
-#ifdef BSD44
-#include <errno.h>
-#endif /* BSD44 */
-
 extern xx_strp xxstring;
 
 #ifdef OS2
