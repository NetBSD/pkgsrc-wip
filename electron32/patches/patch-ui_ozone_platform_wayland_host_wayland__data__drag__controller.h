$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/wayland/host/wayland_data_drag_controller.h.orig	2024-10-18 12:35:12.760256000 +0000
+++ ui/ozone/platform/wayland/host/wayland_data_drag_controller.h
@@ -216,7 +216,6 @@ class WaylandDataDragController : public
   std::optional<wl::Serial> GetAndValidateSerialForDrag(
       mojom::DragEventSource source);
 
-  void SetOfferedExchangeDataProvider(const OSExchangeData& data);
   const WaylandExchangeDataProvider* GetOfferedExchangeDataProvider() const;
 
   // Checks whether |data| holds information about a window dragging session.
