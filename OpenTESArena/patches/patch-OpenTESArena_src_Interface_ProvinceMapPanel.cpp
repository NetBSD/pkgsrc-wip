$NetBSD$

Work around std::sqrt not defined.

--- OpenTESArena/src/Interface/ProvinceMapPanel.cpp.orig	2018-09-23 18:19:37.000000000 +0000
+++ OpenTESArena/src/Interface/ProvinceMapPanel.cpp
@@ -353,8 +353,8 @@ int ProvinceMapPanel::getClosestLocation
 	{
 		const Int2 diff = point - originalPosition;
 		const Int2 closestDiff = closestPosition - originalPosition;
-		const double distance = std::sqrt((diff.x * diff.x) + (diff.y * diff.y));
-		const double closestDistance = std::sqrt(
+		const double distance = sqrt((diff.x * diff.x) + (diff.y * diff.y));
+		const double closestDistance = sqrt(
 			(closestDiff.x * closestDiff.x) + (closestDiff.y * closestDiff.y));
 		return distance < closestDistance;
 	};
