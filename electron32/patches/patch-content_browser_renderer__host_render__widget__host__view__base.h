$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_widget_host_view_base.h.orig	2024-10-18 12:34:13.626790000 +0000
+++ content/browser/renderer_host/render_widget_host_view_base.h
@@ -29,8 +29,11 @@
 #include "components/viz/common/surfaces/scoped_surface_id_allocator.h"
 #include "components/viz/common/surfaces/surface_id.h"
 #include "content/browser/renderer_host/display_feature.h"
+#include "content/browser/renderer_host/visible_time_request_trigger.h"
+#include "content/browser/web_contents/web_contents_view.h"
 #include "content/common/content_export.h"
 #include "content/public/browser/render_frame_metadata_provider.h"
+#include "content/public/browser/render_widget_host.h"
 #include "content/public/browser/render_widget_host_view.h"
 #include "content/public/common/page_visibility_state.h"
 #include "content/public/common/widget_type.h"
@@ -76,9 +79,11 @@ namespace content {
 class DevicePosturePlatformProvider;
 class MouseWheelPhaseHandler;
 class RenderWidgetHostImpl;
+class RenderWidgetHostViewGuest;
 class ScopedViewTransitionResources;
 class TextInputManager;
 class TouchSelectionControllerClientManager;
+class WebContentsView;
 class WebContentsAccessibility;
 class DelegatedFrameHost;
 class SyntheticGestureTarget;
@@ -155,6 +160,10 @@ class CONTENT_EXPORT RenderWidgetHostVie
   void DidOverscroll(const ui::DidOverscrollParams& params) override {}
   void DidStopFlinging() override {}
   RenderWidgetHostViewBase* GetRootView() override;
+  virtual RenderWidgetHostViewBase* CreateViewForWidget(
+      RenderWidgetHost* render_widget_host,
+      RenderWidgetHost* embedder_render_widget_host,
+      WebContentsView* web_contents_view);
   viz::FrameSinkId GetRootFrameSinkId() override;
   void NotifyHitTestRegionUpdated(
       const viz::AggregatedHitTestRegion& region) override {}
@@ -235,6 +244,9 @@ class CONTENT_EXPORT RenderWidgetHostVie
       const gfx::Rect& keyboard_rect) override {}
   bool IsHTMLFormPopup() const override;
 
+  virtual void InitAsGuest(RenderWidgetHostView* parent_host_view,
+                           RenderWidgetHostViewGuest* guest_view) {}
+
   // This only needs to be overridden by RenderWidgetHostViewBase subclasses
   // that handle content embedded within other RenderWidgetHostViews.
   gfx::PointF TransformPointToRootCoordSpaceF(
