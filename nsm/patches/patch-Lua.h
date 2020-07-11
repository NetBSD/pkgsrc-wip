$NetBSD$

--- Lua.h.orig	2020-07-12 00:15:55.891842413 +0200
+++ Lua.h	2020-07-12 00:17:09.794282009 +0200
@@ -6,6 +6,11 @@
 
 #include "StrFns.h"
 
+// Lua in pkgsrc can deal with this
+#include <lua.hpp>
+#include <lualib.h>
+#include <lauxlib.h>
+/*
 #if defined __BUNDLED__
 	#if defined __LUA_VERSION_5_3__
 		#include "Lua-5.3/src/lua.hpp"
@@ -41,6 +44,7 @@
 		#include "/usr/local/include/luajit-2.1/lua.hpp"
 	#endif
 #endif
+*/
 
 void process_lua_error(std::string& errStr, int& errLineNo);
 
