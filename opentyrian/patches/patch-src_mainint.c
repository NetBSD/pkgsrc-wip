$NetBSD: patch-src_mainint.c,v 1.1 2015/08/19 19:36:56 yhardy Exp $

Ensure that ship_banking is initialized (compiled with -Werror).

--- src/mainint.c.orig	2013-09-07 22:14:33.000000000 +0000
+++ src/mainint.c
@@ -3635,7 +3635,7 @@ redo:
 				blit_sprite2x2(VGAScreen, this_player->x - 17, this_player->y - 7, *shapes9ptr_, 220);
 				blit_sprite2x2(VGAScreen, this_player->x + 7, this_player->y - 7, *shapes9ptr_, 222);
 
-				int ship_banking;
+				int ship_banking = 0;
 				switch (ship_sprite)
 				{
 				case 5:
