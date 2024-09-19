$NetBSD: patch-src_mainint.c,v 1.1 2015/08/19 19:36:56 yhardy Exp $

Ensure that ship_banking is initialized (compiled with -Werror).

--- src/mainint.c.orig	2013-09-07 22:14:33.000000000 +0000
+++ src/mainint.c
@@ -1627,6 +1627,7 @@ void JE_highScoreCheck( void )
 							case '"':
 							case '\'':
 								validkey = true;
+								/* FALLTHROUGH */
 							default:
 								if (temp < 28 && (validkey || (lastkey_char >= 'A' && lastkey_char <= 'Z') || (lastkey_char >= '0' && lastkey_char <= '9')))
 								{
@@ -2458,6 +2459,7 @@ void JE_operation( JE_byte slot )
 					case '"':
 					case '\'':
 						validkey = true;
+						/* FALLTHROUGH */
 					default:
 						if (temp < 14 && (validkey || (lastkey_char >= 'A' && lastkey_char <= 'Z') || (lastkey_char >= '0' && lastkey_char <= '9')))
 						{
@@ -3635,7 +3637,7 @@ redo:
 				blit_sprite2x2(VGAScreen, this_player->x - 17, this_player->y - 7, *shapes9ptr_, 220);
 				blit_sprite2x2(VGAScreen, this_player->x + 7, this_player->y - 7, *shapes9ptr_, 222);
 
-				int ship_banking;
+				int ship_banking = 0;
 				switch (ship_sprite)
 				{
 				case 5:
