$NetBSD$

Use the correct modf function for float variables.

--- TheForceEngine/TFE_DarkForces/vueLogic.cpp.orig	2023-08-02 00:48:43.000000000 +0000
+++ TheForceEngine/TFE_DarkForces/vueLogic.cpp
@@ -577,7 +577,7 @@ namespace TFE_DarkForces
 						if (smoothVUEs)
 						{
 							f32 frameIndexF = f32(dt) / f32(local(vue)->frameDelay);
-							t = std::modf(frameIndexF, &frameIndexF); //normalized progress from prev to cur frame
+							t = modff(frameIndexF, &frameIndexF); //normalized progress from prev to cur frame
 							frameIndex = s32(frameIndexF);
 						}
 						else
@@ -646,4 +646,4 @@ namespace TFE_DarkForces
 		task_free(logic->task);
 	}
 
-}  // TFE_DarkForces
\ No newline at end of file
+}  // TFE_DarkForces
