$NetBSD: patch-bin_override.c,v 1.1 2015/05/01 06:24:13 idleroux Exp $

--- bin/override.c.orig	2014-06-14 15:14:12.000000000 +0000
+++ bin/override.c
@@ -27,7 +27,7 @@
 
 void vlc_enable_override (void);
 
-#if defined (__GNUC__) \
+#if 0 && defined (__GNUC__) \
  && (defined (__ELF__) && !defined (__sun__))
 /* Solaris crashes on printf("%s", NULL); which is legal, but annoying. */
 
@@ -125,7 +125,7 @@ static void *getsym (const char *name)
  *
  * Some evil libraries modify the environment. We currently ignore the calls as
  * they could crash the process. This may cause funny behaviour though. */
-int putenv (char *str)
+int putenv (const char *str)
 {
     if (override)
     {
