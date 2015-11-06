$NetBSD$

Text::GlyphQuads::Coords2 changed type from std::vector<osg::Vec2>
in 3.2.0 of osc to osg::ref_ptr<osg::Vec2Array> in 3.4.0

--- simgear/canvas/elements/CanvasText.cxx.orig	2015-11-05 17:00:10.000000000 +0000
+++ simgear/canvas/elements/CanvasText.cxx
@@ -165,15 +165,15 @@ namespace canvas
 
     if( global_i == _begin )
       // before first character of line
-      pos.x() = coords[_begin * 4].x();
+      pos.x() = (*coords)[_begin * 4].x();
     else if( global_i == _end )
       // After Last character of line
-      pos.x() = coords[(_end - 1) * 4 + 2].x();
+      pos.x() = (*coords)[(_end - 1) * 4 + 2].x();
     else
     {
-      float prev_l = coords[(global_i - 1) * 4].x(),
-            prev_r = coords[(global_i - 1) * 4 + 2].x(),
-            cur_l = coords[global_i * 4].x();
+      float prev_l = (*coords)[(global_i - 1) * 4].x(),
+            prev_r = (*coords)[(global_i - 1) * 4 + 2].x(),
+            cur_l = (*coords)[global_i * 4].x();
 
       if( prev_l == prev_r )
         // If previous character width is zero set to begin of next character
@@ -205,7 +205,7 @@ namespace canvas
     {
       // Get threshold for mouse x position for setting cursor before or after
       // current character
-      float threshold = coords[i * 4].x()
+      float threshold = (*coords)[i * 4].x()
                       + HIT_FRACTION * glyphs[i]->getHorizontalAdvance()
                                      * character_width;
 
@@ -652,8 +652,8 @@ namespace canvas
         // osg::Vec2 lowRight = local+osg::Vec2(width+fHorizQuadMargin, ...);
         // osg::Vec2 upRight = local+osg::Vec2(width+fHorizQuadMargin, ...);
 
-        float left = coords[i * 4].x(),
-              right = coords[i * 4 + 2].x(),
+        float left = (*coords)[i * 4].x(),
+              right = (*coords)[i * 4 + 2].x(),
               width = glyphs[i]->getWidth() * wr;
 
         // (local + width + fHoriz) - (local - fHoriz) = width + 2*fHoriz | -width
