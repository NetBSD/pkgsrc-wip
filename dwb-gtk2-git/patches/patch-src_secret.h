$NetBSD: patch-src_secret.h,v 1.1 2015/09/01 23:24:55 f8l Exp $

Corrects a header path.

--- src/secret.h.orig	2015-05-24 10:10:47.000000000 +0000
+++ src/secret.h
@@ -22,7 +22,7 @@
 #define __DWB_SECRET_H__
 
 #include <libsecret/secret.h>
-#include <glib-2.0/glib.h>
+#include <glib.h>
 
 
 typedef void (* dwb_secret_cb)(int, const void *, void *);
