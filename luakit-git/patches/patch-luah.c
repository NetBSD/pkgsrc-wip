$NetBSD$

Also search in the pkgsrc xdg path.

--- luah.c.orig	2017-07-11 15:46:58.000000000 +0000
+++ luah.c
@@ -210,6 +210,9 @@ luaH_parserc(const gchar *confpath, gboo
     for(; *config_dirs; config_dirs++)
         g_ptr_array_add(paths, g_build_filename(*config_dirs, "luakit", "rc.lua", NULL));
 
+    /* add luakit xdg path */
+    g_ptr_array_add(paths, g_build_filename(@PKGSRCXDGPATH@, "luakit", "rc.lua", NULL));
+
     /* get continuation variable; bail out if invalid */
     char *i_str = getenv("LUAKIT_NEXT_CONFIG_INDEX");
     gint i = i_str ? atoi(i_str) : 0;
