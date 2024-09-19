$NetBSD: patch-tools_osynctest.c,v 1.1 2013/02/24 13:41:22 othyro Exp $

Remove useless variable and cast NULL as (char *).

--- tools/osynctest.c.orig	2009-09-20 20:14:18.000000000 +0000
+++ tools/osynctest.c
@@ -79,8 +79,7 @@ double writetime;
 double _second()     /* note that some compilers like AIX xlf do not require the trailing  '_' */
 {
     struct timeval tp;
-    int rtn;
-    rtn=gettimeofday(&tp, NULL);
+    gettimeofday(&tp, NULL);
 
     return ((double)tp.tv_sec+(1.e-6)*tp.tv_usec);
 }
@@ -209,7 +208,7 @@ void modify_data(OSyncMember *member, co
 
 	const char *de = NULL;
 	while ((de = g_dir_read_name(dir))) {
-		char *filename = g_build_filename(localdir, de, NULL);
+		char *filename = g_build_filename(localdir, de, (char *)NULL);
 
 		OSyncChange *change = osync_change_new();
 		if (!osync_member_make_random_data(member, change, objtype)) {
