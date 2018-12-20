$NetBSD$

Add use of getprogname() for NetBSD and OpenBSD.
This part of the code could do with some more work...

--- carp.c.orig	2017-08-04 14:27:44.000000000 +0000
+++ carp.c
@@ -102,7 +102,7 @@ static char proggy[MAXPATHLEN];
 
 const char *thisprogname(void)
 {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     return getprogname();
 #elif defined(__APPLE__)
     return getprogname();
