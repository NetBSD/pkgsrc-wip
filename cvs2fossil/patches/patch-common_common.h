$NetBSD$

Avoid conflict with SSP definition.

--- common/common.h.orig	2010-12-19 15:42:09.000000000 +0000
+++ common/common.h
@@ -2,7 +2,9 @@
 
 void *memrchr(const void *, int, size_t);
 
+#ifndef stpcpy
 char *stpcpy(char *, const char *);
+#endif
 
 size_t strlcat(char *, const char *, size_t);
 size_t strlcpy(char *, const char *, size_t);
