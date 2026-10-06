$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/compositor/compositor.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/compositor/compositor.h
@@ -89,6 +89,7 @@ namespace mojom {
 class DisplayPrivate;
 class ExternalBeginFrameController;
 }  // namespace mojom
+class HostDisplayClient;
 class HostFrameSinkManager;
 class LocalSurfaceId;
 class RasterContextProvider;
@@ -140,6 +141,16 @@ class COMPOSITOR_EXPORT ContextFactory {
   virtual viz::HostFrameSinkManager* GetHostFrameSinkManager() = 0;
 };
 
+class COMPOSITOR_EXPORT CompositorDelegate {
+ public:
+  virtual bool IsOffscreen() const = 0;
+  virtual std::unique_ptr<viz::HostDisplayClient> CreateHostDisplayClient(
+      ui::Compositor* compositor) = 0;
+
+ protected:
+  virtual ~CompositorDelegate() {}
+};
+
 // Compositor object to take care of GPU painting.
 // A Browser compositor object is responsible for generating the final
 // displayable form of pixels comprising a single widget's contents. It draws an
@@ -183,6 +194,9 @@ class COMPOSITOR_EXPORT Compositor : pub
   // Schedules a redraw of the layer tree associated with this compositor.
   void ScheduleDraw();
 
+  CompositorDelegate* delegate() const { return delegate_; }
+  void SetDelegate(CompositorDelegate* delegate) { delegate_ = delegate; }
+
   // Sets the root of the layer tree drawn by this Compositor. The root layer
   // must have no parent. The compositor's root layer is reset if the root layer
   // is destroyed. NULL can be passed to reset the root layer, in which case the
@@ -456,7 +470,7 @@ class COMPOSITOR_EXPORT Compositor : pub
   // base::PowerSuspendObserver:
   void OnResume() override;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
@@ -495,6 +509,10 @@ class COMPOSITOR_EXPORT Compositor : pub
 
   const cc::LayerTreeSettings& GetLayerTreeSettings() const;
 
+  // Sets |background_throttling_| responsible for suspending drawing
+  // and switching frames.
+  void SetBackgroundThrottling(bool background_throttling_enabled);
+
   size_t saved_events_metrics_count_for_testing() const {
     return host_->saved_events_metrics_count_for_testing();
   }
@@ -562,6 +580,8 @@ class COMPOSITOR_EXPORT Compositor : pub
       simple_begin_frame_observers_;
   std::unique_ptr<ui::HostBeginFrameObserver> host_begin_frame_observer_;
 
+  raw_ptr<CompositorDelegate> delegate_ = nullptr;
+
   // The root of the Layer tree drawn by this compositor.
   raw_ptr<Layer> root_layer_ = nullptr;
 
@@ -641,6 +661,12 @@ class COMPOSITOR_EXPORT Compositor : pub
   // See go/report-ux-metrics-at-painting for details.
   bool animation_started_ = false;
 
+  // Background throttling is a default Chromium behaviour. It occurs
+  // when the |display_private_| is not visible by prevent drawing and swapping
+  // frames. When it is disabled we are keeping |display_private_| always
+  // visible in order to keep generating frames.
+  bool background_throttling_ = true;
+
   TrackerId next_throughput_tracker_id_ = 1u;
   struct TrackerState {
     TrackerState();
