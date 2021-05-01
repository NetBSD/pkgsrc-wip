$NetBSD$

Work around std::sqrt not defined.

--- OpenTESArena/src/Interface/ProvinceMapPanel.cpp.orig	2020-10-11 00:01:50.000000000 +0000
+++ OpenTESArena/src/Interface/ProvinceMapPanel.cpp
@@ -322,8 +322,8 @@ int ProvinceMapPanel::getClosestLocation
 		const Int2 diff = point - originalPosition;
 		const Int2 closestDiff = closestPosition - originalPosition;
 		// @todo: change to distance squared
-		const double distance = std::sqrt((diff.x * diff.x) + (diff.y * diff.y));
-		const double closestDistance = std::sqrt(
+		const double distance = sqrt((diff.x * diff.x) + (diff.y * diff.y));
+		const double closestDistance = sqrt(
 			(closestDiff.x * closestDiff.x) + (closestDiff.y * closestDiff.y));
 		return distance < closestDistance;
 	};
