$NetBSD$
Swap out /usr/local with @PREFIX@
--- src/mudlet-lua/tests/GUIUtils.lua.orig	2017-07-11 00:01:53.000000000 +0000
+++ src/mudlet-lua/tests/GUIUtils.lua
@@ -6,7 +6,7 @@ describe("Tests the GUI utilities as far
 
     -- add in the location of Lua libraries on Ubuntu 12.04
     package.path = package.path ..
-"/usr/local/share/lua/5.1/?.lua;/usr/local/share/lua/5.1/?/init.lua;/usr/local/lib/lua/5.1/?.lua;/usr/local/lib/lua/5.1/?/init.lua;/usr/share/lua/5.1/?.lua;/usr/share/lua/5.1/?/init.lua"
+"@PREFIX@/share/lua/5.1/?.lua;@PREFIX@/share/lua/5.1/?/init.lua;@PREFIX@/lib/lua/5.1/?.lua;@PREFIX@/lib/lua/5.1/?/init.lua;/usr/share/lua/5.1/?.lua;/usr/share/lua/5.1/?/init.lua"
 
     rex    = require"rex_pcre"
 
