$NetBSD: patch-src_keybinder.h,v 1.1 2012/07/24 23:03:45 khorben Exp $

--- src/keybinder.h.orig	2010-12-12 14:31:47.000000000 +0000
+++ src/keybinder.h
@@ -20,8 +20,6 @@
 #ifndef __KEY_BINDER_H__
 #define __KEY_BINDER_H__
 
-#include <glib/gtypes.h>
-
 G_BEGIN_DECLS
 
 typedef void (* BindkeyHandler) (char *keystring, gpointer user_data);
