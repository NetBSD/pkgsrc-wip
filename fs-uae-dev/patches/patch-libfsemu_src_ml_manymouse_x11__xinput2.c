$NetBSD: patch-libfsemu_src_ml_manymouse_x11__xinput2.c,v 1.1 2013/11/15 12:26:23 rhialto Exp $

Include proper header file.

--- libfsemu/src/ml/manymouse/x11_xinput2.c.orig	2013-10-23 17:58:00.000000000 +0000
+++ libfsemu/src/ml/manymouse/x11_xinput2.c
@@ -25,6 +25,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <dlfcn.h>
+#include <sys/select.h>
 #include <X11/extensions/XInput2.h>
 
 /* 32 is good enough for now. */
