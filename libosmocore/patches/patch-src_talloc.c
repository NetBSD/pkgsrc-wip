$NetBSD: patch-src_talloc.c,v 1.1 2011/08/02 22:19:13 khorben Exp $

--- src/talloc.c.orig	2010-02-20 19:33:33.000000000 +0000
+++ src/talloc.c
@@ -105,7 +105,7 @@
 #endif
 #endif
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 /* taken from http://insanecoding.blogspot.com/2007/03/methods-for-safe-string-handling.html */
 size_t strnlen(const char *s, size_t n)
 {
