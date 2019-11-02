$NetBSD$

Add FALLTHROUGH for -Werror.

--- src/destruct.c.orig	2013-09-07 22:14:32.000000000 +0000
+++ src/destruct.c
@@ -1717,6 +1717,7 @@ static void DE_RunTickGravity( void )
 					break;
 				}
 				/* else fall through and treat as a normal unit */
+				/* FALLTHROUGH */
 
 			default:
 				DE_GravityLowerUnit(unit);
