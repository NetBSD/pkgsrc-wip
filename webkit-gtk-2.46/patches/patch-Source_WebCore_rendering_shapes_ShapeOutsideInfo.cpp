$NetBSD$

webkitgtk-2.46.3/Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp:136:16: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?

--- Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp.orig	2024-11-02 08:33:48.627831712 +0000
+++ Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp
@@ -133,7 +133,7 @@ Ref<const Shape> makeShapeForShapeOutsid
 
     auto margin = [&] {
         auto shapeMargin = floatValueForLength(style.shapeMargin(), containingBlock.contentWidth());
-        return isnan(shapeMargin) ? 0.0f : shapeMargin;
+        return std::isnan(shapeMargin) ? 0.0f : shapeMargin;
     }();
 
 
