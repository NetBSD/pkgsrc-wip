$NetBSD$

--- Telegram/cmake/lib_export.cmake.orig	2020-02-22 02:08:05.861129396 +0000
+++ Telegram/cmake/lib_export.cmake
@@ -8,7 +8,6 @@ add_library(lib_export OBJECT)
 init_target(lib_export)
 add_library(tdesktop::lib_export ALIAS lib_export)
 
-target_precompile_headers(lib_export PRIVATE ${src_loc}/export/export_pch.h)
 nice_target_sources(lib_export ${src_loc}
 PRIVATE
     export/export_api_wrap.cpp
