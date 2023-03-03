$NetBSD$

--- src/modules/simu/simuv4/simu.cpp.orig	2022-07-28 18:26:21.252125361 -0700
+++ src/modules/simu/simuv4/simu.cpp	2022-07-28 18:26:53.638049451 -0700
@@ -68,27 +68,27 @@
 
     /* sanity check */
 #ifndef WIN32
-    if (isnan(car->ctrl->accelCmd) || isinf(car->ctrl->accelCmd)) car->ctrl->accelCmd = 0;
-    if (isnan(car->ctrl->brakeCmd) || isinf(car->ctrl->brakeCmd)) car->ctrl->brakeCmd = 0;
-    if (isnan(car->ctrl->clutchCmd) || isinf(car->ctrl->clutchCmd)) car->ctrl->clutchCmd = 0;
-    if (isnan(car->ctrl->steer) || isinf(car->ctrl->steer)) car->ctrl->steer = 0;
-    if (isnan(car->ctrl->wingFrontCmd) || isinf(car->ctrl->wingFrontCmd)) car->ctrl->wingFrontCmd = 0;
-    if (isnan(car->ctrl->wingRearCmd) || isinf(car->ctrl->wingRearCmd)) car->ctrl->wingRearCmd = 0;
-    if (isnan(car->ctrl->brakeFrontLeftCmd) || isinf(car->ctrl->brakeFrontLeftCmd)) car->ctrl->brakeFrontLeftCmd = 0;
-    if (isnan(car->ctrl->brakeFrontRightCmd) || isinf(car->ctrl->brakeFrontRightCmd)) car->ctrl->brakeFrontRightCmd = 0;
-    if (isnan(car->ctrl->brakeRearLeftCmd) || isinf(car->ctrl->brakeRearLeftCmd)) car->ctrl->brakeRearLeftCmd = 0;
-    if (isnan(car->ctrl->brakeRearRightCmd) || isinf(car->ctrl->brakeRearRightCmd)) car->ctrl->brakeRearRightCmd = 0;
+    if (std::isnan(car->ctrl->accelCmd) || std::isinf(car->ctrl->accelCmd)) car->ctrl->accelCmd = 0;
+    if (std::isnan(car->ctrl->brakeCmd) || std::isinf(car->ctrl->brakeCmd)) car->ctrl->brakeCmd = 0;
+    if (std::isnan(car->ctrl->clutchCmd) || std::isinf(car->ctrl->clutchCmd)) car->ctrl->clutchCmd = 0;
+    if (std::isnan(car->ctrl->steer) || std::isinf(car->ctrl->steer)) car->ctrl->steer = 0;
+    if (std::isnan(car->ctrl->wingFrontCmd) || std::isinf(car->ctrl->wingFrontCmd)) car->ctrl->wingFrontCmd = 0;
+    if (std::isnan(car->ctrl->wingRearCmd) || std::isinf(car->ctrl->wingRearCmd)) car->ctrl->wingRearCmd = 0;
+    if (std::isnan(car->ctrl->brakeFrontLeftCmd) || std::isinf(car->ctrl->brakeFrontLeftCmd)) car->ctrl->brakeFrontLeftCmd = 0;
+    if (std::isnan(car->ctrl->brakeFrontRightCmd) || std::isinf(car->ctrl->brakeFrontRightCmd)) car->ctrl->brakeFrontRightCmd = 0;
+    if (std::isnan(car->ctrl->brakeRearLeftCmd) || std::isinf(car->ctrl->brakeRearLeftCmd)) car->ctrl->brakeRearLeftCmd = 0;
+    if (std::isnan(car->ctrl->brakeRearRightCmd) || std::isinf(car->ctrl->brakeRearRightCmd)) car->ctrl->brakeRearRightCmd = 0;
 #else
-    if (isnan(car->ctrl->accelCmd)) car->ctrl->accelCmd = 0;
-    if (isnan(car->ctrl->brakeCmd)) car->ctrl->brakeCmd = 0;
-    if (isnan(car->ctrl->clutchCmd)) car->ctrl->clutchCmd = 0;
-    if (isnan(car->ctrl->steer)) car->ctrl->steer = 0;
-    if (isnan(car->ctrl->wingFrontCmd)) car->ctrl->wingFrontCmd = 0;
-    if (isnan(car->ctrl->wingRearCmd)) car->ctrl->wingRearCmd = 0;
-    if (isnan(car->ctrl->brakeFrontLeftCmd)) car->ctrl->brakeFrontLeftCmd = 0;
-    if (isnan(car->ctrl->brakeFrontRightCmd)) car->ctrl->brakeFrontRightCmd = 0;
-    if (isnan(car->ctrl->brakeRearLeftCmd)) car->ctrl->brakeRearLeftCmd = 0;
-    if (isnan(car->ctrl->brakeRearRightCmd)) car->ctrl->brakeRearRightCmd = 0;
+    if (std::isnan(car->ctrl->accelCmd)) car->ctrl->accelCmd = 0;
+    if (std::isnan(car->ctrl->brakeCmd)) car->ctrl->brakeCmd = 0;
+    if (std::isnan(car->ctrl->clutchCmd)) car->ctrl->clutchCmd = 0;
+    if (std::isnan(car->ctrl->steer)) car->ctrl->steer = 0;
+    if (std::isnan(car->ctrl->wingFrontCmd)) car->ctrl->wingFrontCmd = 0;
+    if (std::isnan(car->ctrl->wingRearCmd)) car->ctrl->wingRearCmd = 0;
+    if (std::isnan(car->ctrl->brakeFrontLeftCmd)) car->ctrl->brakeFrontLeftCmd = 0;
+    if (std::isnan(car->ctrl->brakeFrontRightCmd)) car->ctrl->brakeFrontRightCmd = 0;
+    if (std::isnan(car->ctrl->brakeRearLeftCmd)) car->ctrl->brakeRearLeftCmd = 0;
+    if (std::isnan(car->ctrl->brakeRearRightCmd)) car->ctrl->brakeRearRightCmd = 0;
 #endif
 
     /* When the car is broken try to send it on the track side */
