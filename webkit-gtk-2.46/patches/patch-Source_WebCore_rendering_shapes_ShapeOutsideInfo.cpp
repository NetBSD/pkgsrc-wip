$NetBSD$

ShapeOutsideInfo.cpp:140:16: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?

--- Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp.orig	2025-08-23 13:14:21.009366295 +0000
+++ Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp
@@ -137,7 +137,7 @@ Ref<const LayoutShape> makeShapeForShape
 
     auto margin = [&] {
         auto shapeMargin = floatValueForLength(style.shapeMargin(), containingBlock.contentBoxWidth());
-        return isnan(shapeMargin) ? 0.0f : shapeMargin;
+        return std::isnan(shapeMargin) ? 0.0f : shapeMargin;
     }();
 
 
