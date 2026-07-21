$NetBSD$

Use utf8cpp from pkgsrc

--- kernel/src/model/missionbriefing.cpp.orig	2026-07-21 03:27:12.600916571 +0000
+++ kernel/src/model/missionbriefing.cpp
@@ -23,7 +23,7 @@
 
 #include <stdlib.h>
 #include <string>
-#include "utf8.h"
+#include <utf8cpp/utf8.h>
 
 #include "fs-engine/gfx/cp437.h"
 #include "fs-kernel/model/map.h"
@@ -195,4 +195,4 @@ uint8 MissionBriefing::getMinimapOverlay
     return minimap_overlay_[x + y * p_minimap_->max_x()];
 }
 
-}
\ No newline at end of file
+}
