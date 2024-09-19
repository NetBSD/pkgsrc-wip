$NetBSD$

Add FALLTHROUGH for -Werror.

--- src/keyboard.c.orig	2013-09-07 22:14:32.000000000 +0000
+++ src/keyboard.c
@@ -214,6 +214,7 @@ void service_SDL_events( JE_boolean clea
 					break;
 				}
 				// intentional fall-though
+				/* FALLTHROUGH */
 			case SDL_MOUSEBUTTONUP:
 				if (ev.type == SDL_MOUSEBUTTONDOWN)
 				{
