$NetBSD$

Rapidjson is headers only and doesn't provide any libraries.

--- cmake-proxies/cmake-modules/dependencies/rapidjson.cmake.orig	2026-04-15 12:48:57.129799245 +0000
+++ cmake-proxies/cmake-modules/dependencies/rapidjson.cmake
@@ -3,7 +3,7 @@
 if(NOT ${_OPT}use_rapidjson STREQUAL "off")
    if(NOT TARGET rapidjson::rapidjson)
       if(TARGET rapidjson)
-         add_library( rapidjson::rapidjson ALIAS rapidjson )
+         add_library( rapidjson::rapidjson INTERFACE IMPORTED GLOBAL)
       else()
          # At least on Arch RapidJSONConfig.cmake does not define a target at all
          # so we have to do it ourselves
