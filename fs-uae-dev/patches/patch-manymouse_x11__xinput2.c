$NetBSD: patch-manymouse_x11__xinput2.c,v 1.1 2014/08/13 20:22:15 rhialto Exp $

Include proper header file.

--- manymouse/x11_xinput2.c.orig	2014-05-10 20:17:29.000000000 +0000
+++ manymouse/x11_xinput2.c
@@ -25,6 +25,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <dlfcn.h>
+#include <sys/select.h>
 #include <X11/extensions/XInput2.h>
 
 /* 32 is good enough for now. */
