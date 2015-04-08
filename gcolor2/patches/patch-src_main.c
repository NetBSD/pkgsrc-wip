$NetBSD: patch-src_main.c,v 1.1 2015/04/08 22:27:05 krytarowski Exp $

Add missing header for strspn(3)

--- src/main.c.orig	2005-07-11 14:55:49.000000000 +0000
+++ src/main.c
@@ -4,6 +4,7 @@
 
 #include <gtk/gtk.h>
 #include <stdio.h>
+#include <string.h>
 
 #include "interface.h"
 #include "support.h"
