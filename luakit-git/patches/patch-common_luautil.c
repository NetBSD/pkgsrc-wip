$NetBSD$

Also search in the pkgsrc xdg path.

--- common/luautil.c.orig	2017-06-05 19:43:00.000000000 +0000
+++ common/luautil.c
@@ -169,6 +169,9 @@ luaH_add_paths(lua_State *L, const gchar
     /* add luakit install path */
     g_ptr_array_add(paths, g_build_filename(LUAKIT_INSTALL_PATH, "lib", NULL));
 
+    /* add luakit xdg path */
+    g_ptr_array_add(paths, g_build_filename(@PKGSRCXDGPATH@, "luakit", NULL));
+
     const gchar *path;
     for (guint i = 0; i < paths->len; i++) {
         path = paths->pdata[i];
