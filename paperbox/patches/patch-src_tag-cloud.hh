$NetBSD: patch-src_tag-cloud.hh,v 1.1 2012/12/28 12:41:04 othyro Exp $

Only <glib.h> can be included directly.

--- src/tag-cloud.hh.orig	2009-04-17 21:27:46.000000000 +0000
+++ src/tag-cloud.hh
@@ -25,7 +25,7 @@
 #include <list>
 #include <map>
 #include <tr1/memory>
-#include <glib/grand.h>
+#include <glib.h>
 #include <gtkmm.h>
 #include "tag-cloud-model.hh"
 
