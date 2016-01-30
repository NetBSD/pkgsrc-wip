$NetBSD$

Missing ctype(3) casts.

--- lib/certdb/alg1485.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/certdb/alg1485.c
@@ -1343,7 +1343,7 @@ CERT_GetCertificateEmailAddress(CERTCert
     }
     if (rawEmailAddr) {
         for (i = 0; i <= (int)PORT_Strlen(rawEmailAddr); i++) {
-            rawEmailAddr[i] = tolower(rawEmailAddr[i]);
+            rawEmailAddr[i] = tolower((unsigned char)rawEmailAddr[i]);
         }
     }
 
@@ -1369,7 +1369,7 @@ appendStringToBuf(char* dest, char* src,
     if (dest && src && src[0] && *pRemaining > (len = PL_strlen(src))) {
         PRUint32 i;
         for (i = 0; i < len; ++i)
-            dest[i] = tolower(src[i]);
+            dest[i] = tolower((unsigned char)src[i]);
         dest[len] = 0;
         dest += len + 1;
         *pRemaining -= len + 1;
