$NetBSD$

Use std::isinf() from <cmath>.

--- src/playsim/p_mobj.cpp.orig	2026-08-30 22:39:17.564880600 +0000
+++ src/playsim/p_mobj.cpp
@@ -121,7 +121,7 @@ CUSTOM_CVAR (Float, sv_gravity, 800.f, CVAR_SERVERINFO
 CUSTOM_CVAR (Float, sv_gravity, 800.f, CVAR_SERVERINFO|CVAR_NOSAVE|CVAR_NOINITCALL)
 {
 	// test NAN and INF
-	if (((double)self != (double)self) || isinf((double)self))
+	if (((double)self != (double)self) || std::isinf((double)self))
 		sv_gravity = 800.f;
 
 	for (auto Level : AllLevels())
