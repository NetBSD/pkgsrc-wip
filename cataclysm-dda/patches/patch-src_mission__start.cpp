$NetBSD$

Work around a GCC warning/error, the same change was made upstream
with additional code style changes.

--- src/mission_start.cpp.orig	2015-03-09 05:25:34.000000000 +0000
+++ src/mission_start.cpp
@@ -273,9 +273,10 @@ void mission_start::kill_horde_master(mi
  tile.add_spawn("mon_zombie_dog",3,SEEX,SEEY);
  if (SEEX > 1 && SEEX < OMAPX && SEEY > 1 && SEEY < OMAPY){
  for (int x = SEEX - 1; x <= SEEX + 1; x++) {
-  for (int y = SEEY - 1; y <= SEEY + 1; y++)
+  for (int y = SEEY - 1; y <= SEEY + 1; y++) {
    tile.add_spawn("mon_zombie",rng(3,10),x,y);
-   tile.add_spawn("mon_zombie_dog",rng(0,2),SEEX,SEEY);
+  }
+  tile.add_spawn("mon_zombie_dog",rng(0,2),SEEX,SEEY);
  }
 }
  tile.add_spawn("mon_zombie_necro",2,SEEX,SEEY);
