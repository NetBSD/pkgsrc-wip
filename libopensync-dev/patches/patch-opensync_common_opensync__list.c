$NetBSD: patch-opensync_common_opensync__list.c,v 1.1 2013/02/24 13:41:22 othyro Exp $

Only <glib.h> can be included directly.

--- opensync/common/opensync_list.c.orig	2009-09-20 20:14:18.000000000 +0000
+++ opensync/common/opensync_list.c
@@ -30,7 +30,7 @@
  * MT safe
  */
 
-#include <glib/gmem.h>
+#include <glib.h>
 #include "opensync_list.h"
 #include "opensync_internals.h"
 
