$NetBSD$

The code mixes C++ and C (math.h), ensure that isfinite and
signbit resolve correctly.

--- code/fgame/actor.cpp.orig	2024-12-27 08:29:26.159996729 +0000
+++ code/fgame/actor.cpp
@@ -63,6 +63,9 @@ const char *gGermanVoices[]   = {"a", "c
 static const float DEFAULT_NEARBY_SQUAD_DIST = 1024;
 static const float MIN_BADPLACE_UPDATE_DIST  = 256;
 
+using std::isfinite;
+using std::signbit;
+
 Event EV_Actor_SetGun
 (
     "gun",
