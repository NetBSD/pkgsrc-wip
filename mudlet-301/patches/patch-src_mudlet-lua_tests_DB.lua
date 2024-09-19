$NetBSD$
Swap out /usr/local with @PREFIX@
--- src/mudlet-lua/tests/DB.lua.orig	2017-07-11 00:01:53.000000000 +0000
+++ src/mudlet-lua/tests/DB.lua
@@ -4,7 +4,7 @@ describe("Tests DB.lua functions", funct
     package.path = "../lua/?.lua;"
 
     -- add in the location of Lua libraries on Ubuntu 12.04
-    package.path = package.path .. "/usr/local/share/lua/5.1/?.lua;/usr/local/share/lua/5.1/?/init.lua;/usr/local/lib/lua/5.1/?.lua;/usr/local/lib/lua/5.1/?/init.lua;/usr/share/lua/5.1/?.lua;/usr/share/lua/5.1/?/init.lua"
+    package.path = package.path .. "@PREFIX@/share/lua/5.1/?.lua;@PREFIX@/share/lua/5.1/?/init.lua;@PREFIX@/lib/lua/5.1/?.lua;@PREFIX@/lib/lua/5.1/?/init.lua;/usr/share/lua/5.1/?.lua;/usr/share/lua/5.1/?/init.lua"
 
     luasql = require"luasql.sqlite3"
     rex    = require"rex_pcre"
