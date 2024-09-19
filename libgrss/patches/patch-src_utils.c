$NetBSD: patch-src_utils.c,v 1.1 2014/11/25 12:51:28 thomasklausner Exp $

Fix build on NetBSD.

--- src/utils.c.orig	2012-03-06 20:46:34.000000000 +0000
+++ src/utils.c
@@ -26,6 +26,8 @@
  * Copyright (C) 2004-2006  Nathan J. Conrad <t98502@users.sourceforge.net>
  */
 
+#include <arpa/inet.h>
+
 #include "utils.h"
 
 typedef struct {
