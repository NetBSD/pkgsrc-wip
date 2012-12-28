$NetBSD: patch-src_category.cc,v 1.1 2012/12/28 12:41:04 othyro Exp $

Only <glib.h> can be included directly.

--- src/category.cc.orig	2009-04-17 21:27:46.000000000 +0000
+++ src/category.cc
@@ -19,7 +19,7 @@
  */
 
 #include <errno.h>
-#include <glib/gstdio.h>
+#include <glib.h>
 #include <fstream>
 #include <iostream>
 #include <glibmm/fileutils.h>
