$NetBSD: patch-src_lib_eio__file.c,v 1.1 2013/09/15 17:03:37 roelants Exp $

Fix typo'd fchmod check.

--- src/lib/eio_file.c.orig	2012-11-27 19:34:11.000000000 +0100
+++ src/lib/eio_file.c
@@ -675,7 +675,7 @@ eio_file_copy_do(Ecore_Thread *thread, E
      }
 
    /* change access right to match source */
-#ifdef HAVE_CHMOD
+#ifdef HAVE_FCHMOD
    if (fchmod(out, md) != 0)
      goto on_error;
 #else
