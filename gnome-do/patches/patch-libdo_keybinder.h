$NetBSD: patch-libdo_keybinder.h,v 1.1 2012/08/14 10:59:24 thomasklausner Exp $

Do not include private headers.

--- libdo/keybinder.h.orig	2009-08-10 08:16:47.000000000 +0000
+++ libdo/keybinder.h
@@ -24,7 +24,7 @@
 #ifndef __DO_KEY_BINDER_H__
 #define __DO_KEY_BINDER_H__
 
-#include <glib/gtypes.h>
+#include <glib.h>
 
 G_BEGIN_DECLS
 
