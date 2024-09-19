$NetBSD: patch-opensync_opensync__internals.h,v 1.1 2013/02/24 13:41:22 othyro Exp $

Only <glib.h> can be included directly.
Fix compilation with Sun Studio, which does not provide __FUNCTION__.

--- opensync/opensync_internals.h.orig	2009-09-20 20:14:18.000000000 +0000
+++ opensync/opensync_internals.h
@@ -24,8 +24,6 @@
 #include <glib.h>
 #include <gmodule.h>
 #include <string.h>
-#include <glib/gprintf.h>
-#include <glib/gstdio.h>
 #include <sys/stat.h>
 
 #include "config.h"
@@ -35,6 +33,10 @@
 extern int errno;
 #endif
 
+#ifndef __FUNCTION__
+#define __FUNCTION__ __func__
+#endif
+
 #ifdef __GNUC__
 #define OSYNC_UNUSED __attribute__ ((unused))
 #else
