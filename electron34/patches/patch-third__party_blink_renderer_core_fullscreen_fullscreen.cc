$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/fullscreen/fullscreen.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/fullscreen/fullscreen.cc
@@ -110,7 +110,7 @@ void FullscreenElementChanged(Document& 
     // is the iframe element for the out-of-process frame that contains the
     // fullscreen element. Hence, it must match :-webkit-full-screen-ancestor.
     if (new_request_type & FullscreenRequestType::kForCrossProcessDescendant) {
-      DCHECK(IsA<HTMLIFrameElement>(new_element));
+      // DCHECK(IsA<HTMLIFrameElement>(new_element));
       new_element->SetContainsFullScreenElement(true);
     }
     new_element->SetContainsFullScreenElementOnAncestorsCrossingFrameBoundaries(
