$NetBSD: patch-lib_freebl_blapi.h,v 1.1 2014/09/28 14:20:09 thomasklausner Exp $

--- lib/freebl/blapi.h.orig	2014-09-28 13:54:02.000000000 +0000
+++ lib/freebl/blapi.h
@@ -1189,6 +1189,8 @@ extern void SHA1_DestroyContext(SHA1Cont
 */
 extern void SHA1_Begin(SHA1Context *cx);
 
+#define SHA1_Update NSS_SHA1_Update
+
 /*
 ** Update the SHA-1 hash function with more data.
 **	"cx" the context
