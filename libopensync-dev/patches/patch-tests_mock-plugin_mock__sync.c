$NetBSD: patch-tests_mock-plugin_mock__sync.c,v 1.1 2013/02/24 13:41:22 othyro Exp $

Cast NULL as (char *).

--- tests/mock-plugin/mock_sync.c.orig	2009-09-20 20:14:18.000000000 +0000
+++ tests/mock-plugin/mock_sync.c
@@ -292,7 +292,7 @@ static void mock_report_dir(MockDir *dir
 	OSyncFormatEnv *formatenv = osync_plugin_info_get_format_env(info);
 	osync_assert(formatenv);
 
-	path = g_build_filename(directory->path, subdir, NULL);
+	path = g_build_filename(directory->path, subdir, (char *)NULL);
 	osync_trace(TRACE_INTERNAL, "path %s", path);
 	
 	dir = g_dir_open(path, 0, &gerror);
@@ -307,12 +307,12 @@ static void mock_report_dir(MockDir *dir
 
 	while(sorted_dir_list) {
 		de = sorted_dir_list->data;
-		char *filename = g_build_filename(path, de, NULL);
+		char *filename = g_build_filename(path, de, (char *)NULL);
 		char *relative_filename = NULL;
 		if (!subdir)
 			relative_filename = g_strdup(de);
 		else
-			relative_filename = g_build_filename(subdir, de, NULL);
+			relative_filename = g_build_filename(subdir, de, (char *)NULL);
 		g_free(sorted_dir_list->data);
 		sorted_dir_list = osync_list_remove(sorted_dir_list, sorted_dir_list->data);
 
