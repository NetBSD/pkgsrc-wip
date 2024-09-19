$NetBSD: patch-aa,v 1.1.1.1 2010/12/31 16:21:21 makoto Exp $

- Explicitly check isastream(3) for SVR4 and enable it.
- Fix typo.

--- libspt.c.orig	2003-12-12 07:36:35.000000000 +0000
+++ libspt.c
@@ -7,8 +7,8 @@
 #include <time.h>
 #include <stdio.h>  /* for perror() */
 #include <signal.h>
-#ifdef HAVE_PTY_SVR4
-#include <sys/stropts.h>
+#if defined(HAVE_PTY_SVR4) && defined(HAVE_ISASTREAM)
+#include <stropts.h>
 #endif
 
 struct spt_handle_tag {
@@ -467,10 +467,8 @@ spt_init_slavefd(const spt_handle *phand
 {
     /* XXX: screen requires !linux, !sgi, !__osf__ and !M_UNIX */
 #if defined(HAVE_PTY_SVR4) && defined(I_PUSH)
-#if 0	/* only rxvt and mlterm do this */
 #ifdef HAVE_ISASTREAM
-    if (isastram(slavefd))
-#endif
+    if (isastream(slavefd))
 #endif
     {
 	/*
