$NetBSD: patch-src_portfwd.h,v 1.1 2015/06/28 01:33:35 mbowie Exp $
Include path adjustment

--- src/portfwd.h.orig	2015-06-27 14:35:29.000000000 -0700
+++ src/portfwd.h	2015-06-27 14:35:51.000000000 -0700
@@ -7,7 +7,7 @@
 #ifndef PORTFWD_H
 #define PORTFWD_H
 
-#include "config.h"
+#include "../config.h"
 
 extern const int BUF_SZ;
 extern const char * const portfwd_version;
