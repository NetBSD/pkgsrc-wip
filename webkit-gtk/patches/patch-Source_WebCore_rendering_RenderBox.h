$NetBSD$

Properly calls std::isnan()

--- Source/WebCore/rendering/RenderBox.h.orig	2022-09-14 11:58:10.516863300 +0000
+++ Source/WebCore/rendering/RenderBox.h
@@ -732,7 +732,7 @@ protected:
 
     void computePreferredLogicalWidths(const Length& minWidth, const Length& maxWidth, LayoutUnit borderAndPadding);
     
-    bool isAspectRatioDegenerate(double aspectRatio) const { return !aspectRatio || isnan(aspectRatio); }
+    bool isAspectRatioDegenerate(double aspectRatio) const { return !aspectRatio || std::isnan(aspectRatio); }
     
 private:
     bool replacedMinMaxLogicalHeightComputesAsNone(SizeType) const;
