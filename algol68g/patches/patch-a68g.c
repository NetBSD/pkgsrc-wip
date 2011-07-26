$NetBSD: patch-a68g.c,v 1.1.1.1 2011/07/26 22:50:55 rhialto Exp $

Add NetBSD compilation support identical to FreeBSD support.

--- a68g.c.orig	2011-07-03 21:31:45.000000000 +0000
+++ a68g.c
@@ -757,7 +757,7 @@ FIXME: One day this should be all portab
 /*
 Compilation on Linux or FreeBSD
 */
-#if (defined HAVE_LINUX || defined HAVE_FREEBSD)
+#if (defined HAVE_LINUX || defined HAVE_FREEBSD || defined HAVE_NETBSD)
 #if defined HAVE_TUNING
       ASSERT (snprintf (options, SNPRINTF_SIZE, "%s %s %s -g", extra_inc, optimisation, HAVE_TUNING) >= 0);
 #else
