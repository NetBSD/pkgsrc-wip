$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/renderer/pepper/pepper_helper.h.orig	2024-10-18 12:34:04.087868700 +0000
+++ chrome/renderer/pepper/pepper_helper.h
@@ -5,11 +5,13 @@
 #ifndef CHROME_RENDERER_PEPPER_PEPPER_HELPER_H_
 #define CHROME_RENDERER_PEPPER_PEPPER_HELPER_H_
 
+#include "base/component_export.h"
 #include "content/public/renderer/render_frame_observer.h"
 
 // This class listens for Pepper creation events from the RenderFrame and
 // attaches the parts required for Chrome-specific plugin support.
-class PepperHelper : public content::RenderFrameObserver {
+class COMPONENT_EXPORT(PEPPER_FLASH) PepperHelper
+    : public content::RenderFrameObserver {
  public:
   explicit PepperHelper(content::RenderFrame* render_frame);
 
