$NetBSD$

--- src/libs/robottools/rthumandriver.cpp.orig	2022-07-28 18:21:47.908297504 -0700
+++ src/libs/robottools/rthumandriver.cpp	2022-07-28 18:22:01.420987373 -0700
@@ -1483,7 +1483,7 @@
         }
         ax0 = ax0 * cmd[CMD_THROTTLE].pow;
         car->_accelCmd =  pow(fabs(ax0), 1.0f / cmd[CMD_THROTTLE].sens) / (1.0 + cmd[CMD_THROTTLE].spdSens * car->_speed_x / 1000.0);
-        if (isnan (car->_accelCmd)) {
+        if (std::isnan (car->_accelCmd)) {
             car->_accelCmd = 0;
         }
         /* printf("  axO:%f  accelCmd:%f\n", ax0, car->_accelCmd); */
