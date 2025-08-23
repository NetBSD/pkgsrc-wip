$NetBSD$

RenderBox.h:701:85: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?

--- Source/WebCore/rendering/RenderBox.h.orig	2025-08-23 12:57:50.364064667 +0000
+++ Source/WebCore/rendering/RenderBox.h
@@ -698,7 +698,7 @@ protected:
 
     void computePreferredLogicalWidths(const Length& minLogicalWidth, const Length& maxLogicalWidth, LayoutUnit borderAndPaddingLogicalWidth);
     
-    bool isAspectRatioDegenerate(double aspectRatio) const { return !aspectRatio || isnan(aspectRatio); }
+    bool isAspectRatioDegenerate(double aspectRatio) const { return !aspectRatio || std::isnan(aspectRatio); }
 
     bool overflowChangesMayAffectLayout() const final;
 
