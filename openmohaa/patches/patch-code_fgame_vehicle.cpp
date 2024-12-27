$NetBSD$

The code mixes C++ and C (math.h), ensure that isfinite resolves correctly.

--- code/fgame/vehicle.cpp.orig	2024-12-27 08:41:15.476957628 +0000
+++ code/fgame/vehicle.cpp
@@ -36,6 +36,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #include "scriptexception.h"
 #include "debuglines.h"
 
+using std::isfinite;
+
 Event EV_Vehicle_Start
 (
     "start",
