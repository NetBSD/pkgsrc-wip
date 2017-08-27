$NetBSD$

Also search in the pkgsrc xdg path.

--- common/luautil.c.orig	2017-08-27 19:41:20.547896796 +0000
+++ common/luautil.c
@@ -161,6 +161,9 @@ luaH_add_paths(lua_State *L, const gchar
     /* add luakit install path */
     g_ptr_array_add(paths, g_build_filename(LUAKIT_INSTALL_PATH, "lib", NULL));
 
+    /* add luakit xdg path */
+    g_ptr_array_add(paths, g_build_filename(@PKGSRCXDGPATH@, "luakit", NULL));
+
     /* add users config dir (see: XDG_CONFIG_DIR) */
     if (config_dir)
         g_ptr_array_add(paths, g_strdup(config_dir));
