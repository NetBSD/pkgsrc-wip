$NetBSD: patch-manymouse_x11__xinput2.c,v 1.2 2014/12/24 20:17:47 rhialto Exp $

Include proper header file.

--- manymouse/x11_xinput2.c.orig	2015-08-25 13:35:59.000000000 +0000
+++ manymouse/x11_xinput2.c
@@ -25,6 +25,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <dlfcn.h>
+#include <sys/select.h>
 #include <X11/extensions/XInput2.h>
 
 /* 32 is good enough for now. */
