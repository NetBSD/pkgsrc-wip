$NetBSD$

--- Telegram/cmake/lib_mtproto.cmake.orig	2020-02-18 23:44:51.744224914 +0000
+++ Telegram/cmake/lib_mtproto.cmake
@@ -8,7 +8,6 @@ add_library(lib_mtproto OBJECT)
 init_target(lib_mtproto)
 add_library(tdesktop::lib_mtproto ALIAS lib_mtproto)
 
-target_precompile_headers(lib_mtproto PRIVATE ${src_loc}/mtproto/mtproto_pch.h)
 nice_target_sources(lib_mtproto ${src_loc}
 PRIVATE
     mtproto/details/mtproto_abstract_socket.cpp
