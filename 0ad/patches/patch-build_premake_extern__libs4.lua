$NetBSD$

--- build/premake/extern_libs4.lua.orig	2016-03-12 18:15:04.000000000 +0000
+++ build/premake/extern_libs4.lua
@@ -347,7 +347,7 @@ extern_lib_defs = {
 			elseif os.is("macosx") then
 				add_default_include_paths("iconv")
 				defines { "LIBICONV_STATIC" }
-			elseif os.getversion().description == "FreeBSD" then
+			elseif os.getversion().description == "NetBSD" then
 				defines { "HAVE_ICONV_CONST" }
 				defines { "ICONV_CONST=const" }
 			end
@@ -366,7 +366,7 @@ extern_lib_defs = {
 			-- FreeBSD 10+ has iconv as a part of libc
 			if os.is("bsd")
 			   and not (os.getversion().description == "FreeBSD" and os.getversion().majorversion >= 10
-			            or os.getversion().description == "GNU/kFreeBSD") then
+			            or os.getversion().description == "GNU/kFreeBSD") and not os.getversion().description == "NetBSD" then
 				add_default_links({
 					bsd_names = { "iconv" },
 				})
