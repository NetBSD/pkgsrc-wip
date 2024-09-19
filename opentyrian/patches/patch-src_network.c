$NetBSD$

Add FALLTHROUGH for -Werror.

--- src/network.c.orig	2013-09-07 22:14:33.000000000 +0000
+++ src/network.c
@@ -284,6 +284,7 @@ int network_check( void )
 								packet_in[i] = NULL;
 							}
 						}
+						/* FALLTHROUGH */
 
 					case PACKET_DETAILS:
 					case PACKET_WAITING:
@@ -305,6 +306,7 @@ int network_check( void )
 						}
 
 						network_acknowledge(SDLNet_Read16(&packet_temp->data[2]));
+						/* FALLTHROUGH */
 
 					case PACKET_KEEP_ALIVE:
 						last_in_tick = SDL_GetTicks();
