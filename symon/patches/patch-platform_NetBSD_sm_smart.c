$NetBSD: patch-platform_NetBSD_sm_smart.c,v 1.1 2011/04/18 14:51:27 hfath Exp $

Add missing struct field

--- platform/NetBSD/sm_smart.c.orig	2010-01-23 20:56:31.000000000 +0000
+++ platform/NetBSD/sm_smart.c
@@ -63,11 +63,12 @@ static struct atareq smart_cmd = {
 };
 
 /* per drive storage structure */
-static struct smart_device {
+struct smart_device {
     char name[MAX_PATH_LEN];
     int fd;
     int type;
     int failed;
+    struct atareq cmd;
     struct smart_values data;
 };
 
