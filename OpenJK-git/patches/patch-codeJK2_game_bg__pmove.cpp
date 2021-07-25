$NetBSD$

ret is conditional on "ifdef DEBUG", so make the assert also conditional.

--- codeJK2/game/bg_pmove.cpp.orig	2021-01-01 13:35:17.000000000 +0000
+++ codeJK2/game/bg_pmove.cpp
@@ -6500,7 +6500,9 @@ qboolean PM_SaberLocked( void )
 #endif // _DEBUG
 						gi.G2API_GetBoneAnimIndex( &gent->ghoul2[gent->playerModel], gent->lowerLumbarBone, (cg.time?cg.time:level.time), &currentFrame, &junk, &junk, &junk, &junk2, NULL );
 
+#ifdef _DEBUG
 					assert(ret); // this would be pretty bad, the below code seems to assume the call succeeds. -gil
+#endif // _DEBUG
 
 					strength = G_SaberLockStrength( gent );
 					if ( pm->ps->torsoAnim == BOTH_CCWCIRCLELOCK ||
@@ -8991,4 +8993,4 @@ void Pmove( pmove_t *pmove )
 	{//half grav
 		pm->ps->gravity *= 2;
 	}
-}
\ No newline at end of file
+}
