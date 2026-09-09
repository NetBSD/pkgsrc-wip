$NetBSD$

The signature for fabs is "double fabs(double)" or "float fabs(float)"
in <cmath>. To workaround a compile time error (loss of precision),
make sure that the "double" version is used.

--- src/playsim/p_effect.cpp.orig	2026-08-30 22:33:08.633579144 +0000
+++ src/playsim/p_effect.cpp
@@ -296,9 +296,9 @@ void P_ThinkParticles (FLevelLocals *Level)
 
 		particle->alpha -= particle->fadestep;
 		if (	(!!(particle->flags & SPF_FADE_IN_OUT) && particle->alpha >= 1.0)
-			 || (!!(particle->flags & SPF_FADE_IN_HOLD_OUT) && (particle->ttl * fabs(particle->fadeoutstep)) <= std::min(1.0f, fabs(particle->alpha)))
+			 || (!!(particle->flags & SPF_FADE_IN_HOLD_OUT) && (particle->ttl * fabs(particle->fadeoutstep)) <= std::min(1.0, (double)fabs(particle->alpha)))
 		) { // [Jay] if SPF_FADE_IN_HOLD_OUT, hold until the fade out would line up with ttl
-			particle->alpha = std::min(1.0f, fabs(particle->alpha));
+			particle->alpha = std::min(1.0, (double)fabs(particle->alpha));
 			particle->fadestep = particle->fadeoutstep;
 			particle->flags &= ~(SPF_FADE_IN_OUT|SPF_FADE_IN_HOLD_OUT);
 		}
