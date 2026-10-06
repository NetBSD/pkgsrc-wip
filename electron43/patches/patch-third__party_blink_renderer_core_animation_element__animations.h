$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/animation/element_animations.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/animation/element_animations.h
@@ -120,7 +120,7 @@ class CORE_EXPORT ElementAnimations fina
 
   void RecalcCompositedStatusForKeyframeChange(Element& element,
                                                AnimationEffect* effect);
-  void RecalcCompositedStatus(Element* element, const CSSProperty& property);
+  void RecalcCompositedStatus(Element* element);
 
   // TODO(crbug.com/1301961): Consider converting to an array or flat map of
   // fields for paint properties that can be composited.
