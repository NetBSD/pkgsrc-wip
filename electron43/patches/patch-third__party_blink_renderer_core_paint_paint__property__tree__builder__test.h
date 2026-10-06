$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/paint/paint_property_tree_builder_test.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/paint/paint_property_tree_builder_test.h
@@ -34,7 +34,6 @@ class PaintPropertyTreeBuilderTest : pub
       const Document* = nullptr);
   const ClipPaintPropertyNode* DocContentClip(const Document* = nullptr);
   const ScrollPaintPropertyNode* DocScroll(const Document* = nullptr);
-  const EffectPaintPropertyNode* DocEffect(const Document* = nullptr);
 
   // Return the local border box's paint offset. For more details, see
   // ObjectPaintProperties::localBorderBoxProperties().
