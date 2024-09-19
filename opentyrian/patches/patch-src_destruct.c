$NetBSD$

Add FALLTHROUGH for -Werror.
Fix unsigned condition.

--- src/destruct.c.orig	2013-09-07 22:14:32.000000000 +0000
+++ src/destruct.c
@@ -1717,6 +1717,7 @@ static void DE_RunTickGravity( void )
 					break;
 				}
 				/* else fall through and treat as a normal unit */
+				/* FALLTHROUGH */
 
 			default:
 				DE_GravityLowerUnit(unit);
@@ -2240,7 +2241,7 @@ static void DE_RunTickAI( void )
 			ptrUnit = ptrTarget->unit;
 			for (j = 0; j < config.max_installations; j++, ptrUnit++)
 			{
-				if (abs(ptrUnit->unitX - ptrCurUnit->unitX) < 8)
+				if (ptrUnit->unitX < ptrCurUnit->unitX + 8)
 				{
 					/* I get it.  This makes helicoptors hover over
 					 * their enemies. */
