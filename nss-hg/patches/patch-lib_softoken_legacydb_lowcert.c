$NetBSD$

Missing ctype(3) casts.

--- lib/softoken/legacydb/lowcert.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/softoken/legacydb/lowcert.c
@@ -585,7 +585,7 @@ nsslowcert_GetCertificateEmailAddress(NS
     /* make it lower case */
     str = emailAddr;
     while ( str && *str ) {
-	*str = tolower( *str );
+	*str = tolower( (unsigned char)*str );
 	str++;
     }
     return emailAddr;
@@ -689,7 +689,7 @@ nsslowcert_FixupEmailAddr(char *emailAdd
     
     /* make it lower case */
     while ( *str ) {
-	*str = tolower( *str );
+	*str = tolower( (unsigned char)*str );
 	str++;
     }
     
