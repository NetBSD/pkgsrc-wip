$NetBSD$

Use <cmath> for std::isnan(), std::isfinite()

--- src/common/engine/m_joy.cpp.orig	2026-08-31 03:19:00.559334344 +0000
+++ src/common/engine/m_joy.cpp
@@ -24,7 +24,7 @@
 
 // HEADER FILES ------------------------------------------------------------
 
-#include <math.h>
+#include <cmath>
 
 #include "basics.h"
 #include "c_cvars.h"
@@ -647,7 +647,7 @@ bool Joy_ManageThumbstick(
 
 	const double magnitude = sqrt((x_abs * x_abs) + (y_abs * y_abs));
 
-	if (isnan(magnitude) || magnitude <= 0) {
+	if (std::isnan(magnitude) || magnitude <= 0) {
 		*axis_x = *axis_y = 0;
 		if (buttons) *buttons = 0;
 		return false;
@@ -675,7 +675,7 @@ bool Joy_ManageThumbstick(
 	{
 		// Make the dead zone the new 0.
 		double scaled = (magnitude - deadzone) / (1.0 - deadzone);
-		if (!isfinite(scaled)) scaled = 1.0;
+		if (!std::isfinite(scaled)) scaled = 1.0;
 
 		const CubicBezier curve = {{
 			(float)std::lerp((double) curve_y.x1, (double) curve_x.x1, x_bias),
