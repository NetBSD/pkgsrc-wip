$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/paint/paint_property_tree_builder_test.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/paint/paint_property_tree_builder_test.cc
@@ -77,17 +77,6 @@ const ScrollPaintPropertyNode* PaintProp
   return document->GetLayoutView()->FirstFragment().PaintProperties()->Scroll();
 }
 
-const EffectPaintPropertyNode* PaintPropertyTreeBuilderTest::DocEffect(
-    const Document* document) {
-  if (!document) {
-    document = &GetDocument();
-  }
-  return document->GetLayoutView()
-      ->FirstFragment()
-      .PaintProperties()
-      ->ViewTransitionEffect();
-}
-
 const ObjectPaintProperties*
 PaintPropertyTreeBuilderTest::PaintPropertiesForElement(const char* name) {
   return GetDocument()
@@ -1058,7 +1047,8 @@ TEST_P(PaintPropertyTreeBuilderTest, Eff
       PaintPropertiesForElement("groupWithOpacity");
   EXPECT_EQ(0.6f, group_with_opacity_properties->Effect()->Opacity());
   EXPECT_EQ(svg_clip, group_with_opacity_properties->Effect()->OutputClip());
-  EXPECT_EQ(DocEffect(), group_with_opacity_properties->Effect()->Parent());
+  EXPECT_EQ(&EffectPaintPropertyNode::Root(),
+            group_with_opacity_properties->Effect()->Parent());
 
   EXPECT_EQ(nullptr, PaintPropertiesForElement("rectWithoutOpacity"));
 
@@ -4762,7 +4752,7 @@ TEST_P(PaintPropertyTreeBuilderTest, Ref
             filter_properties->PaintOffsetTranslation()->Parent());
   EXPECT_EQ(gfx::Vector2dF(8, 8),
             filter_properties->PaintOffsetTranslation()->Get2dTranslation());
-  EXPECT_EQ(filter_properties->Filter()->Parent(), DocEffect());
+  EXPECT_TRUE(filter_properties->Filter()->Parent()->IsRoot());
   EXPECT_EQ(filter_properties->PaintOffsetTranslation(),
             &filter_properties->Filter()->LocalTransformSpace());
   EXPECT_EQ(DocContentClip(), filter_properties->Filter()->OutputClip());
@@ -4775,7 +4765,7 @@ TEST_P(PaintPropertyTreeBuilderTest, Sim
   const ObjectPaintProperties* filter_properties =
       GetLayoutObjectByElementId("filter")->FirstFragment().PaintProperties();
   EXPECT_FALSE(filter_properties->PaintOffsetTranslation());
-  EXPECT_EQ(filter_properties->Filter()->Parent(), DocEffect());
+  EXPECT_TRUE(filter_properties->Filter()->Parent()->IsRoot());
   EXPECT_FALSE(filter_properties->PixelMovingFilterClipExpander());
   EXPECT_EQ(DocScrollTranslation(),
             &filter_properties->Filter()->LocalTransformSpace());
@@ -4792,7 +4782,7 @@ TEST_P(PaintPropertyTreeBuilderTest, Pix
 
   auto* filter = filter_properties->Filter();
   ASSERT_TRUE(filter);
-  EXPECT_EQ(filter->Parent(), DocEffect());
+  EXPECT_TRUE(filter->Parent()->IsRoot());
   EXPECT_TRUE(filter->HasFilterThatMovesPixels());
   EXPECT_EQ(DocScrollTranslation(), &filter->LocalTransformSpace());
   EXPECT_EQ(DocContentClip(), filter->OutputClip());
@@ -4847,7 +4837,7 @@ TEST_P(PaintPropertyTreeBuilderTest, Fil
       GetLayoutObjectByElementId("clip")->FirstFragment().PaintProperties();
   const ObjectPaintProperties* filter_properties =
       GetLayoutObjectByElementId("filter")->FirstFragment().PaintProperties();
-  EXPECT_TRUE(DocEffect());
+  EXPECT_TRUE(filter_properties->Filter()->Parent()->IsRoot());
   EXPECT_EQ(clip_properties->OverflowClip(),
             filter_properties->Filter()->OutputClip());
   EXPECT_EQ(DocScrollTranslation(),
@@ -5089,7 +5079,7 @@ TEST_P(PaintPropertyTreeBuilderTest, Mas
 
   EXPECT_EQ(properties->Effect(),
             &target->FirstFragment().LocalBorderBoxProperties().Effect());
-  EXPECT_TRUE(DocEffect());
+  EXPECT_TRUE(properties->Effect()->Parent()->IsRoot());
   EXPECT_EQ(SkBlendMode::kSrcOver, properties->Effect()->BlendMode());
   EXPECT_EQ(mask_clip->Parent(), properties->Effect()->OutputClip());
 
@@ -5118,7 +5108,7 @@ TEST_P(PaintPropertyTreeBuilderTest, Mas
 
   EXPECT_EQ(properties->Effect(),
             &target->FirstFragment().LocalBorderBoxProperties().Effect());
-  EXPECT_TRUE(DocEffect());
+  EXPECT_TRUE(properties->Effect()->Parent()->IsRoot());
   EXPECT_EQ(SkBlendMode::kSrcOver, properties->Effect()->BlendMode());
   EXPECT_EQ(mask_clip->Parent(), properties->Effect()->OutputClip());
 
@@ -5172,7 +5162,7 @@ TEST_P(PaintPropertyTreeBuilderTest, Mas
 
   EXPECT_EQ(target_properties->Effect(),
             &target->FirstFragment().LocalBorderBoxProperties().Effect());
-  EXPECT_TRUE(DocEffect());
+  EXPECT_TRUE(target_properties->Effect()->Parent()->IsRoot());
   EXPECT_EQ(SkBlendMode::kSrcOver, target_properties->Effect()->BlendMode());
   EXPECT_EQ(nullptr, target_properties->Effect()->OutputClip());
 
@@ -5215,7 +5205,7 @@ TEST_P(PaintPropertyTreeBuilderTest, Mas
 
   EXPECT_EQ(properties->Effect(),
             &target->FirstFragment().LocalBorderBoxProperties().Effect());
-  EXPECT_TRUE(DocEffect());
+  EXPECT_TRUE(properties->Effect()->Parent()->IsRoot());
   EXPECT_EQ(SkBlendMode::kSrcOver, properties->Effect()->BlendMode());
   EXPECT_EQ(mask_clip->Parent(), properties->Effect()->OutputClip());
 
@@ -5316,7 +5306,8 @@ TEST_P(PaintPropertyTreeBuilderTest, SVG
   ASSERT_TRUE(svg_root_properties->Effect());
   EXPECT_EQ(SkBlendMode::kSrcOver, svg_root_properties->Effect()->BlendMode());
 
-  EXPECT_EQ(DocEffect(), svg_root_properties->Effect()->Parent());
+  EXPECT_EQ(&EffectPaintPropertyNode::Root(),
+            svg_root_properties->Effect()->Parent());
   EXPECT_EQ(svg_root_properties->Effect(), rect_properties->Effect()->Parent());
 }
 
@@ -5338,7 +5329,8 @@ TEST_P(PaintPropertyTreeBuilderTest, SVG
   ASSERT_TRUE(svg_root_properties->Effect());
   EXPECT_EQ(SkBlendMode::kMultiply, svg_root_properties->Effect()->BlendMode());
 
-  EXPECT_EQ(DocEffect(), html_properties->Effect()->Parent());
+  EXPECT_EQ(&EffectPaintPropertyNode::Root(),
+            html_properties->Effect()->Parent());
   EXPECT_EQ(html_properties->Effect(), svg_root_properties->Effect()->Parent());
 }
 
@@ -6454,7 +6446,7 @@ TEST_P(PaintPropertyTreeBuilderTest, SVG
 
   const auto* effect = properties->Effect();
   ASSERT_NE(nullptr, effect);
-  EXPECT_EQ(DocEffect(), effect->Parent());
+  EXPECT_EQ(&EffectPaintPropertyNode::Root(), effect->Parent());
   EXPECT_EQ(transform, &effect->LocalTransformSpace());
   EXPECT_EQ(clip_path_clip, effect->OutputClip());
   EXPECT_EQ(SkBlendMode::kSrcOver, effect->BlendMode());
@@ -6492,7 +6484,7 @@ TEST_P(PaintPropertyTreeBuilderTest, SVG
   const auto* effect = properties->Effect();
   ASSERT_NE(nullptr, effect);
   EXPECT_TRUE(effect->HasDirectCompositingReasons());
-  EXPECT_EQ(DocEffect(), effect->Parent());
+  EXPECT_EQ(&EffectPaintPropertyNode::Root(), effect->Parent());
   EXPECT_EQ(transform, &effect->LocalTransformSpace());
   EXPECT_EQ(clip_path_clip, effect->OutputClip());
   EXPECT_EQ(SkBlendMode::kSrcOver, effect->BlendMode());
