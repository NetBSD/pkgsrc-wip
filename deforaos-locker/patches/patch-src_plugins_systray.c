$NetBSD: patch-src_plugins_systray.c,v 1.1 2011/12/14 23:32:02 khorben Exp $

--- src/plugins/systray.c.orig	2011-10-25 10:56:52.000000000 +0000
+++ src/plugins/systray.c
@@ -16,7 +16,6 @@
 
 
 #include <System.h>
-#include <Desktop.h>
 #ifdef DEBUG
 # include <stdio.h>
 #endif
