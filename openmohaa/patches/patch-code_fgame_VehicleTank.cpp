$NetBSD$

The code mixes C++ and C (math.h), ensure that isfinite resolves correctly.

--- code/fgame/VehicleTank.cpp.orig	2024-12-27 08:28:41.728714713 +0000
+++ code/fgame/VehicleTank.cpp
@@ -25,6 +25,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #include "player.h"
 #include "g_phys.h"
 
+using std::isfinite;
+
 CLASS_DECLARATION(DrivableVehicle, VehicleTank, "VehicleTank") {
     {&EV_Damage, &VehicleTank::EventDamage},
     {NULL,       NULL                     }
