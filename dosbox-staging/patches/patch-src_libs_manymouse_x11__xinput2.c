$NetBSD$

--- src/libs/manymouse/x11_xinput2.c.orig	2023-01-07 07:06:28.000000000 +0000
+++ src/libs/manymouse/x11_xinput2.c
@@ -32,6 +32,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <dlfcn.h>
+#include <sys/select.h>
 #include <X11/extensions/XInput2.h>
 
 /* 32 is good enough for now. */
