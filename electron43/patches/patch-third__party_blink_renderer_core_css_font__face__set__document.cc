$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/css/font_face_set_document.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/css/font_face_set_document.cc
@@ -27,6 +27,7 @@
 
 #include "base/metrics/histogram_functions.h"
 #include "third_party/blink/public/common/features.h"
+#include "third_party/blink/public/common/metrics/document_update_reason.h"
 #include "third_party/blink/renderer/bindings/core/v8/dictionary.h"
 #include "third_party/blink/renderer/core/css/css_font_face.h"
 #include "third_party/blink/renderer/core/css/css_font_selector.h"
@@ -141,21 +142,27 @@ FontFaceSetDocument::CSSConnectedFontFac
 }
 
 void FontFaceSetDocument::FireDoneEventIfPossible() {
-  if (should_fire_loading_event_) {
+  Document* d = GetDocument();
+  if (!d || !d->View()) {
     return;
   }
+
   if (!ShouldSignalReady()) {
     return;
   }
-  Document* d = GetDocument();
-  if (!d) {
+
+  // FireDoneEventIfPossible gets scheduled via PostTask at the end of a
+  // successful style+layout update. An invalidation may have occurred in
+  // the interim, so update style and layout synchronously here.
+  d->UpdateStyleAndLayout(DocumentUpdateReason::kUnknown);
+
+  // These values can change during style+layout update, so check them
+  // *after* the call to UpdateStyleAndLayout.
+  if (should_fire_loading_event_) {
     return;
   }
 
-  // If the layout was invalidated in between when we thought layout
-  // was updated and when we're ready to fire the event, just wait
-  // until after the next layout before firing events.
-  if (!d->View() || d->View()->NeedsLayout()) {
+  if (!ShouldSignalReady()) {
     return;
   }
 
