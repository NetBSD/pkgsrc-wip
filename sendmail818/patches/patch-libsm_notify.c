$NetBSD: patch-bs,v 1.1 2021/07/04 07:57:13 jnemeth Exp $

--- libsm/notify.c.orig	2023-02-09 18:24:38.000000000 +0000
+++ libsm/notify.c
@@ -19,6 +19,7 @@
 #include <sm/time.h>
 #include <sm/string.h>
 
+#include <sys/select.h>
 #include <sys/types.h>
 #include <signal.h>
 #include <stdio.h>
