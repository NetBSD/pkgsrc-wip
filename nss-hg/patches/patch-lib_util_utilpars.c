$NetBSD$

Missing ctype(3) casts.

--- lib/util/utilpars.c.orig	2016-01-30 10:42:11.000000000 +0000
+++ lib/util/utilpars.c
@@ -243,7 +243,7 @@ NSSUTIL_ArgDecodeNumber(const char *num)
 
    
     for ( ;*num; num++ ) {
-	if (isdigit(*num)) {
+	if (isdigit((unsigned char)*num)) {
 	    digit = *num - '0';
 	} else if ((*num >= 'a') && (*num <= 'f'))  {
 	    digit = *num - 'a' + 10;
