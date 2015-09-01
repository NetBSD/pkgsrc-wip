$NetBSD: patch-dwbem_dwbem.c,v 1.1 2015/09/01 23:24:54 f8l Exp $

Corrects a header path.

--- dwbem/dwbem.c.orig	2014-03-07 11:39:43.000000000 +0000
+++ dwbem/dwbem.c
@@ -42,7 +42,7 @@
 #include <JavaScriptCore/JavaScript.h>
 #include <sys/stat.h>
 
-#include <glib-2.0/glib.h>
+#include <glib.h>
 #include <libsoup-2.4/libsoup/soup.h>
 
 #include <exar.h>
