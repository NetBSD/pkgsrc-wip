$NetBSD$

--- build/premake/extern_libs5.lua.orig	2016-03-12 18:15:04.000000000 +0000
+++ build/premake/extern_libs5.lua
@@ -347,7 +347,7 @@ extern_lib_defs = {
 			elseif os.is("macosx") then
 				add_default_include_paths("iconv")
 				defines { "LIBICONV_STATIC" }
-			elseif os.getversion().description == "FreeBSD" then
+			elseif os.getversion().description == "NetBSD" then
 				defines { "HAVE_ICONV_CONST" }
 				defines { "ICONV_CONST=const" }
 			end
