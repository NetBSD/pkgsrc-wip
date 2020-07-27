$NetBSD$

--- ui/native_theme/native_theme_base.cc.orig	2020-07-15 18:56:49.000000000 +0000
+++ ui/native_theme/native_theme_base.cc
@@ -255,7 +255,7 @@ void NativeThemeBase::Paint(cc::PaintCan
     case kCheckbox:
       PaintCheckbox(canvas, state, rect, extra.button, color_scheme);
       break;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     case kFrameTopArea:
       PaintFrameTopArea(canvas, state, rect, extra.frame_top_area,
                         color_scheme);
@@ -1483,7 +1483,7 @@ SkColor NativeThemeBase::OutlineColor(Sk
   SkScalar min_diff =
       base::ClampToRange((hsv1[1] + hsv2[1]) * 1.2f, 0.28f, 0.5f);
   SkScalar diff =
-      base::ClampToRange(fabs(hsv1[2] - hsv2[2]) / 2, min_diff, 0.5f);
+      base::ClampToRange(fabsf(hsv1[2] - hsv2[2]) / 2, min_diff, 0.5f);
 
   if (hsv1[2] + hsv2[2] > 1.0)
     diff = -diff;
