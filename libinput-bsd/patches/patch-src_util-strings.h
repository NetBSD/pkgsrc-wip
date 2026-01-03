$NetBSD$

Treat NetBSD like OpenBSD

--- src/util-strings.h.orig	2025-08-02 09:40:32.000000000 +0000
+++ src/util-strings.h
@@ -242,7 +242,7 @@ safe_atod(const char *str, double *val)
 		return false;
 
 	errno = 0;
-#ifndef __OpenBSD__
+#if !(defined(__OpenBSD__) || defined(__NetBSD__))
 	v = strtod_l(str, &endptr, c_locale);
 #else
 	v = strtod(str, &endptr);
