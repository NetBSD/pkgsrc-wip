$NetBSD: patch-gio_gresource-tool.c,v 1.1 2012/07/12 14:43:26 jperkin Exp $

--- gio/gresource-tool.c.orig	2018-12-18 14:51:13.000000000 +0000
+++ gio/gresource-tool.c
@@ -29,6 +29,11 @@
 #include <locale.h>
 
 #ifdef HAVE_LIBELF
+/* Solaris native libelf does not support largefile in 32-bit mode */
+#  if defined(__sun) && defined(__i386)
+#    undef  _FILE_OFFSET_BITS
+#    define _FILE_OFFSET_BITS   32
+#  endif
 #include <libelf.h>
 #include <gelf.h>
 #endif
