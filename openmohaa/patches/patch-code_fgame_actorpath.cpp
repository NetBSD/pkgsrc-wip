$NetBSD$

The code mixes C++ and C (math.h), ensure that isfinite resolves correctly.

--- code/fgame/actorpath.cpp.orig	2024-12-27 08:31:37.361294660 +0000
+++ code/fgame/actorpath.cpp
@@ -24,6 +24,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 #include "actor.h"
 
+using std::isfinite;
+
 ActorPath::ActorPath()
 {
     m_FallHeight       = 96;
