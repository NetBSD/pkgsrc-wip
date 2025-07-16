$NetBSD$

The code mixes C++ and C (math.h), ensure that isnan resolves correctly.

--- code/fgame/scriptthread.cpp.orig	2025-07-10 21:15:54.000000000 +0000
+++ code/fgame/scriptthread.cpp
@@ -55,6 +55,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 #define scriptfiles sv_scriptfiles
 
+using std::isnan;
+
 Event EV_ScriptThread_GetCvar
 (
     "getcvar",
