$NetBSD$

--- src/modules/simu/simuv2.1/simu.cpp.orig	2022-07-28 18:24:22.665854606 -0700
+++ src/modules/simu/simuv2.1/simu.cpp	2022-07-28 18:25:07.674759715 -0700
@@ -57,15 +57,15 @@
 
     /* sanity check */
 #ifndef WIN32
-    if (isnan(car->ctrl->accelCmd) || isinf(car->ctrl->accelCmd)) car->ctrl->accelCmd = 0;
-    if (isnan(car->ctrl->brakeCmd) || isinf(car->ctrl->brakeCmd)) car->ctrl->brakeCmd = 0;
-    if (isnan(car->ctrl->clutchCmd) || isinf(car->ctrl->clutchCmd)) car->ctrl->clutchCmd = 0;
-    if (isnan(car->ctrl->steer) || isinf(car->ctrl->steer)) car->ctrl->steer = 0;
+    if (std::isnan(car->ctrl->accelCmd) || std::isinf(car->ctrl->accelCmd)) car->ctrl->accelCmd = 0;
+    if (std::isnan(car->ctrl->brakeCmd) || std::isinf(car->ctrl->brakeCmd)) car->ctrl->brakeCmd = 0;
+    if (std::isnan(car->ctrl->clutchCmd) || std::isinf(car->ctrl->clutchCmd)) car->ctrl->clutchCmd = 0;
+    if (std::isnan(car->ctrl->steer) || std::isinf(car->ctrl->steer)) car->ctrl->steer = 0;
 #else
-    if (isnan(car->ctrl->accelCmd)) car->ctrl->accelCmd = 0;
-    if (isnan(car->ctrl->brakeCmd)) car->ctrl->brakeCmd = 0;
-    if (isnan(car->ctrl->clutchCmd)) car->ctrl->clutchCmd = 0;
-    if (isnan(car->ctrl->steer)) car->ctrl->steer = 0;
+    if (std::isnan(car->ctrl->accelCmd)) car->ctrl->accelCmd = 0;
+    if (std::isnan(car->ctrl->brakeCmd)) car->ctrl->brakeCmd = 0;
+    if (std::isnan(car->ctrl->clutchCmd)) car->ctrl->clutchCmd = 0;
+    if (std::isnan(car->ctrl->steer)) car->ctrl->steer = 0;
 #endif
 
     /* When the car is broken try to send it on the track side */
