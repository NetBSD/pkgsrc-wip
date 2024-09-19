$NetBSD$

"Fixes for C++11 support" from upstream.

--- Map.cpp.orig	2014-02-22 12:05:53.000000000 +0000
+++ Map.cpp
@@ -44,7 +44,7 @@ Map::Map(Configuration *cfg)
  actor_manager = NULL;
  surface = NULL;
  roof_surface = NULL;
- dungeons[4] = '\0';
+ dungeons[4] = NULL;
 
  config->value(config_get_game_key(config) + "/roof_mode", roof_mode, false);
 }
