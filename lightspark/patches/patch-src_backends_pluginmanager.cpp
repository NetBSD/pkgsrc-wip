$NetBSD: patch-src_backends_pluginmanager.cpp,v 1.1 2013/12/16 07:54:18 nsloss Exp $

Unset locale variables to avoid crash.  Maybe a problem with libboost.

--- src/backends/pluginmanager.cpp.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/backends/pluginmanager.cpp
@@ -61,9 +61,12 @@ void PluginManager::findPlugins()
 		throw RunTimeException("PluginManager::findPlugins(): can't compile file_pattern");
 	//We don't expect any captured substrings, so 3 ints should be enough
 
-#if defined DEBUG
 	LOG(LOG_INFO, "Looking for plugins under " << plugins_folder << " for pattern " << pattern);
-#endif
+
+	setenv("LANG", "C", 1);
+	setenv("LC_CTYPE", "C", 1);
+	setlocale(LC_CTYPE,"");
+	setlocale(LC_ALL,"");
 
 	if ( !is_directory ( plugins_folder ) )
 	{
