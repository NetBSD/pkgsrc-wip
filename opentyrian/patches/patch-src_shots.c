$NetBSD: patch-src_shots.c,v 1.1 2015/08/19 19:36:56 yhardy Exp $

Ensure that shot_id is initialized (compiled with -Werror).

--- src/shots.c.orig	2013-09-07 22:14:33.000000000 +0000
+++ src/shots.c
@@ -319,7 +319,7 @@ JE_integer player_shot_create( JE_word p
 	if (weapon->sound > 0)
 		soundQueue[soundChannel[bay_i]] = weapon->sound;
 
-	int shot_id;
+	int shot_id = 0;
 	/*Rot*/
 	for (int multi_i = 1; multi_i <= weapon->multi; multi_i++)
 	{
