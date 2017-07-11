$NetBSD$

Also search in the pkgsrc xdg path.

--- clib/xdg.c.orig	2017-07-10 04:22:35.000000000 +0000
+++ clib/xdg.c
@@ -52,6 +52,20 @@ luaH_push_path_array(lua_State *L, const
     return 1;
 }
 
+static int
+luaH_push_path_array_fallback(lua_State *L, const gchar * const * paths, const gchar *fallback)
+{
+    gint n;
+    lua_newtable(L);
+    for (n = 0; paths[n]; ++n) {
+        luaH_push_path(L, paths[n]);
+        lua_rawseti(L, -2, n+1);
+    }
+    luaH_push_path(L, fallback);
+    lua_rawseti(L, -2, n+1);
+    return 1;
+}
+
 static gint
 luaH_xdg_index(lua_State *L)
 {
@@ -84,7 +98,7 @@ luaH_xdg_index(lua_State *L)
         return luaH_push_path_array(L, g_get_system_data_dirs());
 
       case L_TK_SYSTEM_CONFIG_DIRS:
-        return luaH_push_path_array(L, g_get_system_config_dirs());
+        return luaH_push_path_array_fallback(L, g_get_system_config_dirs(), @PKGSRCXDGPATH@);
 
       default:
         break;
