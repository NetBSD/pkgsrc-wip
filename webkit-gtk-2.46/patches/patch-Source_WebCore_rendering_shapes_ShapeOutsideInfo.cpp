$NetBSD$

ShapeOutsideInfo.cpp:140:16: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?

--- Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp.orig	2025-08-08 09:17:55.564470500 +0000
+++ Source/WebCore/rendering/shapes/ShapeOutsideInfo.cpp
@@ -257,7 +257,7 @@ Ref<const LayoutShape> makeShapeForShape
 
     auto logicalMargin = [&] {
         auto shapeMargin = Style::evaluate(style.shapeMargin(), containingBlock.contentBoxLogicalWidth()).toFloat();
-        return isnan(shapeMargin) ? 0.0f : shapeMargin;
+        return std::isnan(shapeMargin) ? 0.0f : shapeMargin;
     }();
 
     return WTF::switchOn(shapeOutside,
