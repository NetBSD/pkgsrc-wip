$NetBSD: patch-src_util_mktlds-header.c,v 1.1 2015/05/26 11:10:47 f8l Exp $

Fixes char overflow bug causing undefined behaviour.
It’s apparent when compiling with GCC 4.5 with -O2, for example.

--- src/util/mktlds-header.c.orig	2014-03-07 11:39:43.000000000 +0000
+++ src/util/mktlds-header.c
@@ -198,7 +198,7 @@ int main()
         if (fgets(buf, sizeof(buf), stdin) == NULL)
             break;
 
-        for (ptr = buf+strlen(buf)-1; isspace(*ptr) ||
+        for (ptr = buf+strlen(buf)-1; isspace((unsigned char)*ptr) ||
             *ptr == '\n' || *ptr == '\r'; ptr --)
             *ptr = '\0';
 
