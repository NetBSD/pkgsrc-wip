$NetBSD: patch-thunar_thunar-transfer-job.c,v 1.1 2011/07/08 20:10:51 guigui2 Exp $

Secunia Advisory SA44104
Thunar "thunar_transfer_job_copy_node()" Format String Vulnerability fix.

--- thunar/thunar-transfer-job.c.orig	2011-02-14 13:09:15.000000000 +0000
+++ thunar/thunar-transfer-job.c
@@ -534,7 +534,7 @@ thunar_transfer_job_copy_node (ThunarTra
         }

       /* update progress information */
-      exo_job_info_message (EXO_JOB (job), g_file_info_get_display_name (info));
+      exo_job_info_message (EXO_JOB (job), "%s", g_file_info_get_display_name (info));

 retry_copy:
       /* copy the item specified by this node (not recursively) */
