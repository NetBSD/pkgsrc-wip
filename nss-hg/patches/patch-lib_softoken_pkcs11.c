$NetBSD: patch-lib_softoken_pkcs11.c,v 1.1 2014/10/01 08:24:20 thomasklausner Exp $

Fix
pkcs11.c: In function 'sftk_handlePublicKeyObject':
pkcs11.c:972:5: error: expected expression before '/' token
     // Check that an imported EC key is valid
     ^

--- lib/softoken/pkcs11.c.orig	2014-10-01 07:23:34.000000000 +0000
+++ lib/softoken/pkcs11.c
@@ -969,7 +969,7 @@ sftk_handlePublicKeyObject(SFTKSession *
     }
     object->infoFree = (SFTKFree) nsslowkey_DestroyPublicKey;
 
-    // Check that an imported EC key is valid
+    /* Check that an imported EC key is valid */
     if (key_type == CKK_EC) {
       NSSLOWKEYPublicKey *pubKey = (NSSLOWKEYPublicKey*) object->objectInfo;
       SECStatus rv = EC_ValidatePublicKey(&pubKey->u.ec.ecParams,
