$NetBSD$

webkitgtk-2.46.3/Source/WebCore/rendering/RenderBox.h:710:85: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?

--- Source/WebCore/rendering/RenderBox.h.orig	2024-11-02 08:18:45.421859379 +0000
+++ Source/WebCore/rendering/RenderBox.h
@@ -707,7 +707,7 @@ protected:
 
     void computePreferredLogicalWidths(const Length& minWidth, const Length& maxWidth, LayoutUnit borderAndPadding);
     
-    bool isAspectRatioDegenerate(double aspectRatio) const { return !aspectRatio || isnan(aspectRatio); }
+    bool isAspectRatioDegenerate(double aspectRatio) const { return !aspectRatio || std::isnan(aspectRatio); }
     
 private:
     bool replacedMinMaxLogicalHeightComputesAsNone(SizeType) const;
