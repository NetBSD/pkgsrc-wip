$NetBSD: patch-src_paths.hh,v 1.1 2012/12/28 12:41:04 othyro Exp $

Only <glib.h> can be included directly.

--- src/paths.hh.orig	2009-04-17 21:27:46.000000000 +0000
+++ src/paths.hh
@@ -23,7 +23,7 @@
 #ifndef __PAPER_BOX_PATHS_HH__
 #define __PAPER_BOX_PATHS_HH__
 
-#include <glib/gutils.h>
+#include <glib.h>
 
 namespace paperbox {
 
